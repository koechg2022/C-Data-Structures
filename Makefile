
create_tests_17:
	clear && clang++ tests/data_structure_tests.c++ -o objects/tests -std=c++17

create_tests_20:
	clear && clang++ tests/data_structure_tests.c++ -o objects/tests -std=c++20

run_tests:
	clear && ./objects/tests
