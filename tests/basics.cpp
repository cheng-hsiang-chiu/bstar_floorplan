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

  tester.open("/home/chiu/bstar_floorplan/circuits/circuit2.txt");
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
    REQUIRE(modules[1]->left->id == 5);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 3);
    REQUIRE(modules[2]->right->id == 4);
    
    REQUIRE(modules[3]->parent->id == 2);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 2);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 1);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes with the same parent - 2") {
    tester.swap_two_nodes(modules[2], modules[1]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 2);
    REQUIRE(modules[0]->right->id == 1);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 5);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 3);
    REQUIRE(modules[2]->right->id == 4);
    
    REQUIRE(modules[3]->parent->id == 2);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 2);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 1);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes with the same parent - 3") {
    tester.swap_two_nodes(modules[3], modules[4]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 4);
    REQUIRE(modules[1]->right->id == 3);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes with the same parent - 4") {
    tester.swap_two_nodes(modules[4], modules[3]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 4);
    REQUIRE(modules[1]->right->id == 3);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 1") {
    tester.swap_two_nodes(modules[0], modules[1]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left->id == 3);
    REQUIRE(modules[0]->right->id == 4);

    REQUIRE(modules[1]->parent == nullptr);
    REQUIRE(modules[1]->left->id == 0);
    REQUIRE(modules[1]->right->id == 2);

    REQUIRE(modules[2]->parent->id == 1);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 0);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 2") {
    tester.swap_two_nodes(modules[1], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left->id == 3);
    REQUIRE(modules[0]->right->id == 4);

    REQUIRE(modules[1]->parent == nullptr);
    REQUIRE(modules[1]->left->id == 0);
    REQUIRE(modules[1]->right->id == 2);

    REQUIRE(modules[2]->parent->id == 1);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 0);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 3") {
    tester.swap_two_nodes(modules[0], modules[2]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 2);
    REQUIRE(modules[0]->left->id == 5);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 2);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent == nullptr);
    REQUIRE(modules[2]->left->id == 1);
    REQUIRE(modules[2]->right->id == 0);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 0);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }
  
  SUBCASE("swap nodes with parent-child relationship - 4") {
    tester.swap_two_nodes(modules[2], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 2);
    REQUIRE(modules[0]->left->id == 5);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 2);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent == nullptr);
    REQUIRE(modules[2]->left->id == 1);
    REQUIRE(modules[2]->right->id == 0);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 0);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
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
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left->id == 1);
    REQUIRE(modules[3]->right->id == 4);
    
    REQUIRE(modules[4]->parent->id == 3);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
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
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left->id == 1);
    REQUIRE(modules[3]->right->id == 4);
    
    REQUIRE(modules[4]->parent->id == 3);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 7") {
    tester.swap_two_nodes(modules[1], modules[4]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 4);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 4);
    REQUIRE(modules[1]->left == nullptr);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 4);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 0);
    REQUIRE(modules[4]->left->id == 3);
    REQUIRE(modules[4]->right->id == 1);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 8") {
    tester.swap_two_nodes(modules[4], modules[1]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 4);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 4);
    REQUIRE(modules[1]->left == nullptr);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 4);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 0);
    REQUIRE(modules[4]->left->id == 3);
    REQUIRE(modules[4]->right->id == 1);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 9") {
    tester.swap_two_nodes(modules[2], modules[5]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 5);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 5);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 0);
    REQUIRE(modules[5]->left->id == 2);
    REQUIRE(modules[5]->right == nullptr);
  }
  
  SUBCASE("swap nodes with parent-child relationship - 10") {
    tester.swap_two_nodes(modules[5], modules[2]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 5);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 5);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 0);
    REQUIRE(modules[5]->left->id == 2);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 1") {
    tester.swap_two_nodes(modules[0], modules[3]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 3);
    REQUIRE(modules[1]->left->id == 0);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 3);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent == nullptr);
    REQUIRE(modules[3]->left->id == 1);
    REQUIRE(modules[3]->right->id == 2);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 2") {
    tester.swap_two_nodes(modules[3], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 3);
    REQUIRE(modules[1]->left->id == 0);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 3);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent == nullptr);
    REQUIRE(modules[3]->left->id == 1);
    REQUIRE(modules[3]->right->id == 2);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 3") {
    tester.swap_two_nodes(modules[0], modules[4]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 4);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 0);

    REQUIRE(modules[2]->parent->id == 4);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent == nullptr);
    REQUIRE(modules[4]->left->id == 1);
    REQUIRE(modules[4]->right->id == 2);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 4") {
    tester.swap_two_nodes(modules[4], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 4);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 0);

    REQUIRE(modules[2]->parent->id == 4);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent == nullptr);
    REQUIRE(modules[4]->left->id == 1);
    REQUIRE(modules[4]->right->id == 2);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 5") {
    tester.swap_two_nodes(modules[0], modules[5]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 2);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 5);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 5);
    REQUIRE(modules[2]->left->id == 0);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent == nullptr);
    REQUIRE(modules[5]->left->id == 1);
    REQUIRE(modules[5]->right->id == 2);
  }

  SUBCASE("swap nodes without relationship - 6") {
    tester.swap_two_nodes(modules[5], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 2);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 5);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 5);
    REQUIRE(modules[2]->left->id == 0);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent == nullptr);
    REQUIRE(modules[5]->left->id == 1);
    REQUIRE(modules[5]->right->id == 2);
  }

  SUBCASE("swap nodes without relationship - 7") {
    tester.swap_two_nodes(modules[2], modules[3]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 3);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 2);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 1);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left->id == 5);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 3);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 8") {
    tester.swap_two_nodes(modules[3], modules[2]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 3);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 2);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 1);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 0);
    REQUIRE(modules[3]->left->id == 5);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 3);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 9") {
    tester.swap_two_nodes(modules[2], modules[4]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 4);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 2);

    REQUIRE(modules[2]->parent->id == 1);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 0);
    REQUIRE(modules[4]->left->id == 5);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 4);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 10") {
    tester.swap_two_nodes(modules[4], modules[2]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 4);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 2);

    REQUIRE(modules[2]->parent->id == 1);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 0);
    REQUIRE(modules[4]->left->id == 5);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 4);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 11") {
    tester.swap_two_nodes(modules[1], modules[5]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 5);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 2);
    REQUIRE(modules[1]->left == nullptr);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 1);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 5);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 5);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 0);
    REQUIRE(modules[5]->left->id == 3);
    REQUIRE(modules[5]->right->id == 4);
  }
  
  SUBCASE("swap nodes without relationship - 12") {
    tester.swap_two_nodes(modules[5], modules[1]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 5);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 2);
    REQUIRE(modules[1]->left == nullptr);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 1);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 5);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 5);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 0);
    REQUIRE(modules[5]->left->id == 3);
    REQUIRE(modules[5]->right->id == 4);
  }

  SUBCASE("swap nodes without relationship - 13") {
    tester.swap_two_nodes(modules[0], modules[3]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 3);
    REQUIRE(modules[1]->left->id == 0);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 3);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent == nullptr);
    REQUIRE(modules[3]->left->id == 1);
    REQUIRE(modules[3]->right->id == 2);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 14") {
    tester.swap_two_nodes(modules[3], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 3);
    REQUIRE(modules[1]->left->id == 0);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 3);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent == nullptr);
    REQUIRE(modules[3]->left->id == 1);
    REQUIRE(modules[3]->right->id == 2);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 15") {
    tester.swap_two_nodes(modules[0], modules[4]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 4);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 0);

    REQUIRE(modules[2]->parent->id == 4);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent == nullptr);
    REQUIRE(modules[4]->left->id == 1);
    REQUIRE(modules[4]->right->id == 2);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 16") {
    tester.swap_two_nodes(modules[4], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 1);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 4);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 0);

    REQUIRE(modules[2]->parent->id == 4);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent == nullptr);
    REQUIRE(modules[4]->left->id == 1);
    REQUIRE(modules[4]->right->id == 2);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 17") {
    tester.swap_two_nodes(modules[0], modules[5]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 2);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 5);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 5);
    REQUIRE(modules[2]->left->id == 0);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent == nullptr);
    REQUIRE(modules[5]->left->id == 1);
    REQUIRE(modules[5]->right->id == 2);
  }
  
  SUBCASE("swap nodes without relationship - 18") {
    tester.swap_two_nodes(modules[5], modules[0]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent->id == 2);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 5);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 5);
    REQUIRE(modules[2]->left->id == 0);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent == nullptr);
    REQUIRE(modules[5]->left->id == 1);
    REQUIRE(modules[5]->right->id == 2);
  }
}


TEST_CASE("delete_node" * doctest::timeout(300)) {

  bstar::BStarTester tester;

  tester.open("/home/chiu/bstar_floorplan/circuits/circuit2.txt");
  tester.generate_initial_tree();
   
  std::vector<std::shared_ptr<bstar::BNode>> modules;

  modules = tester.get_modules();
  
  SUBCASE("node is a leaf node - 1") {
    tester.delete_node(modules[3]);

    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left == nullptr);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent == nullptr);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("node is a leaf node - 2") {
    tester.delete_node(modules[4]);
    
    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right == nullptr);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left->id == 5);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent == nullptr);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }
  
  SUBCASE("node is a leaf node - 3") {
    tester.delete_node(modules[5]);
    
    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 2);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent->id == 0);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent == nullptr);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }

  SUBCASE("node has only left child") {
    tester.delete_node(modules[2]);
    
    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left->id == 1);
    REQUIRE(modules[0]->right->id == 5);

    REQUIRE(modules[1]->parent->id == 0);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent == nullptr);
    REQUIRE(modules[2]->left == nullptr);
    REQUIRE(modules[2]->right == nullptr);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 0);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);

  }
  
  SUBCASE("delete and insert") {
    tester.delete_node(modules[0]);
    
    modules = tester.get_modules();
    
    std::cout << "after deletion\n";
    tester.dump(std::cout);

    std::cout << "after insertion\n";
    tester.insert_node(modules[0]);
    tester.dump(std::cout);
  }

  /*
  SUBCASE("node two children") {
    tester.delete_node(modules[0]);
    
    modules = tester.get_modules();
    
    REQUIRE(modules[0]->parent == nullptr);
    REQUIRE(modules[0]->left == nullptr);
    REQUIRE(modules[0]->right == nullptr);

    REQUIRE(modules[1]->parent->id == 2);
    REQUIRE(modules[1]->left->id == 3);
    REQUIRE(modules[1]->right->id == 4);

    REQUIRE(modules[2]->parent == nullptr);
    REQUIRE(modules[2]->left->id == 1);
    REQUIRE(modules[2]->right->id == 5);
    
    REQUIRE(modules[3]->parent->id == 1);
    REQUIRE(modules[3]->left == nullptr);
    REQUIRE(modules[3]->right == nullptr);
    
    REQUIRE(modules[4]->parent->id == 1);
    REQUIRE(modules[4]->left == nullptr);
    REQUIRE(modules[4]->right == nullptr);
    
    REQUIRE(modules[5]->parent->id == 2);
    REQUIRE(modules[5]->left == nullptr);
    REQUIRE(modules[5]->right == nullptr);
  }
  */
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

