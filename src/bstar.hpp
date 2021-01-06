#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <list>
#include <utility>
#include <limits>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>



#define BSFP_FROZEN_TEMPERATURE 0.1
#define BSFP_MAX_ITERATIONS_PER_TEMPERATURE 1000
#define BSFP_RANDOM_MOVES 60
#define BSFP_P 0.99
#define BSFP_T0 -1


namespace bstar{


struct BNode {
  int id;
  size_t width;
  size_t height;
  size_t llx = 0;
  size_t lly = 0;
  BNode* parent{ nullptr };
  BNode* left{ nullptr };
  BNode* right{ nullptr };  
};



class BStar {
  friend class BStarTester;

  public:
    BStar();

    void optimize();
    void open(const std::string input_file);
    void dump(std::ostream& os) const;
    void dump_json(std::string output_file) const;

  private:
    std::string _input_file;
    
    std::vector<BNode> _modules;
    
    // _contour stores modules which define the contour
    std::vector<BNode*> _contour;

    BNode* _root;
    
    size_t _urx = 0;
    size_t _ury = 0;

    //std::mt19937 _gen(_rd());  
    //std::uniform_real_distribution<> _dis(0, 1);

    void _generate_initial_tree();
    
    size_t _pack(std::vector<BNode>& modules);

    void _pack_helper(BNode* node);
    
    void _update_contour(BNode* node, const bool is_left);
    
    size_t _calculate_coordinate_y(const BNode* node, const bool is_left) const;

    void _rotate_module(BNode* node);
    
    void _swap_two_nodes(BNode* node1_ptr, BNode* node2_ptr);
    
    void _delete_and_insert(BNode* target, std::vector<BNode>& modules);
    
    void _delete_node(BNode* node_ptr);
    
    void _insert_node(BNode* target, std::vector<BNode>& modules);

    void _simulated_annealing(const double initial_temperature);

    void _generate_neighbor(std::vector<BNode>& modules);

    void _dump(const std::vector<BNode> modules) const;

    double _calculate_initial_temperature();
};


// BStar constructor
BStar::BStar() {

  std::cout << "bstar constructor\n";
  std::srand(std::time(0)); 
  //std::srand(std::time(nullptr));

}


// read in the module configurations
void BStar::open(const std::string input_file) {

  _input_file = input_file;

  std::ifstream infile(input_file);
  std::cout << "bstar open\n";
   
  if (!infile) {
    std::cerr << "File could not be opened!!\n";
    std::exit(EXIT_FAILURE);
  }

  size_t num_modules, width, height, id;
  infile >> num_modules;

  while (infile >> id >> width >> height) {
    BNode node;
    node.id = id;
    node.width = width;
    node.height = height; 

    _modules.push_back(node);
  }

  std::cout << "successfully open circuit\n";

}


// dump floorplan to console
void BStar::dump(std::ostream& os) const {

  for (size_t i = 0; i < _modules.size(); ++i) {
    os << _modules[i].id << ' '
       << _modules[i].llx << ' '
       << _modules[i].lly << ' '
       << _modules[i].width << ' '
       << _modules[i].height << ' ';
    
    if (_modules[i].parent)
      os << " ,parent = " << _modules[i].parent->id << ' ';

    if (_modules[i].left)
      os << " ,left = " << _modules[i].left->id << ' ';

    if (_modules[i].right)
      os << " ,right = " << _modules[i].right->id << ' ';
    
    os << '\n';
  }

}


// dump floorplan to a file with a json extesion
// not yet finished
void BStar::dump_json(std::string output_file) const {
  
  if(output_file.rfind(".json") == std::string::npos)
    output_file.append(".json");
  
  std::ofstream outfile(output_file, std::ios::out);
 
  if(!outfile) {
    std::cerr << "File could not be opened for writing\n";
    std::exit(EXIT_FAILURE); 
  }

  // generate json output 
  outfile << "{\"circuit\":\""    << _input_file << "\""
          << ",\"block_number\":" << _modules.size()
          << ",\"llx\":0"
          << ",\"lly\":0"
          << ",\"urx\":"  << _urx
          << ",\"ury\":"  << _ury
          << ",\"area\":" << (_urx * _ury)
          << ",\"coordinates\":"
          << "[";

  for(size_t i = 0; i < _modules.size(); ++i) {
    outfile << "{\"idx\":"    << _modules[i].id
            << ",\"llx\":"    << _modules[i].llx
            << ",\"lly\":"    << _modules[i].lly
            << ",\"width\":"  << _modules[i].width
            << ",\"height\":" << _modules[i].height;
    if(i == _modules.size()-1)
      outfile << "}";
    else
      outfile << "},";
  }

  outfile << "]}"; 

}


// generate an initial ordered binary tree
void BStar::_generate_initial_tree() {
  
  for (size_t i = 0; i < _modules.size(); ++i) {
    if (i*2+1 < _modules.size()) {
      _modules[i].left = &(_modules[i*2+1]);
      _modules[i*2+1].parent = &(_modules[i]);
    }

    if (i*2+2 < _modules.size()) {
      _modules[i].right = &(_modules[i*2+2]);
      _modules[i*2+2].parent = &(_modules[i]);
    }     
  }
  /*
  std::cout << "initial tree\n";
  for (auto m : _modules) {
    std::cout << m.id << " has ";
    if (m.parent)
      std::cout << "parent = " << m.parent;
    if (m.left)
      std::cout << ", left = " << m.left;
    if (m.right)
      std::cout << ", right = " << m.right;
    std::cout << '\n';
  }
  */
  _root = &(_modules[0]);  

}



// update contour
void BStar::_update_contour(BNode* node, const bool is_left) {

  //std::cout << "in update contour\n";
  //std::cout << "node->id = " << node->id << '\n';
  if (_contour.empty()) {
    _contour.push_back(node);
    return;
  }

  if (node->parent) { 
    auto index = std::find(_contour.begin(), 
                           _contour.end(), 
                           node->parent);
    auto l_idx = index;
    auto r_idx = index;
    
    
    while (index != _contour.end()) {
      if ((node->llx + node->width) >= 
          ((*index)->llx + (*index)->width)) {
        ++index;        
      }
      else 
        break;
    }

    r_idx = index; 
    
    if (is_left) {
      _contour.erase(l_idx+1, r_idx);
      _contour.insert(l_idx+1, node);
    }
    else {
      _contour.erase(l_idx, r_idx);
      _contour.insert(l_idx, node);
    }

    //for (auto c : _contour)
    //  std::cout << c->id << ' ';
    //std::cout << '\n';
    /* 
    std::cout << "before insert\n";
    std::cout << *l_idx << '\n';
    std::cout << *(l_idx+1) << '\n';
     
    l_idx = _contour.insert(l_idx+1, node);
    std::cout << *l_idx << '\n';
    std::cout << "successfully insert\n";
    std::cout << _contour.size() << '\n';
    for (auto c : _contour) 
      std::cout << c->id << ' ';
    std::cout << '\n';
    std::cout << "before erase\n";
    std::cout << *(l_idx+1) << '\n';
    std::cout << *r_idx << '\n'; 
    if (l_idx+1 == _contour.end())
      return; 
    _contour.erase(l_idx+1, r_idx);
    std::cout << "successfully erase\n";
    for (auto c : _contour) 
      std::cout << c->id << ' ';
    std::cout << '\n';
    */
  } 
    
  else {
    _contour.push_back(node);
    return; 
  }

}


// calculate the low left coordinate of the node
size_t BStar::_calculate_coordinate_y(
  const BNode* node, const bool is_left) const {
  
  size_t coordinate = 0;
  //std::cout << "node->parent : " << node->parent->id << '\n';
  if (node->parent) {
    auto index = std::find(_contour.begin(), 
                           _contour.end(), 
                           node->parent);
    
    if (is_left) 
      coordinate = node->parent->lly;
    

    else {
      while (index != _contour.end()) {
        //std::cout << "(*index)->id = " << (*index)->id << '\n';
        //std::cout << "(*index)->lly = " << (*index)->lly << '\n';
        //std::cout << "(*index)->height = " << (*index)->height << '\n';
        if (((*index)->lly) + ((*index)->height) > coordinate)
          coordinate = ((*index)->lly) + ((*index)->height);  
        ++index;
      }
    }

  }

  return coordinate;

}



// pack the modules
size_t BStar::_pack(
  std::vector<BNode>& modules) {

  _contour.clear();
  _urx = 0;
  _ury = 0;

  for (auto m : modules) {
    if (m.parent == nullptr) {
      _root = &(m);
    }

    m.llx = 0;
    m.lly = 0;
  }

  _pack_helper(_root);
  
  for (auto m : modules) {
    _urx = (_urx > m.llx+m.width) ? _urx : m.llx+m.width;
    _ury = (_ury > m.lly+m.height) ? _ury : m.lly+m.height;
  }

  return _urx * _ury;

}



// auxiliary function for _pack
void BStar::_pack_helper(BNode* node) {
  
  //std::cout << "node->id = " << node->id << '\n';
  if (node == _root) 
    _update_contour(node, true);
  
    
  if (node->left) {
    node->left->llx = node->llx + node->width;
    node->left->lly = _calculate_coordinate_y(node->left, true); 
    _update_contour(node->left, true);

    _pack_helper(node->left);
  }

  if (node->right) {
    node->right->llx = node->llx;
    node->right->lly = _calculate_coordinate_y(node->right, false);
    _update_contour(node->right, false);
    
    _pack_helper(node->right); 
  }

}


// optimize the floor plan
void BStar::optimize() {
  _generate_initial_tree();

  //_pack(_root);
  double initial_temperature = _calculate_initial_temperature();
  std::cout << "initial temperature = " << initial_temperature << '\n';
  _simulated_annealing(initial_temperature);
}


// operation 1 : rotate one module
void BStar::_rotate_module(BNode* node) {
  
  size_t temp = node->width;
  node->width = node->height;
  node->height = temp;

}


// operation 2 : swap two nodes
void BStar::_swap_two_nodes(BNode* node1, BNode* node2) {
  std::cout << "node1 at " << node1 << '\n';
  std::cout << "node2 at " << node2 << '\n'; 
  //std::cout << "swap " << node1->id << " and " << node2->id << "\n";
  std::cout << "node1->parent = " << node1->parent
            << ", node2->parent = " << node2->parent << '\n'; 
  // case 1 : same parent
  if (node1->parent == node2->parent) {
    std::cout << "same parent\n";

    std::cout << "node1->parent->left = " << node1->parent->left << '\n';
    std::cout << "node1->parent->right = " << node1->parent->right << '\n';
    
    std::swap(node1->parent->left, node1->parent->right);
    //std::cout << node1->parent->left << '\n';
    //std::cout << node1->parent->right << '\n';
    
    std::swap(node1->left, node2->left);
    //std::cout << node1->left->id << '\n';
    //std::cout << node2->left->id << '\n';
    
    std::swap(node1->right, node2->right);
    //std::cout << node2->right->id << '\n';

    if (node1->left)   node1->left->parent = node1;
    if (node1->right)  node1->right->parent = node1;
    if (node2->left)   node2->left->parent = node2;
    if (node2->right)  node2->right->parent = node2;
  } 

  // case 2 : parent-child relationship
  else if ((node1->parent == node2) || (node2->parent == node1)) {
    BNode* parent;
    BNode* child;

    // decide who is the parent 
    if (node1->parent == node2) {
      parent = node2;
      child = node1;
    }
    else {
      parent = node1;
      child = node2;
    }

    if (parent->parent) {
      if (parent->parent->left == parent)
        parent->parent->left = child;
      else
        parent->parent->right = child;
    }

    child->parent = parent->parent;
    parent->parent = child;
     
    if (parent->left == child) {
      parent->left = child->left;
      child->left = parent;
      std::swap(parent->right, child->right);
      
      if (parent->left)
        parent->left->parent = parent;
      if (parent->right)
        parent->right->parent = parent;
      if (child->right)
        child->right->parent = child;  
    }
      
    else {
      parent->right = child->right;
      child->right = parent;
      std::swap(parent->left, child->left);
      
      if (parent->right)
        parent->right->parent = parent;
      if (parent->left)
        parent->left->parent = parent;
      if (child->left)
        child->left->parent = child;  
    }
  }

  // case 3 : no relationship
  else {
    BNode* n1_old_parent = node1->parent;
    BNode* n2_old_parent = node2->parent;

    std::swap(node1->parent, node2->parent);
    std::swap(node1->left, node2->left);
    std::swap(node1->right, node2->right);
    if (node1->left)   node1->left->parent = node1;
    if (node1->right)  node1->right->parent = node1;
    if (node2->left)   node2->left->parent = node2;
    if (node2->right)  node2->right->parent = node2;

    if (n1_old_parent) {
      if (n1_old_parent->left == node1)
        n1_old_parent->left = node2;
      else
        n1_old_parent->right = node2; 
    }

    if (n2_old_parent) {
      if (n2_old_parent->left == node2)
        n2_old_parent->left = node1;
      else
        n2_old_parent->right = node1; 
    }
  }

  //std::cout << "after swap\n";
  //dump(std::cout);
  //std::cout << "------------------\n";
}


// operation 3 : delete one node then insert it back 
void BStar::_delete_and_insert(BNode* target, std::vector<BNode>& modules) {
  
  //std::cout << "delete " << target->id << " and insert after " << parent->id << '\n';
  _delete_node(target);
  _insert_node(target, modules); 

}



// insert the node to the tree
void BStar::_insert_node(BNode* target, std::vector<BNode>& modules) {
  
  BNode* parent = &(modules[std::rand()%(modules.size())]);

  while ((target == parent) || ((parent->left) && (parent->right)))
    parent = &(modules[std::rand()%(modules.size())]);
  
  // parent has no children
  if ((parent->left == nullptr) && (parent->right == nullptr)) {
    if (std::rand()%2 == 0)
      parent->left = target;
    else
      parent->right = target;

    target->parent = parent;
  }

  // parent has no left child
  else if (parent->left == nullptr) {
    parent->left = target;
    target->parent = parent;
  }

  // parent has no right child
  else {
    parent->right = target;
    target->parent = parent;
  }
} 


// delete one node
void BStar::_delete_node(BNode* node) {
  
  //std::cout << "before delete node\n";
  //dump(std::cout); 
  
  // case 1 : two children exist
  if (node->left && node->right) {
    while (node->left && node->right) {
      if ((std::rand()%2) == 0)  
        _swap_two_nodes(node, node->left);
      else 
        _swap_two_nodes(node, node->right);
    }
    _delete_node(node);
  }
 
  // case 2 : only left child exists
  else if (node->left) {
    BNode* parent = node->parent;
    BNode* child = node->left;

    if (parent) {
      if (parent->left == node)
        parent->left = child;  
      else
        parent->right = child;
    }
    node->parent = nullptr;
    node->left = nullptr;
    child->parent = parent;
  }

  // case 3 : only right child exists
  else if (node->right) {
    BNode* parent = node->parent;
    BNode* child = node->right;

    if (parent) {
      if (parent->left == node)
        parent->left = child;  
      else
        parent->right = child;
    }
    node->parent = nullptr;
    node->right = nullptr;
    child->parent = parent;
  }

  // case 4 : no children
  else {
    if (node->parent == nullptr)
      return;
    else {
      if (node->parent->left == node) {
        node->parent->left = nullptr;
        node->parent = nullptr;
      }
      else {
        node->parent->right = nullptr; 
        node->parent = nullptr;
      }
    }
  }

  //std::cout << "after delete node\n";
  //dump(std::cout);
  //std::cout << "----------------\n";
}


// simulated annealing
void BStar::_simulated_annealing(const double initial_temperature) {
  
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_real_distribution<> dis(0, 1.0);
  
  double temperature = initial_temperature;

  std::vector<BNode> modules_prop;
  std::vector<BNode> modules_curr;
  std::vector<BNode> modules_best;

  modules_curr = _modules;
  modules_best = modules_curr;


  size_t area_best = _pack(modules_curr);
  //dump(std::cout);
  //std::cin.get();
  
  size_t area_curr = area_best;
  
  while(temperature > BSFP_FROZEN_TEMPERATURE) {  
    for (size_t iter = 0; iter < BSFP_MAX_ITERATIONS_PER_TEMPERATURE; iter++) {
      modules_prop = modules_curr;
      //std::cout << "modules proposed before neighbor \n";
      std::cout << "modules_curr = " << '\n';
      _dump(modules_curr);
      _generate_neighbor(modules_prop);
      //std::cout << "modules proposed after neighbor \n";
      std::cout << "modules_prop = " << '\n';
      _dump(modules_prop);
      //std::cout << " ------------------\n";
      //std::cin.get();

      size_t area_prop = _pack(modules_prop);

      std::cout << "area_curr = " << area_curr << " , area_prop = " << area_prop << '\n';
      double cost = area_prop < area_curr ? 
                    (double)-1*(area_curr - area_prop) : area_prop - area_curr;

      //std::cout << "cost = " << cost << '\n';
      if (cost < 0) {
        modules_curr = modules_prop;
        area_curr = area_prop;
         
        if (area_prop < area_best) {
          std::cout << "best solution with area = " << _urx << "*" << _ury << " = " << area_best << "\n";
          modules_best = modules_prop;
          area_best = area_prop;
        }

      }

      else {
        //std::cout << "-cost/temperature = " << -cost/temperature << '\n';
        auto prob = std::exp(-cost/temperature);

        if (prob > dis(gen)) {
          std::cout << "take worse solution with area = " << _urx << "*" << _ury << " = " << area_prop << "\n";
          _dump(modules_prop);
          modules_curr = modules_prop;
          area_curr = area_prop;
        }
      }
    }
    temperature *= 0.95;
  }

  _dump(modules_best);
  _modules = modules_best;

}


// generate different tree
void BStar::_generate_neighbor(std::vector<BNode>& modules) {

  //std::cout << "before generating neighbot\n";
  //_dump(modules_prop);

  BNode* node1_ptr = &(modules[std::rand()%(modules.size())]);
  
  BNode* node2_ptr = &(modules[std::rand()%(modules.size())]);
  
  switch(std::rand()%3) {
    case 0:
      //std::cout << "rotate module\n";
      _rotate_module(node1_ptr);
      break;

    case 1:
      //std::cout << "swap two nodes\n";
      while (node1_ptr == node2_ptr) {
        node2_ptr = &(modules[std::rand()%(modules.size())]);  
      }    
      _swap_two_nodes(node1_ptr, node2_ptr);
      break;

    case 2:
      //std::cout << "delete and insert\n";
      // delete node1 first then insert it back
      _delete_and_insert(node1_ptr, modules);
      break;
  }

}



void BStar::_dump(const std::vector<BNode> modules) const {
  
  for (auto m : modules) {
    std::cout << m.id << ", "; 
    //          << m->llx << ", "
    //          << m->lly << ", "
    //          << m->width << ", "
    //          << m->height << ", ";
    if (m.parent)
      std::cout << "parent : " << m.parent->id << ", ";
    if (m.left)
      std::cout << "left : " << m.left->id << ", ";
    if (m.right)
      std::cout << "right : " << m.right->id << ", ";
    std::cout << '\n';
  }

}


// calculate the initial temperature for SA
double BStar::_calculate_initial_temperature() {

  size_t num_moves = 0;
  double total_area_change = 0.0;
  double delta_area, avg_area_change, init_temperature;

  std::vector<BNode> modules_curr = _modules;
  std::vector<BNode> modules_prop = _modules;

  size_t area_curr = _pack(modules_curr);
  size_t area_prop;

  while(num_moves < BSFP_RANDOM_MOVES) {
    _generate_neighbor(modules_prop);

    area_prop = _pack(modules_prop);
    delta_area = area_prop > area_curr ? 
                 (area_prop - area_curr) : (area_curr - area_prop);
    //std::cout << "area_prop = " << area_prop << ", area_curr = " << area_curr << '\n';
    total_area_change += delta_area;

    //std::cout << "delta_area = " << delta_area << '\n';
    //std::cout << "total_area_change = " << total_area_change << '\n';
    ++num_moves;
    area_curr = area_prop;
  }

  avg_area_change = total_area_change / num_moves;
  //std::cout << "total_area_change = " << total_area_change << '\n';
  init_temperature = BSFP_P < 1 ? 
                     (BSFP_T0 * avg_area_change) / log(BSFP_P) : 
                     avg_area_change / log(BSFP_P);

  return init_temperature;

}




}
