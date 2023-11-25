
create_tests:
	clear && clang++ tests/data_structure_tests.c++ -o objects/tests -std=c++17

run_tests:
	clear && ./objects/tests