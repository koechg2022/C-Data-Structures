
#include <iostream>
#include <map>



namespace tests {

    namespace {

        static unsigned int test_count = 0;

        class test {

            private:
                std::string test_name, pass_message, fail_message;
                bool the_test;
                

            public:

                test(std::string test_name = "TEST ", std::string pass = "PASSED", std::string fail = "FAILED", bool condition) {
                    test_count = test_count + 1;
                    if (test_name == "TEST ") {
                        this->test_name = test_name + std::to_string(test_count);
                    }
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
                 * @brief This method updates the name of the test object.
                 * 
                 * @param new_name The new name of the test. The test will be set to have this name.
                 * 
                 * @returns void.
                */
                void update_test_name(std::string new_name) {
                    this->test_name = new_name;
                }

        };

    }


}