#include <bstar.hpp>

int main(int argc, char* argv[]) {

  if (argc < 3) {
    std::cerr << "usage: ./bstar input output\n";
    std::exit(EXIT_FAILURE);
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // declare a bstar object
  bstar::BStar obj;

  // read in circuit configurations
  obj.open(input_file);

  // generate optimized floorplan 
  obj.optimize();

  // dump the floorplan to console
  obj.dump(std::cout);

  // dump the floorplan to output
  obj.dump_json(output_file);
  
  return 0;
}
