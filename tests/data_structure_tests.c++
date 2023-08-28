
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


test_stuff::tests tests;


void simple_test_linked_list();



int main(int len, char** args) {
    simple_test_linked_list();
    return 0;
}



void simple_test_linked_list() {
    unsigned long index;
    data_structures::linear_linked_list<std::string> dragons_list, beeltes_list;
    for (index = 0; index < imagine_dragons.size(); index = index + 1) {
        dragons_list.push(imagine_dragons[index]);
    }

    for (index = 0; index < the_beetles.size(); index = index + 1) {
        beeltes_list.push(the_beetles[index]);
    }
    tests.create_group("linear_linked_list created");
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

    data_structures::linear_linked_list<std::string> combined;
    std::cout << "Combined created" << std::endl;
    combined = dragons_list + beeltes_list;
    // std::cout << "combined.length() : " << combined.length() << std::endl;
    std::cout << "dragons_list.length() : " << dragons_list.length() << std::endl;
    std::cout << "beetles_list.length() : " << beeltes_list.length() << std::endl;
    for (index = 0; index < combined.length(); index = index + 1) {
        std::cout << index << ".) " << combined[index] << std::endl;
    }
    std::cout << "Done" << std::endl;
    // tests.print_tests();
}