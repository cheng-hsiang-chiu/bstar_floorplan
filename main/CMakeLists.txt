
## --------------------------------------------------------
## main program 1: floorplan
## --------------------------------------------------------
add_executable(bsfp main.cpp)
target_link_libraries(bsfp error_settings)
target_include_directories(bsfp PRIVATE ${BSFP_SRC_DIR})
