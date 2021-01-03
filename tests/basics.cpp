#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bstar_tester.hpp"


/*
TEST_CASE("update_contour_after_insertion" * doctest::timeout(300)) {
  
  bstar::BStarTester tester;

  tester.open("../circuits/circuit1.txt");

  std::cout << "in test case, after open\n"; 
  std::vector<std::shared_ptr<bstar::BNode>> contour;
  
  std::shared_ptr<bstar::BNode> node = tester.get_modules()[0];
  
  tester.update_contour_after_insertion(node);
 
  contour = tester.get_contour();
  for (auto c : contour)
    std::cout << c->id << '\n'; 
  //REQUIRE((*contour.begin()).first == 0);
  //REQUIRE((*contour.begin()).second == 0);
}
*/


TEST_CASE("swap_two_nodes" * doctest::timeout(300)) {
  
  bstar::BStarTester tester;

  tester.open("/home/chiu/bstar_floorplan/circuits/circuit1.txt");
  tester.generate_initial_tree();
   
  std::vector<std::shared_ptr<bstar::BNode>> modules;

  modules = tester.get_modules();
  
  SUBCASE("swap nodes with the same parent - 1") {
    tester.swap_two_nodes(modules[1], modules[2]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 2);
    REQUIRE(modules[0]->right->id == 1);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left == nullptr);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 3);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 2);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
  }

  SUBCASE("swap nodes with the same parent - 2") {
    tester.swap_two_nodes(modules[2], modules[1]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 2);
    REQUIRE(modules[0]->right->id == 1);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left == nullptr);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 3);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 2);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 1") {
    tester.swap_two_nodes(modules[0], modules[1]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left->id == 3);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent == nullptr);
    REQUIRE(modules[1]->left->id == 0);
    REQUIRE(modules[1]->right->id == 2);

    REQUIRE(modules[2]->parent->id == 1);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 2") {
    tester.swap_two_nodes(modules[1], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left->id == 3);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent == nullptr);
    REQUIRE(modules[1]->left->id == 0);
    REQUIRE(modules[1]->right->id == 2);

    REQUIRE(modules[2]->parent->id == 1);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 3") {
    tester.swap_two_nodes(modules[0], modules[2]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 2);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 2);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent == nullptr);
    REQUIRE(modules[2]->left->id == 1);
    REQUIRE(modules[2]->right->id == 0);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
  }
  
  SUBCASE("swap nodes with parent-child relationship - 4") {
    tester.swap_two_nodes(modules[2], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 2);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 2);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent == nullptr);
    REQUIRE(modules[2]->left->id == 1);
    REQUIRE(modules[2]->right->id == 0);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
  }
  
  SUBCASE("swap nodes with parent-child relationship - 5") {
    tester.swap_two_nodes(modules[1], modules[3]);

    modules = tester.get_modules();
    tester.dump(std::cout);
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 3);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 3);
    REQUIRE(modules[1]->left == nullptr);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left->id == 1);
    REQUIRE(modules[3]->right == nullptr);
    
  }
  
  SUBCASE("swap nodes with parent-child relationship - 6") {
    tester.swap_two_nodes(modules[3], modules[1]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 3);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 3);
    REQUIRE(modules[1]->left == nullptr);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left->id == 1);
    REQUIRE(modules[3]->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 1") {
    tester.swap_two_nodes(modules[0], modules[3]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 3);
    REQUIRE(modules[1]->left->id == 0);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 3);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent == nullptr);
    REQUIRE(modules[3]->left->id == 1);
    REQUIRE(modules[3]->right->id == 2);
  }

  SUBCASE("swap nodes without relationship - 2") {
    tester.swap_two_nodes(modules[3], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 3);
    REQUIRE(modules[1]->left->id == 0);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 3);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent == nullptr);
    REQUIRE(modules[3]->left->id == 1);
    REQUIRE(modules[3]->right->id == 2);
  }

  SUBCASE("swap nodes without relationship - 3") {
    tester.swap_two_nodes(modules[2], modules[3]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 3);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 2);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 1);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 3") {
    tester.swap_two_nodes(modules[3], modules[2]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 3);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 2);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 1);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
  }
}


TEST_CASE("delete_and_insert" * doctest::timeout(300)) {

  bstar::BStarTester tester;

  tester.open("/home/chiu/bstar_floorplan/circuits/circuit1.txt");
  tester.generate_initial_tree();
   
  std::vector<std::shared_ptr<bstar::BNode>> modules;

  modules = tester.get_modules();
  
  SUBCASE("node is a leaf node - 1") {
    tester.delete_and_insert(modules[2]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent == nullptr);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
  }

  SUBCASE("node is a leaf node - 2") {
    tester.delete_and_insert(modules[3]);
    
    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left == nullptr);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent == nullptr);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
  }
}
/*
TEST_CASE("split_node" * doctest::timeout(300)) {
  
  btree::BTreeTester tester(4);
  
  btree::BNode* root = new btree::BNode();
  root->keys.push_back(6);
  root->keys.push_back(8);
  root->keys.push_back(16);
  root->keys.push_back(18);


  REQUIRE((tester.split_node(root))->keys[0] == 18);
}
*/

