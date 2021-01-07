#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bstar_tester.hpp"



TEST_CASE("swap_two_nodes" * doctest::timeout(300)) {
  
  bstar::BStarTester tester;

  tester.open("../../circuits/circuit2.txt");
  tester.generate_initial_tree();
   
  bstar::BNode* modules;

  modules = tester.get_modules();
 
  SUBCASE("swap nodes with the same parent - 1") {

    for (size_t i = 0; i < 6; ++i) {
      std::cout << "modules+" << i << " at " << (modules+i) << '\n'; 
    }

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

  tester.open("../../circuits/circuit2.txt");
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

  SUBCASE("node has two children") {
  
    tester.delete_node((modules+0));

    // node 1 is the new root
    if ((modules+1)->parent == nullptr) {
      if ((modules+1)->left == (modules+3)) {
        REQUIRE((modules+0)->parent == nullptr);
        REQUIRE((modules+0)->left == nullptr);
        REQUIRE((modules+0)->right == nullptr);
        
        REQUIRE((modules+1)->parent == nullptr);
        REQUIRE((modules+1)->left == (modules+3));
        REQUIRE((modules+1)->right == (modules+2));

        REQUIRE((modules+2)->parent == (modules+1));
        REQUIRE((modules+2)->left == (modules+5));
        REQUIRE((modules+2)->right == nullptr);
        
        REQUIRE((modules+3)->parent == (modules+1));
        REQUIRE((modules+3)->left == nullptr);
        REQUIRE((modules+3)->right == (modules+4));
        
        REQUIRE((modules+4)->parent == (modules+3));
        REQUIRE((modules+4)->left == nullptr);
        REQUIRE((modules+4)->right == nullptr);
        
        REQUIRE((modules+5)->parent == (modules+2));
        REQUIRE((modules+5)->left == nullptr);
        REQUIRE((modules+5)->right == nullptr);
      }
      else {
        REQUIRE((modules+0)->parent == nullptr);
        REQUIRE((modules+0)->left == nullptr);
        REQUIRE((modules+0)->right == nullptr);
        
        REQUIRE((modules+1)->parent == nullptr);
        REQUIRE((modules+1)->left == (modules+4));
        REQUIRE((modules+1)->right == (modules+2));

        REQUIRE((modules+2)->parent == (modules+1));
        REQUIRE((modules+2)->left == (modules+5));
        REQUIRE((modules+2)->right == nullptr);
        
        REQUIRE((modules+3)->parent == (modules+4));
        REQUIRE((modules+3)->left == nullptr);
        REQUIRE((modules+3)->right == nullptr);
        
        REQUIRE((modules+4)->parent == (modules+1));
        REQUIRE((modules+4)->left == (modules+3));
        REQUIRE((modules+4)->right == nullptr);
        
        REQUIRE((modules+5)->parent == (modules+2));
        REQUIRE((modules+5)->left == nullptr);
        REQUIRE((modules+5)->right == nullptr);
      }
    }

    // node 2 is the root
    else {
        REQUIRE((modules+0)->parent == nullptr);
        REQUIRE((modules+0)->left == nullptr);
        REQUIRE((modules+0)->right == nullptr);
        
        REQUIRE((modules+1)->parent == (modules+2));
        REQUIRE((modules+1)->left == (modules+3));
        REQUIRE((modules+1)->right == (modules+4));

        REQUIRE((modules+2)->parent == nullptr);
        REQUIRE((modules+2)->left == (modules+1));
        REQUIRE((modules+2)->right == (modules+5));
        
        REQUIRE((modules+3)->parent == (modules+1));
        REQUIRE((modules+3)->left == nullptr);
        REQUIRE((modules+3)->right == nullptr);
        
        REQUIRE((modules+4)->parent == (modules+1));
        REQUIRE((modules+4)->left == nullptr);
        REQUIRE((modules+4)->right == nullptr);
        
        REQUIRE((modules+5)->parent == (modules+2));
        REQUIRE((modules+5)->left == nullptr);
        REQUIRE((modules+5)->right == nullptr);
    }
  }
}



TEST_CASE("deep_copy" * doctest::timeout(300)) {

  bstar::BStarTester tester;

  tester.open("../../circuits/circuit2.txt");
  tester.generate_initial_tree();

  //bstar::BNode* modules;
  
  //modules = tester.get_modules();

  SUBCASE("deep copy") {
    std::vector<bstar::BNode> source;
    std::vector<bstar::BNode> destination;

    for (size_t i = 0; i < 6; ++i) {
      bstar::BNode node;
      node.id = i;
      source.push_back(node);
    }

    source[0].left = &source[1];
    source[0].right = &source[2];
    source[1].parent = &source[0];
    source[1].left = &source[3];
    source[1].right = &source[4];
    source[2].parent = &source[0];
    source[2].left = &source[5];
    source[3].parent = &source[1];
    source[4].parent = &source[1];
    source[5].parent = &source[2];

    std::cout << "shallow copy \n";

    destination = source;
    
    for (size_t i = 0; i < 6; ++i) {
      std::cout << source[i].id << " at " << &source[i];
      if (source[i].parent)
        std::cout << " has parent at " << source[i].parent << " which has id " << source[i].parent->id;
      if (source[i].left)
        std::cout << " has left at " << source[i].left << " which has id " << source[i].left->id;
      if (source[i].right)
        std::cout << " has right at " << source[i].right << " which has id " << source[i].right->id;
      std::cout << '\n';
    }

    for (size_t i = 0; i < 6; ++i) {
      std::cout << destination[i].id << " at " << &destination[i];
      if (destination[i].parent)
        std::cout << " has parent at " << destination[i].parent << " which has id " << source[i].parent->id;
      if (destination[i].left)
        std::cout << " has left at " << destination[i].left << " which has id " << source[i].left->id;
      if (destination[i].right)
        std::cout << " has right at " << destination[i].right << " which has id " << source[i].right->id;
      std::cout << '\n';
    }

    REQUIRE(source[0].id == destination[0].id);
    REQUIRE(source[0].left->id == destination[0].left->id);
    REQUIRE(source[0].right->id == destination[0].right->id);

    REQUIRE(source[1].id == destination[1].id);
    REQUIRE(source[1].parent->id == destination[1].parent->id);
    REQUIRE(source[1].left->id == destination[1].left->id);
    REQUIRE(source[1].right->id == destination[1].right->id);
    
    REQUIRE(source[2].id == destination[2].id);
    REQUIRE(source[2].parent->id == destination[2].parent->id);
    REQUIRE(source[2].left->id == destination[2].left->id);
   
    REQUIRE(source[3].id == destination[3].id);
    REQUIRE(source[3].parent->id == destination[3].parent->id);
    
    REQUIRE(source[4].id == destination[4].id);
    REQUIRE(source[4].parent->id == destination[4].parent->id);
    
    REQUIRE(source[5].id == destination[5].id);
    REQUIRE(source[5].parent->id == destination[5].parent->id);
    
    REQUIRE(&source[0] != &destination[0]);
    REQUIRE(source[0].parent == nullptr);
    REQUIRE(destination[0].parent == nullptr);
    REQUIRE(source[0].left == destination[0].left);
    REQUIRE(source[0].right == destination[0].right);

    REQUIRE(&source[1] != &destination[1]);
    REQUIRE(source[1].parent == destination[1].parent);
    REQUIRE(source[1].left == destination[1].left);
    REQUIRE(source[1].right == destination[1].right);
    
    REQUIRE(&source[2] != &destination[2]);
    REQUIRE(source[2].parent == destination[2].parent);
    REQUIRE(source[2].left == destination[2].left);
    REQUIRE(source[2].right == nullptr);
    REQUIRE(destination[2].right == nullptr);
   
    REQUIRE(&source[3] != &destination[3]);
    REQUIRE(source[3].parent == destination[3].parent);
    REQUIRE(source[3].left == nullptr);
    REQUIRE(source[3].right == nullptr);
    REQUIRE(destination[3].left == nullptr);
    REQUIRE(destination[3].right == nullptr);
    
    REQUIRE(&source[4] != &destination[4]);
    REQUIRE(source[4].parent == destination[4].parent);
    REQUIRE(source[4].left == nullptr);
    REQUIRE(source[4].right == nullptr);
    REQUIRE(destination[4].left == nullptr);
    REQUIRE(destination[4].right == nullptr);

    REQUIRE(&source[5] != &destination[5]);
    REQUIRE(source[5].parent == destination[5].parent);
    REQUIRE(source[5].left == nullptr);
    REQUIRE(source[5].right == nullptr);
    REQUIRE(destination[5].left == nullptr);
    REQUIRE(destination[5].right == nullptr);

    tester.deep_copy_modules(source, destination);

    std::cout << "deep copy \n";

    for (size_t i = 0; i < 6; ++i) {
      std::cout << source[i].id << " at " << &source[i];
      if (source[i].parent)
        std::cout << " has parent at " << source[i].parent << " which has id " << source[i].parent->id;
      if (source[i].left)
        std::cout << " has left at " << source[i].left << " which has id " << source[i].left->id;
      if (source[i].right)
        std::cout << " has right at " << source[i].right << " which has id " << source[i].right->id;
      std::cout << '\n';
    }

    for (size_t i = 0; i < 6; ++i) {
      std::cout << destination[i].id << " at " << &destination[i];
      if (destination[i].parent)
        std::cout << " has parent at " << destination[i].parent<< " which has id " << source[i].parent->id;
      if (destination[i].left)
        std::cout << " has left at " << destination[i].left << " which has id " << source[i].left->id;
      if (destination[i].right)
        std::cout << " has right at " << destination[i].right << " which has id " << source[i].right->id;
      std::cout << '\n';
    }

    REQUIRE(source[0].id == destination[0].id);
    REQUIRE(source[0].left->id == destination[0].left->id);
    REQUIRE(source[0].right->id == destination[0].right->id);

    REQUIRE(source[1].id == destination[1].id);
    REQUIRE(source[1].parent->id == destination[1].parent->id);
    REQUIRE(source[1].left->id == destination[1].left->id);
    REQUIRE(source[1].right->id == destination[1].right->id);
    
    REQUIRE(source[2].id == destination[2].id);
    REQUIRE(source[2].parent->id == destination[2].parent->id);
    REQUIRE(source[2].left->id == destination[2].left->id);
   
    REQUIRE(source[3].id == destination[3].id);
    REQUIRE(source[3].parent->id == destination[3].parent->id);
    
    REQUIRE(source[4].id == destination[4].id);
    REQUIRE(source[4].parent->id == destination[4].parent->id);
    
    REQUIRE(source[5].id == destination[5].id);
    REQUIRE(source[5].parent->id == destination[5].parent->id);
    
    REQUIRE(&source[0] != &destination[0]);
    REQUIRE(source[0].parent == nullptr);
    REQUIRE(destination[0].parent == nullptr);
    REQUIRE(source[0].left != destination[0].left);
    REQUIRE(source[0].right != destination[0].right);

    REQUIRE(&source[1] != &destination[1]);
    REQUIRE(source[1].parent != destination[1].parent);
    REQUIRE(source[1].left != destination[1].left);
    REQUIRE(source[1].right != destination[1].right);
    
    REQUIRE(&source[2] != &destination[2]);
    REQUIRE(source[2].parent != destination[2].parent);
    REQUIRE(source[2].left != destination[2].left);
    REQUIRE(source[2].right == nullptr);
    REQUIRE(destination[2].right == nullptr);
   
    REQUIRE(&source[3] != &destination[3]);
    REQUIRE(source[3].parent != destination[3].parent);
    REQUIRE(source[3].left == nullptr);
    REQUIRE(source[3].right == nullptr);
    REQUIRE(destination[3].left == nullptr);
    REQUIRE(destination[3].right == nullptr);
    
    REQUIRE(&source[4] != &destination[4]);
    REQUIRE(source[4].parent != destination[4].parent);
    REQUIRE(source[4].left == nullptr);
    REQUIRE(source[4].right == nullptr);
    REQUIRE(destination[4].left == nullptr);
    REQUIRE(destination[4].right == nullptr);

    REQUIRE(&source[5] != &destination[5]);
    REQUIRE(source[5].parent != destination[5].parent);
    REQUIRE(source[5].left == nullptr);
    REQUIRE(source[5].right == nullptr);
    REQUIRE(destination[5].left == nullptr);
    REQUIRE(destination[5].right == nullptr);
  }

}

TEST_CASE("rotate_module" * doctest::timeout(300)) {

  bstar::BStarTester tester;

  tester.open("../../circuits/circuit2.txt");
  tester.generate_initial_tree();

  bstar::BNode* modules;
  
  modules = tester.get_modules();

  SUBCASE("rotate 0") {
    size_t original_width = (modules+0)->width;
    size_t original_height = (modules+0)->height;

    tester.rotate_module(modules+0);

    REQUIRE((modules+0)->id == 0);
    REQUIRE((modules+0)->parent == nullptr);
    REQUIRE((modules+0)->left->id == 1);
    REQUIRE((modules+0)->right->id == 2);
    REQUIRE((modules+0)->width == original_height);
    REQUIRE((modules+0)->height == original_width);
  }
}


TEST_CASE("delete_and_insert" * doctest::timeout(300)) {

  bstar::BStarTester tester;

  std::vector<bstar::BNode> modules;

  for (size_t i = 0; i < 6; ++i) {
    bstar::BNode node;
    node.id = i;
    modules.push_back(node);
  }

  modules[0].left = &modules[1];
  modules[0].right = &modules[2];
  modules[1].parent = &modules[0];
  modules[1].left = &modules[3];
  modules[1].right = &modules[4];
  modules[2].parent = &modules[0];
  modules[2].left = &modules[5];
  modules[3].parent = &modules[1];
  modules[4].parent = &modules[1];
  modules[5].parent = &modules[2];
   
  SUBCASE("delete_and_insert 0") {
    tester.delete_node(&modules[0]);

    // node 1 is the new root
    if ((modules[1].parent == nullptr)) {
      if (modules[1].left == &modules[3]) {
        tester.insert_node(&modules[0], modules);
        if (modules[0].parent == &modules[3]) {
          REQUIRE(modules[0].parent == &modules[3]);
          REQUIRE(modules[0].left == nullptr);
          REQUIRE(modules[0].right == nullptr);
          
          REQUIRE(modules[1].parent == nullptr);
          REQUIRE(modules[1].left == &modules[3]);
          REQUIRE(modules[1].right == &modules[2]);
          
          REQUIRE(modules[2].parent == &modules[1]);
          REQUIRE(modules[2].left == &modules[5]);
          REQUIRE(modules[2].right == nullptr);
          
          REQUIRE(modules[3].parent == &modules[1]);
          REQUIRE(modules[3].left == &modules[0]);
          REQUIRE(modules[3].right == &modules[4]);
          
          REQUIRE(modules[4].parent == &modules[3]);
          REQUIRE(modules[4].left == nullptr);
          REQUIRE(modules[4].right == nullptr);
          
          REQUIRE(modules[5].parent == &modules[2]);
          REQUIRE(modules[5].left == nullptr);
          REQUIRE(modules[5].right == nullptr);
        }
        else if (modules[0].parent == &modules[4]) {
          REQUIRE(modules[0].parent == &modules[4]);
          REQUIRE(modules[0].left == nullptr);
          REQUIRE(modules[0].right == nullptr);
          
          REQUIRE(modules[1].parent == nullptr);
          REQUIRE(modules[1].left == &modules[3]);
          REQUIRE(modules[1].right == &modules[2]);
          
          REQUIRE(modules[2].parent == &modules[1]);
          REQUIRE(modules[2].left == &modules[5]);
          REQUIRE(modules[2].right == nullptr);
          
          REQUIRE(modules[3].parent == &modules[1]);
          REQUIRE(modules[3].left == nullptr);
          REQUIRE(modules[3].right == &modules[4]);
          
          REQUIRE(modules[4].parent == &modules[3]);
          if (modules[4].left == nullptr)
            REQUIRE(modules[4].right == &modules[3]);
          else
            REQUIRE(modules[4].left == &modules[3]);
          
          REQUIRE(modules[5].parent == &modules[2]);
          REQUIRE(modules[5].left == nullptr);
          REQUIRE(modules[5].right == nullptr);
        }
        else if (modules[0].parent == &modules[2]) {
          REQUIRE(modules[0].parent == &modules[2]);
          REQUIRE(modules[0].left == nullptr);
          REQUIRE(modules[0].right == nullptr);
          
          REQUIRE(modules[1].parent == nullptr);
          REQUIRE(modules[1].left == &modules[3]);
          REQUIRE(modules[1].right == &modules[2]);
          
          REQUIRE(modules[2].parent == &modules[1]);
          REQUIRE(modules[2].left == &modules[5]);
          REQUIRE(modules[2].right == &modules[0]);
          
          REQUIRE(modules[3].parent == &modules[1]);
          REQUIRE(modules[3].left == nullptr);
          REQUIRE(modules[3].right == &modules[4]);
          
          REQUIRE(modules[4].parent == &modules[3]);
          REQUIRE(modules[4].left == nullptr);
          REQUIRE(modules[4].right == nullptr);
          
          REQUIRE(modules[5].parent == &modules[2]);
          REQUIRE(modules[5].left == nullptr);
          REQUIRE(modules[5].right == nullptr);
        }
        else if (modules[0].parent == &modules[5]) {
          REQUIRE(modules[0].parent == &modules[5]);
          REQUIRE(modules[0].left == nullptr);
          REQUIRE(modules[0].right == nullptr);
          
          REQUIRE(modules[1].parent == nullptr);
          REQUIRE(modules[1].left == &modules[3]);
          REQUIRE(modules[1].right == &modules[2]);
          
          REQUIRE(modules[2].parent == &modules[1]);
          REQUIRE(modules[2].left == &modules[5]);
          REQUIRE(modules[2].right == nullptr);
          
          REQUIRE(modules[3].parent == &modules[1]);
          REQUIRE(modules[3].left == nullptr);
          REQUIRE(modules[3].right == &modules[4]);
          
          REQUIRE(modules[4].parent == &modules[3]);
          REQUIRE(modules[4].left == nullptr);
          REQUIRE(modules[4].right == nullptr);
          
          REQUIRE(modules[5].parent == &modules[2]);
          if (modules[5].left == nullptr)
            REQUIRE(modules[5].right == &modules[0]);
          else
            REQUIRE(modules[5].left == &modules[0]);
        }
      }
      
      else {
        tester.insert_node(&modules[0], modules);
        if (modules[0].parent == &modules[3]) {
          REQUIRE(modules[0].parent == &modules[3]);
          REQUIRE(modules[0].left == nullptr);
          REQUIRE(modules[0].right == nullptr);
          
          REQUIRE(modules[1].parent == nullptr);
          REQUIRE(modules[1].left == &modules[4]);
          REQUIRE(modules[1].right == &modules[2]);
          
          REQUIRE(modules[2].parent == &modules[1]);
          REQUIRE(modules[2].left == &modules[5]);
          REQUIRE(modules[2].right == nullptr);
          
          REQUIRE(modules[3].parent == &modules[4]);
          if (modules[3].left == nullptr)
            REQUIRE(modules[3].right == &modules[0]);
          else
            REQUIRE(modules[3].left == &modules[0]);
          
          REQUIRE(modules[4].parent == &modules[1]);
          REQUIRE(modules[4].left == &modules[3]);
          REQUIRE(modules[4].right == nullptr);
          
          REQUIRE(modules[5].parent == &modules[2]);
          REQUIRE(modules[5].left == nullptr);
          REQUIRE(modules[5].right == nullptr);
        }
        else if (modules[0].parent == &modules[4]) {
          REQUIRE(modules[0].parent == &modules[4]);
          REQUIRE(modules[0].left == nullptr);
          REQUIRE(modules[0].right == nullptr);
          
          REQUIRE(modules[1].parent == nullptr);
          REQUIRE(modules[1].left == &modules[4]);
          REQUIRE(modules[1].right == &modules[2]);
          
          REQUIRE(modules[2].parent == &modules[1]);
          REQUIRE(modules[2].left == &modules[5]);
          REQUIRE(modules[2].right == nullptr);
          
          REQUIRE(modules[3].parent == &modules[4]);
          REQUIRE(modules[3].left == nullptr);
          REQUIRE(modules[3].right == nullptr);
          
          REQUIRE(modules[4].parent == &modules[1]);
          REQUIRE(modules[4].left == &modules[3]);
          REQUIRE(modules[4].right == &modules[0]);
          
          REQUIRE(modules[5].parent == &modules[2]);
          REQUIRE(modules[5].left == nullptr);
          REQUIRE(modules[5].right == nullptr);
        }
        else if (modules[0].parent == &modules[2]) {
          REQUIRE(modules[0].parent == &modules[2]);
          REQUIRE(modules[0].left == nullptr);
          REQUIRE(modules[0].right == nullptr);
          
          REQUIRE(modules[1].parent == nullptr);
          REQUIRE(modules[1].left == &modules[4]);
          REQUIRE(modules[1].right == &modules[2]);
          
          REQUIRE(modules[2].parent == &modules[1]);
          REQUIRE(modules[2].left == &modules[5]);
          REQUIRE(modules[2].right == &modules[0]);
          
          REQUIRE(modules[3].parent == &modules[4]);
          REQUIRE(modules[3].left == nullptr);
          REQUIRE(modules[3].right == nullptr);
          
          REQUIRE(modules[4].parent == &modules[1]);
          REQUIRE(modules[4].left == &modules[3]);
          REQUIRE(modules[4].right == nullptr);
          
          REQUIRE(modules[5].parent == &modules[2]);
          REQUIRE(modules[5].left == nullptr);
          REQUIRE(modules[5].right == nullptr);
        }
        else {
          REQUIRE(modules[0].parent == &modules[5]);
          REQUIRE(modules[0].left == nullptr);
          REQUIRE(modules[0].right == nullptr);
          
          REQUIRE(modules[1].parent == nullptr);
          REQUIRE(modules[1].left == &modules[4]);
          REQUIRE(modules[1].right == &modules[2]);
          
          REQUIRE(modules[2].parent == &modules[1]);
          REQUIRE(modules[2].left == &modules[5]);
          REQUIRE(modules[2].right == nullptr);
          
          REQUIRE(modules[3].parent == &modules[4]);
          REQUIRE(modules[3].left == nullptr);
          REQUIRE(modules[3].right == nullptr);
          
          REQUIRE(modules[4].parent == &modules[1]);
          REQUIRE(modules[4].left == &modules[3]);
          REQUIRE(modules[4].right == nullptr);
          
          REQUIRE(modules[5].parent == &modules[2]);
          if (modules[5].left == nullptr)
            REQUIRE(modules[5].right == &modules[0]);
          else
            REQUIRE(modules[5].left == &modules[0]);
        }
      }
    }
    
    // node 2 is the root
    else {
      tester.insert_node(&modules[0], modules);
      if (modules[0].parent == &modules[3]) {
        REQUIRE(modules[0].parent == &modules[3]);
        REQUIRE(modules[0].left == nullptr);
        REQUIRE(modules[0].right == nullptr);
         
        REQUIRE(modules[1].parent == &modules[2]);
        REQUIRE(modules[1].left == &modules[3]);
        REQUIRE(modules[1].right == &modules[4]);
          
        REQUIRE(modules[2].parent == nullptr);
        REQUIRE(modules[2].left == &modules[1]);
        REQUIRE(modules[2].right == &modules[5]);
          
        REQUIRE(modules[3].parent == &modules[1]);
        if (modules[3].left == nullptr)
          REQUIRE(modules[3].right == &modules[0]);
        else
          REQUIRE(modules[3].left == &modules[0]);
          
        REQUIRE(modules[4].parent == &modules[1]);
        REQUIRE(modules[4].left == nullptr);
        REQUIRE(modules[4].right == nullptr);
          
        REQUIRE(modules[5].parent == &modules[2]);
        REQUIRE(modules[5].left == nullptr);
        REQUIRE(modules[5].right == nullptr);
      }
      else if (modules[0].parent == &modules[4]){
        REQUIRE(modules[0].parent == &modules[4]);
        REQUIRE(modules[0].left == nullptr);
        REQUIRE(modules[0].right == nullptr);
         
        REQUIRE(modules[1].parent == &modules[2]);
        REQUIRE(modules[1].left == &modules[3]);
        REQUIRE(modules[1].right == &modules[4]);
          
        REQUIRE(modules[2].parent == nullptr);
        REQUIRE(modules[2].left == &modules[1]);
        REQUIRE(modules[2].right == &modules[5]);
          
        REQUIRE(modules[3].parent == &modules[1]);
        REQUIRE(modules[3].left == nullptr);
        REQUIRE(modules[3].right == nullptr);
          
        REQUIRE(modules[4].parent == &modules[1]);
        if (modules[4].left == nullptr)
          REQUIRE(modules[4].right == &modules[0]);
        else
          REQUIRE(modules[4].left == &modules[0]);
          
        REQUIRE(modules[5].parent == &modules[2]);
        REQUIRE(modules[5].left == nullptr);
        REQUIRE(modules[5].right == nullptr);
      }
      else {
        REQUIRE(modules[0].parent == &modules[5]);
        REQUIRE(modules[0].left == nullptr);
        REQUIRE(modules[0].right == nullptr);
         
        REQUIRE(modules[1].parent == &modules[2]);
        REQUIRE(modules[1].left == &modules[3]);
        REQUIRE(modules[1].right == &modules[4]);
          
        REQUIRE(modules[2].parent == nullptr);
        REQUIRE(modules[2].left == &modules[1]);
        REQUIRE(modules[2].right == &modules[5]);
          
        REQUIRE(modules[3].parent == &modules[1]);
        REQUIRE(modules[3].left == nullptr);
        REQUIRE(modules[3].right == nullptr);
          
        REQUIRE(modules[4].parent == &modules[1]);
        REQUIRE(modules[4].left == nullptr);
        REQUIRE(modules[4].right == nullptr);
          
        REQUIRE(modules[5].parent == &modules[2]);
        if (modules[5].left == nullptr)
          REQUIRE(modules[5].right == &modules[0]);
        else
          REQUIRE(modules[5].left == &modules[0]);
      }
    }
  }
  
}
