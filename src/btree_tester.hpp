#pragma once

#include "btree.hpp"

namespace btree {
 
  class BTreeTester {
    public:
      BTreeTester(const size_t m);
      void traverse() const;
      void search(const int k) const;
      void insert(const int k);
      void remove();
      size_t get_insertion_position(const BNode* node, const int k) const;
      void traverse_helper(const BNode* node) const;
      void search_helper(const BNode* node, const int k) const;
      void insert_helper(BNode*& node, const int k);
      BNode* split_node(BNode*& node);
      BNode* get_root() const;
      int order;       

      std::unique_ptr<BTree> _bt;

      BTree btree;
  };


  // constructor
  BTreeTester::BTreeTester(const size_t m) : order(m), btree {m} {
    std::cout << "construct a btree tester\n";
    //BTree* _bt_tester = new BTree(m);
  }


  BNode* BTreeTester::get_root() const {
    //BTree* _bt_tester = new BTree(order);
    std::cout << "get_root from BtreeTester\n";
    return btree.get_root();
  }


  // get where to insert the new key
  size_t BTreeTester::get_insertion_position(const BNode* node, const int k) const {
    //BTree* _bt_tester = new BTree(order);
    return _bt_tester->_get_insertion_position(node, k);
  }
  

  // insert key into the tree
  void BTreeTester::insert(const int k) {
    //BTree* _bt_tester = new BTree(order);
    _bt_tester->insert(k);
  }


  /*
  void BTreeTester::insert_helper(BNode*& node, const int k) {
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
        node->children.push_back(node->children[i--]);
 
        
        while (i > index+1)
          node->children[i] = node->children[--i];

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
  */


  // return the key that will be promoted to the parent node
  BNode* BTreeTester::split_node(BNode*& node) {
    //BTree* _bt_tester = new BTree(order);
    return _bt_tester->_split_node(node);
  }  


  // traverse the whole tree
  void  BTreeTester::traverse() const {
    //BTree* _bt_tester = new BTree(order);
    _bt_tester->traverse();
  }


  // the auxiliary function of traverse 
  void BTreeTester::traverse_helper(const BNode* node) const {
    //BTree* _bt_tester = new BTree(order);
    _bt_tester->_traverse_helper(node);
  }


  // search the location of the target key
  void BTreeTester::search(const int k) const {
    //BTree* _bt_tester = new BTree(order);
    _bt_tester->search(k);
  }


  // the auxiliary function of search
  void BTreeTester::search_helper(const BNode* node, const int k) const {
    //BTree* _bt_tester = new BTree(order);
    _bt_tester->_search_helper(node, k);

  }
}
