if(EXISTS "/home/chiu/bstar_floorplan/build/tests/basics_tests-b858cb2.cmake")
  include("/home/chiu/bstar_floorplan/build/tests/basics_tests-b858cb2.cmake")
else()
  add_test(basics_NOT_BUILT-b858cb2 basics_NOT_BUILT-b858cb2)
endif()