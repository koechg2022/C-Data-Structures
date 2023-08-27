
#include <vector>
#include "../headers/structures.h"
#include "../headers/test_structures.h"



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


tests::all_tests the_tests;


void test_linked_list();



int main(int len, char** args) {
    test_linked_list();
    return 0;
}



void test_linked_list() {
    data_structures::linear_linked_list<std::string> dragons_list, beetles_list, combined_list, temp;
    signed long index;
    for (index = 0; index < imagine_dragons.size(); index = index + 1) {
        dragons_list.push(imagine_dragons[index]);
        temp.push(imagine_dragons[index]);
    }

    for (index = 0; index < the_beetles.size(); index = index + 1) {
        beetles_list.push(the_beetles[index]);
    }

    the_tests.add_test(imagine_dragons.size() == dragons_list.length(), "Imagine Dragons linked_list length", "Correctly determined length to be " + std::to_string(imagine_dragons.size()), "Incorrectly determined to be " + std::to_string(dragons_list.length()));
    the_tests.add_test(beetles_list.length() == the_beetles.size(), "Beetles linked_list length", "beetles_list.length() returned " + std::to_string(the_beetles.size()) + " as expected.", "beetles_list.length() returned " + std::to_string(beetles_list.length()) + " instead of " + std::to_string(the_beetles.size()));

    for (index = 0; index < dragons_list.length(); index = index + 1) {
        the_tests.add_test(dragons_list.peek(index) == imagine_dragons[index], "dragons_list.peek(" + std::to_string(index) + ") method", "Peek method returned expected", "Peek did not return expected. Instead returned\n\t" + dragons_list.peek(index));
        the_tests.add_test(dragons_list[index] == imagine_dragons[index], "dragons_list[" + std::to_string(index) + "] peek test", "Bracket referencing returned expected", "Bracket referencing did not return expected");

    }

    for (index = 0; index < beetles_list.length(); index = index + 1) {
        the_tests.add_test(beetles_list.peek(index) == the_beetles[index], "beetles_list.peek(" + std::to_string(index) + ") method", "Peek method returned expected", "Peek did not return expected. Instead returned\n\t" + beetles_list.peek(index));
        the_tests.add_test(beetles_list[index] == the_beetles[index], "beetles_list[" + std::to_string(index) + "] peek test", "Bracket referencing returned expected", "Bracket referencing did not return expected");
    }

    // combined_list = (beetles_list + dragons_list);
    // combined_list = beetles_list;

    the_tests.add_test(temp == dragons_list, "== operator on different lists with same data", "== operator returned true correctly", "== operator returned false instead of true");
    the_tests.add_test(temp == temp, "== operator on same lists with same data (temp)", "== operator returned true correctly", "== operator returned false instead of true");
    the_tests.add_test(dragons_list == dragons_list, "== operator on same lists with same data (dragon_list)", "== operator returned true correctly", "== operator returned false instead of true");
    the_tests.add_test(!(dragons_list == beetles_list), "== operator on different lists with different data", "== operator returned false correctly", "== operator returned true instead of false");
    the_tests.add_test(dragons_list != beetles_list, "!= operator on different lists with different data", "== operator returned false correctly", "== operator returned true instead of false");
    temp[0] = "Just switched temp's 0th index. It should no longer be, imagine_dragins[0]";
    the_tests.add_test(temp[0] != imagine_dragons[0], "Square brackets can be used to change data at specified index", "Square bracket data assignment worked successfully", "Square bracket data assignment did not work as expected");
    // the_tests.add_test(beetles_list.length() + dragons_list.length() == combined_list.length(), "Combined with +", "Correctly returned" + std::to_string(beetles_list.length()) + std::to_string(dragons_list.length()), "Incorrectly returned " + std::to_string(combined_list.length()));
    // the_tests.add_test(combined_list.length() == beetles_list.length(), "linkear_linked_list copy constructor", "combined_list with copy constructor call has expected length of " + std::to_string(beetles_list.length()) + ".", "combined_list with copy constructor call did not have expected length of " + std::to_string(beetles_list.length()) + ". Instead it had a length of " + std::to_string(combined_list.length()));
    the_tests.print_all_tests();

}