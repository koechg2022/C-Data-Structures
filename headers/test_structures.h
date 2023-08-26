
#include <iostream>
#include <map>




namespace tests {

    namespace {

        class test {

            private:
                std::string test_name, pass_message, fail_message;
                bool the_test;

            public:

                test(std::string test_name = "TEST ", std::string pass = "PASSED", std::string fail = "FAILED", bool condition) {
                    this->test_name = test_name;
                    this->pass_message = pass;
                    this->fail_message = fail;
                    this->the_test = condition;
                }

                /**
                 * @brief This updates message of the test.
                 * This method updates the pass message of the test object (if the test is passed)
                 * or the fail message of the test object (if the test is failed).
                 * 
                 * @param new_message The new message for the relevant (pass or fail) message of this test.
                 * 
                 * @returns void.
                */
                void update_message(std::string new_message) {
                    if (this->the_test) {
                        this->pass_message = new_message;
                    }
                    else {
                        this->fail_message = new_message;
                    }
                }

                /**
                 * @brief Get the message that corresponds to the condition.
                 * 
                 * @returns The string that corresponnds to the message matching the condition passed in.
                */
                std::string get_message() const {
                    if (this->the_test) {
                        return this->pass_message;
                    }
                    return this->fail_message;
                }

                /**
                 * @brief This method updates the name of the test object.
                 * 
                 * @param new_name The new name of the test. The test will be set to have this name.
                 * 
                 * @returns void.
                */
                void update_test_name(std::string new_name) {
                    this->test_name = new_name;
                }

                /**
                 * @brief Get the name of the test.
                 * 
                 * @returns The name of the test.
                 * 
                 * @note Constant method.
                */
                std::string get_test_name() const {
                    return this->test_name;
                }

                /**
                 * @brief Change the condition of this test.
                 * @returns void.
                */
                void update_condition(bool new_condition) {
                    this->the_test = new_condition;
                }

                /**
                 * @brief Get the condition of the test.
                 * 
                 * @returns The condition of the test.
                */
                bool get_condition() const {
                    return this->the_test;
                }

                /**
                 * @brief Update the message to be displayed when the test passes.
                 * 
                 * @returns void.
                */
                void update_pass_message(std::string new_message) {
                    this->pass_message = new_message;
                }

                /**
                 * @brief Get the message associated with a passing test.
                 * 
                 * @returns The string associated with a passing test.
                */
                std::string get_pass_message() const {
                    return this->pass_message;
                }

                /**
                 * @brief Change the message associated with a failing test.
                 * 
                 * @returns void.
                */
                void update_fail_message(std::string new_message) {
                    this->fail_message = new_message;
                }

                /**
                 * @brief Get the message associated with a failing test.
                 * 
                 * @returns The message associated with a failing test.
                */
                std::string get_fail_message() const {
                    return this->fail_message;
                }

        };
    }


    class tests {

        private:
            std::map<std::string, test> the_tests;
            bool contains(std::string name) {
                return this->the_tests.find(name) != this->the_tests.end();
            }
        
        public:

            tests() {}

            tests(std::string name, bool condition, std::string pass, std::string fail) {
                test new_test = test(name, pass, fail, condition);
                this->the_tests.insert({name, new_test});
            }

            /**
             * @brief Add a new test to the tests.
             * 
             * @param name The name of the test. Defaults to "TEST "
             * @param pass The pass message for the test being added. Defaults to "PASSED".
             * @param fail The fail message for the test being added. Defaults to "FAILED".
             * @param condition Not defaulted. Must be filled in. The condition of the test. Determines if a test is passed or failed.
             * 
             * @returns null.
            */
            void add_test(std::string name = "TEST ", std::string pass = "PASSED", std::string fail = "FAILED", bool condition) {
                if (name == "TEST ") {
                    name = name + std::to_string(the_tests.size());
                }
                if (!this->contains(name)) {
                    test new_test = test(name, pass, fail, condition);
                    this->the_tests.insert({ name, new_test});
                }
            }



    };


}