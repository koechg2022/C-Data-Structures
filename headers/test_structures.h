
#include <iostream>
#include <map>



namespace tests {

    namespace {

        // TEXT COLORS
        #define black_text 30
        #define red_text 31
        #define green_text 32
        #define yellow_text 33
        #define blue_text 34
        #define purple_text 35
        #define cyan_text 36
        #define white_text 37




        // TEXT STYLE
        #define no_effect_style 0
        #define bold_style 1
        #define underline_style 2
        #define negative_1_style 3
        #define negative_2_style 5




        // BACKGROUND COLOR
        #define black_background 40
        #define red_background 41
        #define green_background 42
        #define yellow_background 43
        #define blue_background 44
        #define purple_background 45
        #define cyan_background 46
        #define white_background 47
        #define default_background 49

        typedef unsigned short int short_int;

        const std::string ansi_escape = "\033[";
        // "\033[<style>;<color>;<bkg>m<the_string>\033[0m"

        bool valid_color(short_int color) {
            return ((color >= (short_int) black_text) && (color <= (short_int) white_text));
        }

        bool valid_style(short_int style) {
            return (((style >= (short_int) no_effect_style) && (style <= (short_int) negative_1_style)) || (style == (short_int) negative_2_style));
        }

        bool valid_bkg(short_int bkg) {
            return ((bkg >= (short_int) black_background) && (bkg <= (short_int) default_background));
        }

        std::string get_styled_string(std::string the_string, short_int style = (short_int) no_effect_style, short_int color = (short_int) black_text, short_int bkg = (short_int) default_background) {
            style = (valid_style((short_int) style)) ? (short_int) style : (short_int) no_effect_style;
            color = (valid_color((short_int) color)) ? (short_int) color : (short_int) black_text;
            bkg = (valid_bkg((short_int) bkg)) ? (short_int) bkg : (short_int) default_background;
            return "\033[" + std::to_string(int(style)) + ";" + std::to_string(int(color)) + ";" + std::to_string(int(bkg)) + "m" + the_string + "\033[0m";
        }

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
            unsigned long passed_tests, total_tests;
            bool contains(std::string name) {
                return this->the_tests.find(name) != this->the_tests.end();
            }

        public:

            tests() {
                passed_tests = total_tests = 0;
            }

            tests(std::string name, bool condition, std::string pass, std::string fail) {
                test new_test = test(name, pass, fail, condition);
                this->the_tests.insert({name, new_test});
                passed_tests = (condition) ? 1 : 0;
                total_tests = 1;
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
                    name = name + std::to_string(the_tests.size() + 1);
                }
                if (!this->contains(name)) {
                    test new_test = test(name, pass, fail, condition);
                    this->the_tests.insert({ name, new_test});
                    this->passed_tests = (condition) ? this->passed_tests + 1 : this->passed_tests;
                    this->total_tests = this->total_tests + 1;
                }
            }

            void print_all_tests() const {
                // std::string final_message = std::to_string(this->passed_tests) + " / " + std::to_string(this->total_tests);
                for (const auto& entry : this->the_tests) {
                    std::string colored_message = get_styled_string(entry.second.get_message(), (unsigned short int) bold_style, (unsigned short int)((entry.second.get_condition()) ? green_text : red_text), (unsigned short int) default_background);
                    std::cout << "\t" << entry.first << ":\t" << colored_message << std::endl;
                }
                std::cout << get_styled_string(std::to_string(this->passed_tests) + " / " + std::to_string(this->total_tests), (unsigned short int) bold_style, (unsigned short int)((this->passed_tests == this->total_tests) ? green_text : red_text), (unsigned short int) default_background) << std::endl;
            }

    };


}