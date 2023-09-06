
#include <iostream>
#include <map>

#ifndef useful_functions_h

#include "useful_functions.h"

#endif



namespace test_stuff {

    namespace {

        // // TEXT COLORS
        // #define black_text 30
        // #define red_text 31
        // #define green_text 32
        // #define yellow_text 33
        // #define blue_text 34
        // #define purple_text 35
        // #define cyan_text 36
        // #define white_text 37




        // // TEXT STYLE
        // #define no_effect_style 0
        // #define bold_style 1
        // #define underline_style 2
        // #define negative_1_style 3
        // #define negative_2_style 5




        // // BACKGROUND COLOR
        // #define black_background 40
        // #define red_background 41
        // #define green_background 42
        // #define yellow_background 43
        // #define blue_background 44
        // #define purple_background 45
        // #define cyan_background 46
        // #define white_background 47
        // #define default_background 49

        // typedef unsigned short int short_int;

        // // const std::string ansi_escape = "\033[";
        // // "\033[<style>;<color>;<bkg>m<the_string>\033[0m"

        // bool valid_color(short_int color) {
        //     return ((color >= (short_int) black_text) && (color <= (short_int) white_text));
        // }

        // bool valid_style(short_int style) {
        //     return (((style >= (short_int) no_effect_style) && (style <= (short_int) negative_1_style)) || (style == (short_int) negative_2_style));
        // }

        // bool valid_bkg(short_int bkg) {
        //     return ((bkg >= (short_int) black_background) && (bkg <= (short_int) default_background));
        // }

        // std::string get_styled_string(std::string the_string, short_int style = (short_int) no_effect_style, short_int color = (short_int) black_text, short_int bkg = (short_int) default_background) {
        //     style = (valid_style((short_int) style)) ? (short_int) style : (short_int) no_effect_style;
        //     color = (valid_color((short_int) color)) ? (short_int) color : (short_int) black_text;
        //     bkg = (valid_bkg((short_int) bkg)) ? (short_int) bkg : (short_int) default_background;
        //     return "\033[" + std::to_string(int(style)) + ";" + std::to_string(int(color)) + ";" + std::to_string(int(bkg)) + "m" + the_string + "\033[0m";
        // }


        class test {

            private:
                std::string pass_message, fail_message;
                bool the_test;


            public:

                test() {
                    this->pass_message = "PASSED";
                    this->fail_message = "FAILED";
                    this->the_test = true;
                }

                test(bool condition, std::string pass = "PASSED", std::string fail = "FAILED") {
                    // this->test_name = test_name;
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


        class test_group {

            private:

                std::map<std::string, test> the_tests;
                std::string group_name;
                unsigned long passed_tests, total_tests;
                bool contains(std::string test_name) {
                    return this->the_tests.find(test_name) != this->the_tests.end();
                }

            public:

                test_group() {
                    this->passed_tests = this->total_tests = 0;
                }

                test_group(std::string group_name, bool condition, std::string test_name, std::string pass = "PASSED", std::string fail = "FAILED") {
                    this->group_name = group_name;
                    test new_test(condition, pass, fail);
                    this->the_tests.insert({test_name, new_test});
                }
                
                void set_group_name(std::string new_name) {
                    this->group_name = new_name;
                }

                void add_test(bool condition, std::string test_name, std::string pass = "PASSED", std::string fail = "FAILED") {
                    if (this->contains(test_name)) {
                        this->the_tests[test_name] = test(condition, pass, fail);
                    }
                    else {
                        this->the_tests.insert({test_name, test(condition, pass, fail)});
                    }
                    this->passed_tests = (condition) ? this->passed_tests + 1 : passed_tests;
                    this->total_tests = this->total_tests + 1;
                }

                std::vector<std::string> get_test_names () const {
                    std::vector<std::string> the_answer;
                    for (const auto &element : this->the_tests) {
                        the_answer.push_back(element.first);
                    }
                    return the_answer;
                }

                std::map<std::string, test> get_test_map() const {
                    return this->the_tests;
                }

                test get_test(std::string name) {
                    if (this->contains(name)) {
                        return this->the_tests[name];
                    }
                    return NULL;
                }

                unsigned long get_passed_tests() const {
                    return this->passed_tests;
                }

                unsigned long get_total_tests() const {
                    return this->total_tests;
                }

        };


    }


    class tests {

        private:
            std::map<std::string, test_group> groups;

            bool group_contained(std::string group_name) const {
                return this->groups.find(group_name) != this->groups.end();
            }

        public:
            
            tests() {}

            tests(std::string group_name, bool condition, std::string test_name = "TEST ", std::string pass = "PASSED", std::string fail = "FAILED") {
                test_group new_group(group_name, condition, test_name, pass, fail);
                this->groups.insert({group_name, new_group});
            }

            /**
             * @brief This creates a new group, or overrides an old group
             * and creates a new group with no tests in it.
             * 
             * @param group_name The name of the group to be created or added.
             * 
             * @returns void.
            */
            void create_group(std::string group_name) {
                test_group new_group;
                new_group.set_group_name(group_name);
                this->groups.insert({group_name, new_group});
            }

            /**
             * @brief Check if a specific group exists or not.
             * 
             * @param to_find The group to check for.
             * 
             * @returns true if the to_find group exists, false otherwise.
            */
            bool group_exists(std::string to_find) {
                return this->group_contained(to_find);
            }

            /**
             * @brief Adds a new test to the tests, either to an existing group, or to a new group.
             * @param group The group to add the test to, or create the group then add the test to.
             * @param test_name The name of the test that is being added.
             * @param condition The condition of the test, either a pass or a fail.
             * @param pass The message to be displayed if the test is passed.
             * @param fail The message to be displayed if the test is failed.
             * 
             * @returns void.
            */
            void add_test(std::string group, std::string test_name, bool condition, std::string pass = "PASSED", std::string fail = "FAILED") {
                if (this->group_contained(group)) {
                    this->groups[group].add_test(condition, test_name, pass, fail);
                }
                else {
                    test_group new_group;
                    new_group.set_group_name(group);
                    this->groups.insert({group, new_group});
                    this->groups[group].add_test(condition, test_name, pass, fail);
                }
            }

            /**
             * @brief Print all the tests, and the groups that they are in, and
             * the total number of tests that passed over the total number of tests.
             * 
             * @returns void.
            */
            void print_tests(std::string title, bool only_fails = false, bool clear_first = false) const {
                std::string colored_string;
                unsigned long passed = 0, total = 0;
                if (clear_first) {
                    std::cout << "\x1B[2J" << std::endl;
                }
                std::cout << title << std::endl;
                for (const auto& this_group : this->groups) {
                    std::cout << useful_functions::get_styled_string(this_group.first, bold_style, (this_group.second.get_passed_tests() == this_group.second.get_total_tests()) ? green_text : ((this_group.second.get_passed_tests() == 0) ? red_text : yellow_text), default_background);
                    std::cout << " : " << this_group.second.get_passed_tests() << " / " << this_group.second.get_total_tests() << std::endl;
                    passed = passed + this_group.second.get_passed_tests();
                    total = total + this_group.second.get_total_tests();
                    for (const auto& this_group_stuff : this_group.second.get_test_map()) {
                        // colored_string = useful_functions::get_styled_string(this_group_stuff.second.get_message(), bold_style, (this_group_stuff.second.get_condition()) ? green_text : red_text, default_background);
                        if (only_fails) {
                            if (this_group_stuff.second.get_condition() == false) {
                                std::cout << "\t" << this_group_stuff.first << " : " << useful_functions::get_styled_string(this_group_stuff.second.get_message(), bold_style, (this_group_stuff.second.get_condition()) ? green_text : red_text, default_background) << std::endl;
                            }
                        }
                        else {
                            std::cout << "\t" << this_group_stuff.first << " : " << useful_functions::get_styled_string(this_group_stuff.second.get_message(), bold_style, (this_group_stuff.second.get_condition()) ? green_text : red_text, default_background) << std::endl;
                        }
                        
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl << std::endl;
                std::cout << useful_functions::get_styled_string("Final results " + std::to_string(passed), bold_style, (passed == total) ? green_text : ((passed == 0) ? red_text : yellow_text), default_background) << " / " << useful_functions::get_styled_string(std::to_string(total), bold_style, (passed == total) ? green_text : ((passed == 0) ? red_text : yellow_text), default_background) << std::endl;
            }

    };



}