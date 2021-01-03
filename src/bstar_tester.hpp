#include "../src/bstar.hpp"

namespace bstar{


class BStarTester {
  public:
    BStarTester();

    void update_contour_after_insertion(
      const std::shared_ptr<BNode> node);

    std::vector<std::shared_ptr<BNode>> get_contour() const;
    std::vector<std::shared_ptr<BNode>> get_modules() const;
    void open(const std::string input_file); 
    void dump(std::ostream& os);
    void swap_two_nodes(
      std::shared_ptr<BNode> node1,
      std::shared_ptr<BNode> node2);
    void generate_initial_tree();
    void delete_and_insert(
      std::shared_ptr<BNode> node);
        
    BStar bs;
    std::vector<int> contour;
};


BStarTester::BStarTester() {
  std::cout << "bstar tester constructor\n";
}


void BStarTester::update_contour_after_insertion(
  const std::shared_ptr<BNode> node) {
  bs._update_contour_after_insertion(node, true);
}


void BStarTester::open(const std::string input_file) {
  std::cout << "bstar tester open\n";
  bs.open(input_file);
}


std::vector<std::shared_ptr<BNode>> BStarTester::get_contour() const {
  return bs._contour;
}


std::vector<std::shared_ptr<BNode>> BStarTester::get_modules() const {
  return bs._modules;
}


void BStarTester::dump(std::ostream& os){
  bs.dump(os);
}

void BStarTester::swap_two_nodes(
  std::shared_ptr<BNode> node1,
  std::shared_ptr<BNode> node2){
  bs._swap_two_nodes(node1, node2); 
}


void BStarTester::generate_initial_tree() {
  bs._generate_initial_tree();
}


void BStarTester::delete_and_insert(
  std::shared_ptr<BNode> node){
  bs._delete_and_insert(node);
}


}
