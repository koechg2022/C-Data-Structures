
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
    data_structures::linear_linked_list<std::string> dragons_list, beetles_list, combined_list;
    signed long index;
    for (index = 0; index < imagine_dragons.size(); index = index + 1) {
        dragons_list.push(imagine_dragons[index]);
    }

    for (index = 0; index < the_beetles.size(); index = index + 1) {
        beetles_list.push(the_beetles[index]);
    }


    the_tests.add_test(imagine_dragons.size() == dragons_list.length(), "Imagine Dragons linked_list length", "Correctly determined length to be " + std::to_string(imagine_dragons.size()), "Incorrectly determined to be " + std::to_string(dragons_list.length()));
    the_tests.add_test(beetles_list.length() == the_beetles.size(), "Beetles linked_list length", "beetles_list.length() returned " + std::to_string(the_beetles.size()) + " as expected.", "beetles_list.length() returned " + std::to_string(beetles_list.length()) + " instead of " + std::to_string(the_beetles.size()));
    // combined_list = dragons_list + beetles_list;
    // the_tests.add_test(combined_list.length() == dragons_list.length() + beetles_list.length(), "Combined_list length is accurate", "Correctly determined length of combined to be " + std::to_string(dragons_list.length() + beetles_list.length()), "Incorrectly determined length of combined list to be " + std::to_string(combined_list.length()));


    the_tests.print_all_tests();

}