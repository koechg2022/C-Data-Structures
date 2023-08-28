
create_test:
	clang++ tests/data_structures.c++ -o objects/tests

run_tests : objects/tests
	./objects/tests