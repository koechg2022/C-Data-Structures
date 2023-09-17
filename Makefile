
create_tests:
	clang++ tests/data_structure_tests.c++ -o objects/tests -std=c++14

create_debug_tests:
	clang++ tests/data_structure_tests.c++ -o objects/tests -g

run_debug_tests:
	gdb objects/tests

run_tests : create_tests
	./objects/tests

run_tests_all : create_tests
	./objects/tests --all

run_tests_only_fails: create_tests
	./objects/tests --toprint true

run_tests_not_only_fails: create_tests
	./objects/tests --toprint false