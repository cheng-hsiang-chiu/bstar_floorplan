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
  
  tester.dump(std::cout);
  
  tester.swap_two_nodes(modules[3], modules[1]);
  
  std::cout << "swap two nodes\n";
  
  tester.dump(std::cout);
 
  REQUIRE(1 == 1);
  //REQUIRE((*contour.begin()).second == 0);
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

