#include "../src/bstar.hpp"

namespace bstar{


class BStarTester {
  public:
    BStarTester();

    void update_contour(BNode* node_ptr);

    std::vector<BNode*> get_contour() const;
    std::vector<BNode> get_modules() const;
    
    void open(const std::string input_file); 
    void dump(std::ostream& os);
    void swap_two_nodes(BNode* node1, BNode* node2);
    void generate_initial_tree();
    void delete_node(BNode* node_ptr);
    void insert_node(BNode* target, std::vector<BNode>& modules);
    void dump_modules(const std::vector<BNode> modules) const;
                
    BStar bs;
    std::vector<int> contour;
};


BStarTester::BStarTester() {
  std::cout << "bstar tester constructor\n";
}


void BStarTester::update_contour(BNode* node_ptr) {
  bs._update_contour(node_ptr, true);
}


void BStarTester::open(const std::string input_file) {
  std::cout << "bstar tester open\n";
  bs.open(input_file);
}


std::vector<BNode*> BStarTester::get_contour() const {
  return bs._contour;
}


std::vector<BNode> BStarTester::get_modules() const {
  /*
  bs._modules[0]->parent = bs._modules[1];
  bs._modules[0]->left = bs._modules[3];
  bs._modules[0]->right = nullptr;
  
  bs._modules[1]->parent = nullptr;
  bs._modules[1]->left = bs._modules[0];
  bs._modules[1]->right = bs._modules[2];
  
  bs._modules[2]->parent = bs._modules[1];;
  bs._modules[2]->left = nullptr;
  bs._modules[2]->right = nullptr;
  
  bs._modules[3]->parent = bs._modules[0];
  bs._modules[3]->left = nullptr;
  bs._modules[3]->right = nullptr;
  */
  return bs._modules;

}


void BStarTester::dump(std::ostream& os){
  bs.dump(os);
}


void BStarTester::swap_two_nodes(BNode* node1, BNode* node2) {
  bs._swap_two_nodes(node1, node2); 
}


void BStarTester::generate_initial_tree() {
  bs._generate_initial_tree();
}


void BStarTester::delete_node(BNode* node_ptr) {
  bs._delete_node(node_ptr);
}


void BStarTester::insert_node(BNode* target, std::vector<BNode>& modules) {
  bs._insert_node(target, modules);
}


void BStarTester::dump_modules(const std::vector<BNode> modules) const {
  bs._dump(modules);
}



}
