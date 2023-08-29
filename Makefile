
create_tests:
	clang++ tests/data_structure_tests.c++ -o objects/tests

run_tests : objects/tests
	./objects/tests