#include <vector>
#include <iostream>


namespace btree {
  
  // TODO: change it to left child and right child
  // 
  struct BNode {
    std::vector<int> keys;
    std::vector<BNode*> children;  // not necessary
    
    //bool has_children = false;

    BNode* right {nullptr};
    BNode* left  {nullptr};
    
  };

  class BTree {
    friend class BTreeTester;

    public:
      BTree(const size_t m);
      void traverse() const;
      void search(const int k) const;
      void insert(const int k);
      void remove();
      void testing();
      BNode* get_root() const;

    private:
      BNode* _root;
      size_t _order;
      int _promote_key;
      std::vector<BNode*> _stk;

      // TODO: prefer smart pointer than raw pointer
      // unique_ptr > shared_ptre > raw pointer
      std::vector<std::unique_ptr<BNode*>> _nodes;

      size_t _get_insertion_position(const BNode* node, const int k) const;
      void _traverse_helper(const BNode* node) const;
      void _search_helper(const BNode* node, const int k) const;
      void _insert_helper(BNode*& node, const int k);
      BNode* _split_node(BNode*& node);
  };


  // constructor
  BTree::BTree(const size_t m) : _order(m) {
    std::cout << "creating a root node\n";
    _root = new BNode(); 
    //_root->has_children = false;
  };


  // get where to insert the new key
  size_t BTree::_get_insertion_position(const BNode* node, const int k) const {
    size_t i = 0;
    while ((i < node->keys.size()) && (k > node->keys[i]))
      ++i;
      
    return i;
  }
  

  BNode* BTree::get_root() const {
    return _root;
  }

 
  // insert key into the tree
  void BTree::insert(const int k) {
    if (_root->keys.empty()) {
      _root->keys.push_back(k);
      return;
    }

    else 
      _insert_helper(_root, k);
  }


  void BTree::_insert_helper(BNode*& node, const int k) {
    size_t index = _get_insertion_position(node, k);
    
    // check children if it exists
    if (node->has_children) {
      _insert_helper(node->children[index], k);

      // _stk has splitted node from children
      if (!_stk.empty()) {
        index = _get_insertion_position(node, _promote_key);
        
        auto it = node->keys.begin();
        node->keys.insert(it+index, 1, _promote_key);
        
        size_t i = node->keys.size()-1;
        node->children.push_back(node->children[i]);
 
        
        while (i > index+1) {
          node->children[i] = node->children[i-1];
          --i;
        }

        node->children[index+1] = _stk.front();
        _stk.pop_back();

      }
    }

    // has no children
    else {
      auto it = node->keys.begin();
      node->keys.insert(it+index, 1, k);
    }  
      
    // node has reached maximum capacity
    if (node->keys.size() == _order) {
      _promote_key = node->keys[node->keys.size()/2];
      _stk.push_back(_split_node(node));


      if (node == _root) {
        BNode* new_root = new BNode();
       
        new_root->has_children = true;
        new_root->keys.push_back(_promote_key);
        new_root->children.push_back(node);
        new_root->children.push_back(_stk.front());
        _stk.pop_back();
        
        _root = new_root; 
      }
    }
  }


  // return the key that will be promoted to the parent node
  BNode* BTree::_split_node(BNode*& node) {
    BNode* new_node = new BNode();

    size_t len = node->keys.size();
    size_t upper = len/2;
    
    if (len % 2 == 0)
      upper = len/2-1;

    for (size_t i = 0; i < upper; ++i) { 
      new_node->keys.push_back(node->keys[i+len/2+1]);
      
      if (node->has_children) {
        new_node->has_children = true;
        new_node->children.push_back(node->children[i+len/2+1]);
        
        if (i == upper-1)
          new_node->children.push_back(node->children[i+len/2+2]);   
      }
    }

    
    for (size_t i = 0; i <= upper; ++i) {
      node->keys.pop_back();

      if (node->has_children) 
        node->children.pop_back();
    }

    /*
    for (size_t i = 0; i < node->keys.size(); ++i)
      std::cout << node->keys[i] << '\n';
    if (node->has_children) {
      for (size_t i = 0; i < node->children.size(); ++i)
        std::cout << node->children[i]->keys[0] << '\n';
    }
    */

    return new_node;  
  }  


  // traverse the whole tree
  void BTree::traverse() const {
    if (_root->keys.empty()) {  
      std::cout << "empty tree\n";
      return;
    }

    BTree::_traverse_helper(_root);
    std::cout << '\n';
  }


  // the auxiliary function of traverse 
  void BTree::_traverse_helper(const BNode* node) const {
    if (node->has_children) {
      for (size_t i = 0; i < node->children.size(); ++i) {
        BTree::_traverse_helper(node->children[i]);
        if (i < node->keys.size())
          std::cout << node->keys[i] << ' ';
      }
    }

    else {
      for (size_t i = 0; i < node->keys.size(); ++i)
        std::cout << node->keys[i] << ' ';
    }
  }


  // search the location of the target key
  void BTree::search(const int k) const {
    if (_root->keys.empty()) {
      std::cout << "empty tree\n";
      return;
    }

    BTree::_search_helper(_root, k);
  }


  // the auxiliary function of search
  void BTree::_search_helper(const BNode* node, const int k) const {
    size_t i = 0;
    
    while ((i < node->keys.size()) && (k > node->keys[i]))
      ++i;
      
    if (k == node->keys[i]) {
      std::cout << "found " << k << " at " << &(node->keys[i]) << '\n';
      return;
    }

    if (node->has_children)
      BTree::_search_helper(node->children[i], k);
    else
      std::cout << "found nothing\n";
  }
  

  void BTree::testing() {
    std::cout << "_root->keys[0] = " << _root->keys[0] << '\n';
    //std::cout << "_root->keys[1] = " << _root->keys[1] << '\n';
    //std::cout << "_root->keys[2] = " << _root->keys[2] << '\n';
    
    std::cout << "_root->children[0]->keys[0] = " << _root->children[0]->keys[0] << '\n';
    std::cout << "_root->children[0]->keys[1] = " << _root->children[0]->keys[1] << '\n';
    std::cout << "_root->children[1]->keys[0] = " << _root->children[1]->keys[0] << '\n';
    //std::cout << "_root->children[1]->keys[1] = " << _root->children[1]->keys[1] << '\n';
    
    //std::cout << "_root->children[2]->keys[0] = " << _root->children[2]->keys[0] << '\n';
    //std::cout << "_root->children[2]->keys[1] = " << _root->children[2]->keys[1] << '\n';
    //std::cout << "_root->children[3]->keys[0] = " << _root->children[3]->keys[0] << '\n';
    //std::cout << "_root->children[3]->keys[1] = " << _root->children[3]->keys[1] << '\n';
    //std::cout << "_root->children[3]->keys[2] = " << _root->children[3]->keys[2] << '\n';
    
    std::cout << "_root->children[0]->children[0]->keys[0] = " << _root->children[0]->children[0]->keys[0] << '\n';
    std::cout << "_root->children[0]->children[0]->keys[1] = " << _root->children[0]->children[0]->keys[1] << '\n';
    std::cout << "_root->children[0]->children[1]->keys[0] = " << _root->children[0]->children[1]->keys[0] << '\n';
    std::cout << "_root->children[0]->children[1]->keys[1] = " << _root->children[0]->children[1]->keys[1] << '\n';
    std::cout << "_root->children[0]->children[2]->keys[0] = " << _root->children[0]->children[2]->keys[0] << '\n';
    std::cout << "_root->children[0]->children[2]->keys[1] = " << _root->children[0]->children[2]->keys[1] << '\n';
    std::cout << "_root->children[1]->children[0]->keys[0] = " << _root->children[1]->children[0]->keys[0] << '\n';
    std::cout << "_root->children[1]->children[0]->keys[1] = " << _root->children[1]->children[0]->keys[1] << '\n';
    std::cout << "_root->children[1]->children[1]->keys[0] = " << _root->children[1]->children[1]->keys[0] << '\n';
    //std::cout << "_root->children[1]->children[1]->keys[1] = " << _root->children[1]->children[1]->keys[1] << '\n';
    //std::cout << "_root->children[1]->children[1]->keys[2] = " << _root->children[1]->children[1]->keys[2] << '\n';
    
  }
}
