#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bstar_tester.hpp"



TEST_CASE("swap_two_nodes" * doctest::timeout(300)) {
  
  bstar::BStarTester tester;

  tester.open("/home/chiu/bstar_floorplan/circuits/circuit2.txt");
  tester.generate_initial_tree();
   
  bstar::BNode* modules;

  modules = tester.get_modules();
 
  SUBCASE("swap nodes with the same parent - 1") {
 
    tester.swap_two_nodes((modules+1), (modules+2));
     
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 2);
    REQUIRE((modules+0)->right->id == 1);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 5);
    REQUIRE((modules+1)->right == nullptr);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 3);
    REQUIRE((modules+2)->right->id == 4);
    
    REQUIRE((modules+3)->parent->id == 2);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 2);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 1);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes with the same parent - 2") {
    
    tester.swap_two_nodes((modules+2), (modules+1));
  
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 2);
    REQUIRE((modules+0)->right->id == 1);
  
    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 5);
    REQUIRE((modules+1)->right == nullptr);
  
    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 3);
    REQUIRE((modules+2)->right->id == 4);
  
    REQUIRE((modules+3)->parent->id == 2);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 2);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
 
    REQUIRE((modules+5)->parent->id == 1);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes with the same parent - 3") {
    
    tester.swap_two_nodes((modules+3), (modules+4));
      
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 2);
  
    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 4);
    REQUIRE((modules+1)->right->id == 3);
  
    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
      
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
      
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
      
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);  
  }

  SUBCASE("swap nodes with the same parent - 4") {

    tester.swap_two_nodes((modules+4), (modules+3));
      
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 2);
    
    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 4);
    REQUIRE((modules+1)->right->id == 3);
   
    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
      
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
      
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
      
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 1") {

    tester.swap_two_nodes((modules+0), (modules+1));
    
    REQUIRE((modules+0)->parent->id == 1);
    REQUIRE((modules+0)->left->id == 3);
    REQUIRE((modules+0)->right->id == 4);

    REQUIRE((modules+1)->parent == nullptr);
    REQUIRE((modules+1)->left->id == 0);
    REQUIRE((modules+1)->right->id == 2);

    REQUIRE((modules+2)->parent->id == 1);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 0);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 0);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 2") {

    tester.swap_two_nodes((modules+1), (modules+0));
    
    REQUIRE((modules+0)->parent->id == 1);
    REQUIRE((modules+0)->left->id == 3);
    REQUIRE((modules+0)->right->id == 4);

    REQUIRE((modules+1)->parent == nullptr);
    REQUIRE((modules+1)->left->id == 0);
    REQUIRE((modules+1)->right->id == 2);

    REQUIRE((modules+2)->parent->id == 1);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 0);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 0);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 3") {
    
    tester.swap_two_nodes((modules+0), (modules+2));
    
    REQUIRE((modules+0)->parent->id == 2);
    REQUIRE((modules+0)->left->id == 5);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 2);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent == nullptr);
    REQUIRE((modules+2)->left->id == 1);
    REQUIRE((modules+2)->right->id == 0);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 0);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes with parent-child relationship - 4") {
    
    tester.swap_two_nodes((modules+2), (modules+0));

    REQUIRE((modules+0)->parent->id == 2);
    REQUIRE((modules+0)->left->id == 5);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 2);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent == nullptr);
    REQUIRE((modules+2)->left->id == 1);
    REQUIRE((modules+2)->right->id == 0);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 0);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes with parent-child relationship - 5") {

    tester.swap_two_nodes((modules+1), (modules+3));

    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 3);
    REQUIRE((modules+0)->right->id == 2);

    REQUIRE((modules+1)->parent->id == 3);
    REQUIRE((modules+1)->left == nullptr);
    REQUIRE((modules+1)->right == nullptr);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 0);
    REQUIRE((modules+3)->left->id == 1);
    REQUIRE((modules+3)->right->id == 4);
    
    REQUIRE((modules+4)->parent->id == 3);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes with parent-child relationship - 6") {

    tester.swap_two_nodes((modules+3), (modules+1));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 3);
    REQUIRE((modules+0)->right->id == 2);

    REQUIRE((modules+1)->parent->id == 3);
    REQUIRE((modules+1)->left == nullptr);
    REQUIRE((modules+1)->right == nullptr);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 0);
    REQUIRE((modules+3)->left->id == 1);
    REQUIRE((modules+3)->right->id == 4);
    
    REQUIRE((modules+4)->parent->id == 3);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 7") {
    
    tester.swap_two_nodes((modules+1), (modules+4));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 4);
    REQUIRE((modules+0)->right->id == 2);

    REQUIRE((modules+1)->parent->id == 4);
    REQUIRE((modules+1)->left == nullptr);
    REQUIRE((modules+1)->right == nullptr);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 4);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 0);
    REQUIRE((modules+4)->left->id == 3);
    REQUIRE((modules+4)->right->id == 1);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 8") {

    tester.swap_two_nodes((modules+4), (modules+1));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 4);
    REQUIRE((modules+0)->right->id == 2);

    REQUIRE((modules+1)->parent->id == 4);
    REQUIRE((modules+1)->left == nullptr);
    REQUIRE((modules+1)->right == nullptr);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 4);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 0);
    REQUIRE((modules+4)->left->id == 3);
    REQUIRE((modules+4)->right->id == 1);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes with parent-child relationship - 9") {

    tester.swap_two_nodes((modules+2), (modules+5));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 5);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 5);
    REQUIRE((modules+2)->left == nullptr);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 0);
    REQUIRE((modules+5)->left->id == 2);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes with parent-child relationship - 10") {
    
    tester.swap_two_nodes((modules+5), (modules+2));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 5);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 5);
    REQUIRE((modules+2)->left == nullptr);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 0);
    REQUIRE((modules+5)->left->id == 2);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 1") {
    
    tester.swap_two_nodes((modules+0), (modules+3));
    
    REQUIRE((modules+0)->parent->id == 1);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 3);
    REQUIRE((modules+1)->left->id == 0);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 3);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent == nullptr);
    REQUIRE((modules+3)->left->id == 1);
    REQUIRE((modules+3)->right->id == 2);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 2") {

    tester.swap_two_nodes((modules+3), (modules+0));
    
    REQUIRE((modules+0)->parent->id == 1);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 3);
    REQUIRE((modules+1)->left->id == 0);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 3);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent == nullptr);
    REQUIRE((modules+3)->left->id == 1);
    REQUIRE((modules+3)->right->id == 2);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 3") {

    tester.swap_two_nodes((modules+0), (modules+4));
    
    REQUIRE((modules+0)->parent->id == 1);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 4);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 0);

    REQUIRE((modules+2)->parent->id == 4);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent == nullptr);
    REQUIRE((modules+4)->left->id == 1);
    REQUIRE((modules+4)->right->id == 2);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 4") {

    tester.swap_two_nodes((modules+4), (modules+0));
    
    REQUIRE((modules+0)->parent->id == 1);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 4);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 0);

    REQUIRE((modules+2)->parent->id == 4);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent == nullptr);
    REQUIRE((modules+4)->left->id == 1);
    REQUIRE((modules+4)->right->id == 2);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 5") {

    tester.swap_two_nodes((modules+0), (modules+5));
    
    REQUIRE((modules+0)->parent->id == 2);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 5);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 5);
    REQUIRE((modules+2)->left->id == 0);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent == nullptr);
    REQUIRE((modules+5)->left->id == 1);
    REQUIRE((modules+5)->right->id == 2);
  }

  SUBCASE("swap nodes without relationship - 6") {

    tester.swap_two_nodes((modules+5), (modules+0));
    
    REQUIRE((modules+0)->parent->id == 2);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 5);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 5);
    REQUIRE((modules+2)->left->id == 0);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent == nullptr);
    REQUIRE((modules+5)->left->id == 1);
    REQUIRE((modules+5)->right->id == 2);
  }

  SUBCASE("swap nodes without relationship - 7") {

    tester.swap_two_nodes((modules+2), (modules+3));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 3);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 2);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 1);
    REQUIRE((modules+2)->left == nullptr);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 0);
    REQUIRE((modules+3)->left->id == 5);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 3);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 8") {

    tester.swap_two_nodes((modules+3), (modules+2));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 3);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 2);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 1);
    REQUIRE((modules+2)->left == nullptr);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 0);
    REQUIRE((modules+3)->left->id == 5);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 3);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("swap nodes without relationship - 9") {

    tester.swap_two_nodes((modules+2), (modules+4));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 4);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 2);

    REQUIRE((modules+2)->parent->id == 1);
    REQUIRE((modules+2)->left == nullptr);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 0);
    REQUIRE((modules+4)->left->id == 5);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 4);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 10") {

    tester.swap_two_nodes((modules+4), (modules+2));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 4);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 2);

    REQUIRE((modules+2)->parent->id == 1);
    REQUIRE((modules+2)->left == nullptr);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 0);
    REQUIRE((modules+4)->left->id == 5);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 4);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 11") {

    tester.swap_two_nodes((modules+1), (modules+5));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 5);
    REQUIRE((modules+0)->right->id == 2);

    REQUIRE((modules+1)->parent->id == 2);
    REQUIRE((modules+1)->left == nullptr);
    REQUIRE((modules+1)->right == nullptr);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 1);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 5);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 5);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 0);
    REQUIRE((modules+5)->left->id == 3);
    REQUIRE((modules+5)->right->id == 4);
  }
  
  SUBCASE("swap nodes without relationship - 12") {

    tester.swap_two_nodes((modules+5), (modules+1));
    
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 5);
    REQUIRE((modules+0)->right->id == 2);

    REQUIRE((modules+1)->parent->id == 2);
    REQUIRE((modules+1)->left == nullptr);
    REQUIRE((modules+1)->right == nullptr);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 1);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 5);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 5);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 0);
    REQUIRE((modules+5)->left->id == 3);
    REQUIRE((modules+5)->right->id == 4);
  }

  SUBCASE("swap nodes without relationship - 13") {

    tester.swap_two_nodes((modules+0), (modules+3));
    
    REQUIRE((modules+0)->parent->id == 1);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 3);
    REQUIRE((modules+1)->left->id == 0);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 3);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent == nullptr);
    REQUIRE((modules+3)->left->id == 1);
    REQUIRE((modules+3)->right->id == 2);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 14") {

    tester.swap_two_nodes((modules+3), (modules+0));
    
    REQUIRE((modules+0)->parent->id == 1);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 3);
    REQUIRE((modules+1)->left->id == 0);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 3);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent == nullptr);
    REQUIRE((modules+3)->left->id == 1);
    REQUIRE((modules+3)->right->id == 2);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 15") {

    tester.swap_two_nodes((modules+0), (modules+4));
    
    REQUIRE((modules+0)->parent->id == 1);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 4);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 0);

    REQUIRE((modules+2)->parent->id == 4);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent == nullptr);
    REQUIRE((modules+4)->left->id == 1);
    REQUIRE((modules+4)->right->id == 2);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 16") {

    tester.swap_two_nodes((modules+4), (modules+0));
    
    REQUIRE((modules+0)->parent->id == 1);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 4);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 0);

    REQUIRE((modules+2)->parent->id == 4);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent == nullptr);
    REQUIRE((modules+4)->left->id == 1);
    REQUIRE((modules+4)->right->id == 2);
    
    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }
  
  SUBCASE("swap nodes without relationship - 17") {

    tester.swap_two_nodes((modules+0), (modules+5));
    
    REQUIRE((modules+0)->parent->id == 2);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 5);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 5);
    REQUIRE((modules+2)->left->id == 0);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent == nullptr);
    REQUIRE((modules+5)->left->id == 1);
    REQUIRE((modules+5)->right->id == 2);
  }
  
  SUBCASE("swap nodes without relationship - 18") {

    tester.swap_two_nodes((modules+5), (modules+0));
    
    REQUIRE((modules+0)->parent->id == 2);
    REQUIRE((modules+0)->left == nullptr);
    REQUIRE((modules+0)->right == nullptr);

    REQUIRE((modules+1)->parent->id == 5);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 5);
    REQUIRE((modules+2)->left->id == 0);
    REQUIRE((modules+2)->right == nullptr);
    
    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);
    
    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);
    
    REQUIRE((modules+5)->parent == nullptr);
    REQUIRE((modules+5)->left->id == 1);
    REQUIRE((modules+5)->right->id == 2);
  }
}


TEST_CASE("delete_node" * doctest::timeout(300)) {

  bstar::BStarTester tester;

  tester.open("/home/chiu/bstar_floorplan/circuits/circuit2.txt");
  tester.generate_initial_tree();

  bstar::BNode* modules;
  
  modules = tester.get_modules();

  SUBCASE("node is a leaf node - 1") {

    tester.delete_node((modules+3));

    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 2);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left == nullptr);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);

    REQUIRE((modules+3)->parent == nullptr);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);

    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);

    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("node is a leaf node - 2") {
    
    tester.delete_node((modules+4));

    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 2);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right == nullptr);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);

    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);

    REQUIRE((modules+4)->parent == nullptr);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);

    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("node is a leaf node - 3") {
 
    tester.delete_node((modules+5));

    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 2);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left == nullptr);
    REQUIRE((modules+2)->right == nullptr);

    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);

    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);

    REQUIRE((modules+5)->parent == nullptr);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("node has only left child") {

    tester.delete_node((modules+2));

    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 5);

    REQUIRE((modules+1)->parent->id == 0);
    REQUIRE((modules+1)->left->id == 3);
    REQUIRE((modules+1)->right->id == 4);

    REQUIRE((modules+2)->parent == nullptr);
    REQUIRE((modules+2)->left == nullptr);
    REQUIRE((modules+2)->right == nullptr);

    REQUIRE((modules+3)->parent->id == 1);
    REQUIRE((modules+3)->left == nullptr);
    REQUIRE((modules+3)->right == nullptr);

    REQUIRE((modules+4)->parent->id == 1);
    REQUIRE((modules+4)->left == nullptr);
    REQUIRE((modules+4)->right == nullptr);

    REQUIRE((modules+5)->parent->id == 0);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);
  }

  SUBCASE("node has two children") {
  
    tester.delete_node((modules+1));

    bool result;
    REQUIRE((modules+0)->parent == nullptr);
    result = ((modules+0)->left->id == 3) || ((modules+0)->left->id == 4);
    REQUIRE(result == true);
    REQUIRE((modules+0)->right->id == 2);

    REQUIRE((modules+1)->parent == nullptr);
    REQUIRE((modules+1)->left == nullptr);
    REQUIRE((modules+1)->right == nullptr);

    REQUIRE((modules+2)->parent->id == 0);
    REQUIRE((modules+2)->left->id == 5);
    REQUIRE((modules+2)->right == nullptr);

    result = ((modules+3)->parent->id == 0) || ((modules+3)->parent->id == 4);
    REQUIRE(result == true);
    REQUIRE((modules+3)->left == nullptr);
    result = ((modules+3)->right == nullptr) || ((modules+3)->right->id == 4);
    REQUIRE(result == true);

    result = ((modules+4)->parent->id == 0) || ((modules+4)->parent->id == 3);
    REQUIRE(result == true);
    result = ((modules+4)->left == nullptr) || ((modules+4)->left->id == 3);
    REQUIRE(result == true);
    REQUIRE((modules+4)->right == nullptr);

    REQUIRE((modules+5)->parent->id == 2);
    REQUIRE((modules+5)->left == nullptr);
    REQUIRE((modules+5)->right == nullptr);

  }
}

