#include "../src/bstar.hpp"

namespace bstar{


class BStarTester {
  public:
    BStarTester();

    void update_contour(BNode* node_ptr);

    std::vector<BNode*> get_contour() const;
    BNode* get_modules();
    
    void open(const std::string input_file); 
    void dump(std::ostream& os);
    void swap_two_nodes(BNode* node1, BNode* node2);
    void generate_initial_tree();
    void delete_node(BNode* node_ptr);
    void insert_node(BNode* target, std::vector<BNode>& modules);
    void dump_modules(const std::vector<BNode> modules) const;
    void deep_copy_modules(std::vector<BNode>& source,
                           std::vector<BNode>& destination);               
    void rotate_module(BNode* node);

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


BNode* BStarTester::get_modules(){
  return &(bs._modules_curr[0]);
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


void BStarTester::deep_copy_modules(
  std::vector<BNode>& source, std::vector<BNode>& destination) {
  
  bs._deep_copy_modules(source, destination);                                  
}


void BStarTester::rotate_module(BNode* node) {
  bs._rotate_module(node);
}


}
