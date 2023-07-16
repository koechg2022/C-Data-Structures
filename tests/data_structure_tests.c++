
#include <vector>
#include "../headers/structures.h"


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

    std::cout << "Imagine Dragons list:\n---------------------------------------------\n";

    for (index = 0; index < dragons_list.length(); index = index + 1) {
        std::cout << "\t" << index << ".) " << dragons_list[index] << std::endl;
    }

    for (index = 0; index < the_beetles.size(); index = index + 1) {
        beetles_list.push(the_beetles[index]);
    }
    std::cout << "Beetles list:\n---------------------------------------------\n";
    for (index = 0; index < beetles_list.length(); index = index + 1) {
        std::cout << "\t" << index << ".) " << beetles_list[index] << std::endl;
    }
    std::cout << "Combined list:\n---------------------------------------------\n";
    combined_list = dragons_list;
    combined_list = combined_list + beetles_list;
    for (index = 0; index < combined_list.length(); index = index + 1) {
        std::cout << "\t" << index << ".) " << combined_list[index] << std::endl;
    }


    std::cout << "Imagine Dragons list:\n---------------------------------------------\n";

    for (index = 0; index < dragons_list.length(); index = index + 1) {
        std::cout << "\t" << index << ".) " << dragons_list[index] << std::endl;
    }

    std::cout << "Beetles list:\n---------------------------------------------\n";
    for (index = 0; index < beetles_list.length(); index = index + 1) {
        std::cout << "\t" << index << ".) " << beetles_list[index] << std::endl;
    }

}