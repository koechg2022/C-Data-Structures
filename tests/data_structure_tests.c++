
#include <random>
#include <vector>
#include "../headers/structures.h"
#include "../headers/test_structures.h"

#ifndef useful_functions_h

#include "../headers/useful_functions.h"

#endif



std::vector<std::string> imagine_dragons = {
    "Oh the mouth of the river...",
    "Oh the mouth of the river...",
    "Oh the mouth of the river...",
    "I wanna live life like that",
    "Live Life like the faithful one",
    "I wanna bow to the floor with everybody else, I wanna be someone",
    "I wanna make love",
    "I don't want no enemies",
    "I was the curse of the man that was living life, living life just to please",
    "Oh the mouth of the river....",
    "And the wrath of the giver.....",
    "With the hands at the center......",
    "Oh the mouth of the river......."
};


std::vector<std::string> the_beetles = {
    "Blackbird singing in the dead of night",
    "Take these broken wings and learn to fly",
    "All your life",
    "You were only waiting for this moment to arrive",
    "Blackbird fly",
    "Blackbird fly",
    "Into the dawn of a dark black night"
};


test_stuff::tests tests;


void simple_test_linked_list();


void useful_functions_tests();


int main(int len, char** args) {
    bool clear_before = false, only_fails = false;
    int index, increase = 1;

    for (index = 0; index < len; index = index + increase) {
        if (useful_functions::same_char(args[index][0], '-')) {
            if (index >= len) {
                if (useful_functions::same_string(args[index], (char*) "--all") || useful_functions::same_string(args[index], (char*) "-al")) {
                    clear_before = true;
                    only_fails = true;
                    break;
                }
                std::cout << useful_functions::get_styled_string(
                    "Missing argument for flag \"" + useful_functions::to_std_string(args[index]),
                    bold_style, 
                    red_text,
                    default_background
                ) << "\"" << std::endl;
                exit(EXIT_FAILURE);
                return 1;
            }
            // there is at least 1 argument
            if (useful_functions::same_string(args[index], (char*) "--clearfirst") || useful_functions::same_string(args[index], (char*) "-cf")) {
                clear_before = true;
            }
            // else {
            //     std::cout << "\"" <<  args[index] << "\" not recognized as the same as \"--clearfirst\"" << std::endl;
            // }
            if (useful_functions::same_string(args[index], (char*) "--toprint") || useful_functions::same_string(args[index], (char*) "-tp")) {
                // std::cout << "\"" << args[index] << "\" recognized as the same as \"--toprint\", or \"-tp\"" << std::endl;
                if (useful_functions::same_string(args[index + 1], (char*) "true")) {
                    only_fails = true;
                }
            }
            // else {
            //     std::cout << "\"" << args[index] << "\" not recognized as the same as \"--toprint\", or \"-tp\"" << std::endl;
            // }
            increase = 2;
        }
        else {
            increase = 1;
        }
    }

    simple_test_linked_list();
    useful_functions_tests();
    tests.print_tests("Data Structures & useful functions tests:\n", only_fails, clear_before);
    return 0;
}



void simple_test_linked_list() {
    unsigned long index;
    data_structures::linear_linked_list<std::string> dragons_list, beeltes_list;
    for (index = 0; index < imagine_dragons.size(); index = index + 1) {
        dragons_list.push(imagine_dragons[index]);
    }
    // std::cout << "\n\n\n";
    for (index = 0; index < the_beetles.size(); index = index + 1) {
        beeltes_list.push(the_beetles[index]);
    }
    tests.create_group("linear_linked_list created");
    // std::cout << "\n\n\n";
    for (index = 0; index < dragons_list.length(); index = index + 1) {
        tests.add_test("linear_linked_list created", 
            "dragons_list[" + std::to_string(index) + "] returns expected",
            imagine_dragons[index] == dragons_list[index],
            "dragons_list[" + std::to_string(index) + "] returned correct",
            "dragons_list[" + std::to_string(index) + "] did not return expected"
        );
    }
    for (index = 0; index < beeltes_list.length(); index = index + 1) {
        tests.add_test("linear_linked_list created", 
            "beeltes_list[" + std::to_string(index) + "] returns expected",
            beeltes_list[index] == the_beetles[index],
            "beeltes_list[" + std::to_string(index) + "] returned correct",
            "beeltes_list[" + std::to_string(index) + "] did not return expected"
        );
    }

    tests.create_group("linear_linked_list lengths are correct");

    tests.add_test("linear_linked_list lengths are correct",
        "beetles_list.length()",
        beeltes_list.length() == the_beetles.size(),
        "beeltles_list.length() returned " + std::to_string(beeltes_list.length()),
        "beeltles_list.length() returned " + std::to_string(beeltes_list.length()) + 
        " instead of " + std::to_string(the_beetles.size())
    );

    tests.add_test("linear_linked_list lengths are correct",
        "dragons_list.length()",
        dragons_list.length() == imagine_dragons.size(),
        "dragons_list.length() returned " + std::to_string(dragons_list.length()),
        "dragons_list.length() returned " + std::to_string(dragons_list.length()) + 
        " instead of " + std::to_string(imagine_dragons.size())
    );

    srand((unsigned) time(NULL));
    unsigned long ref;
    for (index = 0; index < dragons_list.length(); index = index + 1) {
        ref = (unsigned long) rand() % ((int) dragons_list.length());
        tests.add_test("linear_linked_list a-linear peeking",
        "dragons_list[" + std::to_string(ref) + "]",
        dragons_list[ref] == imagine_dragons[ref],
        "Returned correct data",
        "Returned \"" + dragons_list[ref] + "\" instead of \"" + imagine_dragons[ref] + "\"");
    }
    // std::cout << "--------------------------------------------------" << std::endl;
    signed long signed_index;
    for (signed_index = -1; signed_index > -1 * (dragons_list.length()); signed_index = signed_index - 1) {
        // std::cout << "Testing " << signed_index << std::endl;
        // std::cout << "imagine_dragons[" << std::to_string(imagine_dragons.size() + signed_index) << "] : " << imagine_dragons[imagine_dragons.size() + signed_index] << std::endl;
        // std::cout << "dragons_list.peek(" << signed_index << ") : " << dragons_list.peek(signed_index) << std::endl;
        tests.add_test("linear_linked_list Negative Reference",
            "dragons_list[" + std::to_string(signed_index) + "]",
            dragons_list[signed_index] == imagine_dragons[imagine_dragons.size() + signed_index],
            "dragons_list[" + std::to_string(signed_index) + "] returned expected",
            "dragons_list[" + std::to_string(signed_index) + "] returned" + dragons_list[signed_index] + " instead of " +
            imagine_dragons[imagine_dragons.size() + signed_index - 1]
        );
        // std::cout << "Added test" << std::endl;
    }

    for (index = 0; index < dragons_list.length(); index = index + 1) {
        std::cout << index << ".) \"" << dragons_list[index] << "\"" << std::endl;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;
    for (index = 0; index < dragons_list.length() / 2; index = index + 1) {
        std::string first_before = dragons_list[index];
        std::string second_before = dragons_list[dragons_list.length() - 1 - index];
        std::cout << "index : " << index << std::endl;
        std::cout << "Before swap, first : \"" << first_before << std::endl;
        std::cout << "Before swap, second : \"" << second_before << std::endl;
        dragons_list.swap(index, dragons_list.length() - 1 - index);
        std::cout << "After swap, first : \"" << first_before << std::endl;
        std::cout << "After swap, second : \"" << second_before << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
    }


    dragons_list.reset();
    tests.add_test("linear_linked_list reset method is correct",
        "reset re-set's the size",
        dragons_list.length() == 0,
        "Size is 0",
        "Size is " + std::to_string(dragons_list.length())
    );
    // bool except_thrown = false;
    try {
        dragons_list.peek(0);
        tests.add_test("linear_linked_list reset method is correct",
            "reset removes all data peek method",
            false,
            "data at index 0 retrieved",
            "data at index 0 should not have been retrieved, but was"
        );
    }
    catch (std::range_error except) {

        tests.add_test("linear_linked_list reset method is correct",
            "reset removes all data peek method",
            true,
            "data at index 0 retrieved",
            "data at index 0 should not have been retrieved, but was"
        );

        try {
            dragons_list[0];
            tests.add_test("linear_linked_list reset method is correct",
                "reset removes all data, []",
                false,
                "data at index 0 retrieved",
                "data at index 0 should not have been retrieved, but was"
            );
        }
        catch (std::range_error inner_except) {
            tests.add_test("linear_linked_list reset method is correct",
                "reset removes all data []",
                true,
                "data at index 0 retrieved",
                "data at index 0 should not have been retrieved, but was"
            );
        }

    }



}


void useful_functions_tests() {
    unsigned long unsigned_long;
    unsigned long const limit = 1000;
    for (unsigned_long = 0; unsigned_long < limit; unsigned_long = unsigned_long + 1) {
        tests.add_test(
            "useful_functions tests",
            "absolute((unsigned long) " + std::to_string(unsigned_long) + ")",
            ((useful_functions::absolute<unsigned long>(unsigned_long) >= 0) && (useful_functions::absolute<unsigned long>(unsigned_long) == unsigned_long)),
            "Correctly returned absolute value of " + std::to_string(unsigned_long),
            "useful_functions::absolute(" + std::to_string(unsigned_long) + ") : " + std::to_string(useful_functions::absolute<unsigned long>(unsigned_long))
        );
    }
    signed long signed_long, other, index;
    for (signed_long = -1000; signed_long <= limit; signed_long = signed_long + 1) {
        tests.add_test(
            "useful_functions tests",
            "absolute((signed long) " + std::to_string(signed_long) + ")",
            ((useful_functions::absolute<signed long>(signed_long) >= 0) && (useful_functions::absolute<signed long>(signed_long) == ((signed_long < 0) ? signed_long * -1 : signed_long))),
            "Correctly returned absolute value of " + std::to_string(signed_long),
            "useful_functions::absolute(" + std::to_string(signed_long) + ") : " + std::to_string(useful_functions::absolute<signed long>(signed_long))
        );
    }

    // tests for min/max both with and without pointers

    for (index = 0; index < limit; index = index + 1) {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<signed long> distr(-1 * limit, limit); // define the range
        signed_long = (signed long) distr(gen);
        other = (signed long) distr(gen);
        // std::cout << "signed_long is " << signed_long << ", and other is " << other << std::endl;

        // first 3 branches for abs = false
        if (signed_long == other) {
            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", false)",
                useful_functions::max<signed long>(signed_long, other, false) == signed_long,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::max<signed long>(signed_long, other, false))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", false)",
                useful_functions::max<signed long>(&signed_long, &other, false) == &signed_long,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::max<signed long>(signed_long, other, false))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", false)",
                useful_functions::min<signed long>(signed_long, other, false) == signed_long,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::min<signed long>(signed_long, other, false))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", false)",
                useful_functions::min<signed long>(&signed_long, &other, false) == &signed_long,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::min<signed long>(signed_long, other, false))
            );

        }
        
        else if (signed_long > other) {
            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", false)",
                useful_functions::max<signed long>(signed_long, other, false) == signed_long,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::max<signed long>(signed_long, other, false))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", false)",
                useful_functions::max<signed long>(&signed_long, &other, false) == &signed_long,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::max<signed long>(signed_long, other, false))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", false)",
                useful_functions::min<signed long>(signed_long, other, false) == other,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::min<signed long>(signed_long, other, false))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", false)",
                useful_functions::min<signed long>(&signed_long, &other, false) == &other,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::min<signed long>(signed_long, other, false))
            );

        }

        else {
            
            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", false)",
                useful_functions::max<signed long>(signed_long, other, false) == other,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::max<signed long>(signed_long, other, false))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", false)",
                useful_functions::max<signed long>(&signed_long, &other, false) == &other,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::max<signed long>(signed_long, other, false))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", false)",
                useful_functions::min<signed long>(signed_long, other, false) == signed_long,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::min<signed long>(signed_long, other, false))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", false)",
                useful_functions::min<signed long>(&signed_long, &other, false) == &signed_long,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::min<signed long>(signed_long, other, false))
            );

        }
        

        // next 3 branches for abs = true
        if (useful_functions::absolute(signed_long) == useful_functions::absolute(other)) {
            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", true)",
                useful_functions::max<signed long>(signed_long, other, true) == signed_long,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::max<signed long>(signed_long, other, true))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", true)",
                useful_functions::max<signed long>(&signed_long, &other, true) == &signed_long,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::max<signed long>(signed_long, other, true))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", true)",
                useful_functions::min<signed long>(signed_long, other, true) == signed_long,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::min<signed long>(signed_long, other, true))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", true)",
                useful_functions::min<signed long>(&signed_long, &other, true) == &signed_long,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::min<signed long>(signed_long, other, true))
            );
        }

        else if (useful_functions::absolute(signed_long) > useful_functions::absolute(other)) {
            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", true)",
                useful_functions::max<signed long>(signed_long, other, true) == signed_long,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::max<signed long>(signed_long, other, true))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", true)",
                useful_functions::max<signed long>(&signed_long, &other, true) == &signed_long,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::max<signed long>(signed_long, other, true))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", true)",
                useful_functions::min<signed long>(signed_long, other, true) == other,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::min<signed long>(signed_long, other, true))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", true)",
                useful_functions::min<signed long>(&signed_long, &other, true) == &other,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::min<signed long>(signed_long, other, true))
            );
        }

        else {

            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", true)",
                useful_functions::max<signed long>(signed_long, other, true) == other,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::max<signed long>(signed_long, other, true))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::max(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", true)",
                useful_functions::max<signed long>(&signed_long, &other, true) == &other,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::max<signed long>(signed_long, other, true))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", true)",
                useful_functions::min<signed long>(signed_long, other, true) == signed_long,
                "Correctly returned the max",
                "Returned " + std::to_string(useful_functions::min<signed long>(signed_long, other, true))
            );

            tests.add_test(
                "useful_functions tests",
                "useful_functions::min(&" + std::to_string(signed_long) + ", &" + std::to_string(other) + ", true)",
                useful_functions::min<signed long>(&signed_long, &other, true) == &signed_long,
                "Correctly returned the max",
                "Returned pointer to " + std::to_string(useful_functions::min<signed long>(signed_long, other, true))
            );

        }

    }

    // tests for difference

    for (index = 0; index < limit; index = index + 1) {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<signed long> distr( -1 * limit, limit);
        signed_long = (signed long) distr(gen);
        other = (signed long) distr(gen);
        if (signed_long >= other) {
            tests.add_test(
                "useful_functions tests",
                "diffrence(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", false)",
                useful_functions::difference<signed long>(signed_long, other, false) == signed_long - other,
                "Correctly returned " + std::to_string(signed_long - other),
                "Incorrectly returned " + std::to_string(useful_functions::difference<signed long>(signed_long, other, false))
            );
        }
        else {
            tests.add_test(
                "useful_functions tests",
                "diffrence(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", false)",
                useful_functions::difference<signed long>(signed_long, other, false) == other - signed_long,
                "Correctly returned " + std::to_string(other - signed_long),
                "Incorrectly returned " + std::to_string(useful_functions::difference<signed long>(signed_long, other, false))
            );
        }

        if (useful_functions::absolute(signed_long) >= useful_functions::absolute(other)) {
            tests.add_test(
                "useful_functions tests",
                "diffrence(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", true)",
                useful_functions::difference<signed long>(signed_long, other, true) == useful_functions::absolute(signed_long) - useful_functions::absolute(other),
                "Correctly returned " + std::to_string(useful_functions::absolute(signed_long) - useful_functions::absolute(other)),
                "Incorrectly returned " + std::to_string(useful_functions::difference<signed long>(signed_long, other, true))
            );
        }

        else {
            tests.add_test(
                "useful_functions tests",
                "diffrence(" + std::to_string(signed_long) + ", " + std::to_string(other) + ", true)",
                useful_functions::difference<signed long>(signed_long, other, true) == useful_functions::absolute(other) - useful_functions::absolute(signed_long),
                "Correctly returned " + std::to_string(useful_functions::absolute(other) - useful_functions::absolute(signed_long)),
                "Incorrectly returned " + std::to_string(useful_functions::difference<signed long>(signed_long, other, true))
            );
        }

    }

    // tests for string functions

    char letter, c;
    for (letter = 0; letter < sizeof(letter) * 8; letter = letter + 1) {
        if (letter >= 'A' && letter <= 'Z') {
            tests.add_test(
                "useful_functions tests",
                "is_caps(" + std::to_string(letter) + ")",
                useful_functions::is_caps(letter),
                "Accurately recognized that \"" + std::to_string(letter) + "\" is a capital letter",
                "Innacurately reported that \"" + std::to_string(letter) + "\" is not a capital letter"
            );

            tests.add_test(
                "useful_functions tests",
                "is_letter(" + std::to_string(letter) + ")",
                useful_functions::is_letter(letter),
                "Accurately determined that \"" + std::to_string(letter) + "\" is a letter",
                "Inaccurately reported that \"" + std::to_string(letter) + "\" is not a letter"
            );

            // add to_lower case test here
            tests.add_test(
                "useful_functions tests",
                "to_caps(" + std::to_string(letter) + ")",
                useful_functions::to_caps(letter) == letter,
                "Accurately converted a capital letter to capital letter form",
                "Innacurately converted a capital letter into a different version of it's form"
            );

            tests.add_test(
                "useful_functions tests",
                "to_lower(" + std::to_string(letter) + ")",
                useful_functions::to_lower(letter) == (letter + ('a' - 'A')),
                "Correctly converted a capital letter into a lower case letter",
                "Did not correctly convert a capital letter into a lower case letter. Instead converted it into \"" + std::to_string(useful_functions::to_lower(letter)) + "\""
            );

            for (c = 0; c < sizeof(c) * 8; c = c + 1) {
                if (c == letter) {
                    tests.add_test(
                        "useful_functions tests",
                        "same_char(" + std::to_string(c) + ", " + std::to_string(letter) + ", false)",
                        useful_functions::same_char(c, letter, false),
                        "Correctly determined that \"" + std::to_string(c) + "\" is the same as \"" + std::to_string(letter),
                        "Incorrectly determined that \"" + std::to_string(c) + "\" is not the same as \"" + std::to_string(letter)
                    );
                }
                else if (c == useful_functions::to_caps(letter) || c == useful_functions::to_lower(letter)) {
                    tests.add_test(
                        "useful_functions tests",
                        "same_char(" + std::to_string(c) + ", " + std::to_string(letter) + ", true)",
                        useful_functions::same_char(c, letter, true),
                        "Correctly determined that \"" + std::to_string(c) + "\" is the same as \"" + std::to_string(letter),
                        "Incorrectly determined that \"" + std::to_string(c) + "\" is not the same as \"" + std::to_string(letter)
                    );
                }
            }

        }
        else if (letter >= 'a' && letter <= 'z') {
            tests.add_test(
                "useful_functions tests",
                "is_lower(" + std::to_string(letter) + ")",
                useful_functions::is_lower(letter),
                "Accurately recognized that \"" + std::to_string(letter) + "\" is a lower case letter",
                "Innacurately reported that \"" + std::to_string(letter) + "\" is not a lower case letter"
            );

            tests.add_test(
                "useful_functions tests",
                "is_letter(" + std::to_string(letter) + ")",
                useful_functions::is_letter(letter),
                "Accurately determined that \"" + std::to_string(letter) + "\" is a letter",
                "Inaccurately reported that \"" + std::to_string(letter) + "\" is not a letter"
            );

            // add to_caps case test here
            tests.add_test(
                "useful_functions tests",
                "to_lower(" + std::to_string(letter) + ")",
                useful_functions::to_lower(letter) == letter,
                "Accurately converted a lower letter to it's same lower letter form",
                "Did not converted a lower letter to it's same lower letter form"
            );

            tests.add_test(
                "useful_functions tests",
                "to_caps(" + std::to_string(letter) + ")",
                useful_functions::to_caps(letter) == (letter - ('a' - 'A')),
                "Correctly converted a lower case letter into it's capital letter case form",
                "Did not correctly converted a lower case letter into it's capital letter case form"
            );

            for (c = 0; c < sizeof(c) * 8; c = c + 1) {
                if (c == letter) {
                    tests.add_test(
                        "useful_functions tests",
                        "same_char(" + std::to_string(c) + ", " + std::to_string(letter) + ", false)",
                        useful_functions::same_char(c, letter, false),
                        "Correctly determined that \"" + std::to_string(c) + "\" is the same as \"" + std::to_string(letter),
                        "Incorrectly determined that \"" + std::to_string(c) + "\" is not the same as \"" + std::to_string(letter)
                    );
                }
                else if (c == useful_functions::to_caps(letter) || c == useful_functions::to_lower(letter)) {
                    tests.add_test(
                        "useful_functions tests",
                        "same_char(" + std::to_string(c) + ", " + std::to_string(letter) + ", true)",
                        useful_functions::same_char(c, letter, true),
                        "Correctly determined that \"" + std::to_string(c) + "\" is the same as \"" + std::to_string(letter),
                        "Incorrectly determined that \"" + std::to_string(c) + "\" is not the same as \"" + std::to_string(letter)
                    );
                }
            }

        }
        else {
            tests.add_test(
                "useful_functions tests",
                "is_letter(" + std::to_string(letter) + ")",
                !useful_functions::is_letter(letter),
                "Accurately determined that \"" + std::to_string(letter) + "\" is not a letter",
                "Inaccurately reported that \"" + std::to_string(letter) + "\" is a letter"
            );

            tests.add_test(
                "useful_functions tests",
                "is_caps(" + std::to_string(letter) + ")",
                !useful_functions::is_caps(letter),
                "is_caps(" + std::to_string(letter) + ") returned false",
                "is_caps(" + std::to_string(letter) + ") returned true instead of false"
            );

            tests.add_test(
                "useful_functions tests",
                "is_lower(" + std::to_string(letter) + ")",
                !useful_functions::is_lower(letter),
                "is_lower(" + std::to_string(letter) + ") returned false",
                "is_lower(" + std::to_string(letter) + ") returned true instead of false"
            );

            tests.add_test(
                "useful_functions tests",
                "to_caps(" + std::to_string(letter) + ")",
                useful_functions::to_caps(letter) == letter,
                "to_caps(" + std::to_string(letter) + ") returned \"" + std::to_string(letter) + "\" as expected",
                "to_caps(" + std::to_string(letter) + ") returned \"" + std::to_string(useful_functions::to_caps(letter)) + "\" instead of " + std::to_string(letter)
            );

            tests.add_test(
                "useful_functions tests",
                "to_lower(" + std::to_string(letter) + ")",
                useful_functions::to_lower(letter) == letter,
                "to_lower(" + std::to_string(letter) + ") returned \"" + std::to_string(letter) + "\" as expected",
                "to_lower(" + std::to_string(letter) + ") returned \"" + std::to_string(useful_functions::to_lower(letter)) + "\" instead of " + std::to_string(letter)
            );

        }

    }

}