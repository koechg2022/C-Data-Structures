
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


void test_linked_list();



int main(int len, char** args) {

    test_linked_list();

    return 0;
}



void test_linked_list() {
    data_structures::linear_linked_list<std::string> linked_list, other_list;
    unsigned short int index;
    for (index = 0; index < imagine_dragons.size() / 2; index = index + 1) {
        linked_list.push(imagine_dragons[index]);
    }
    for (index = 0; index < linked_list.length(); index = index + 1) {
        std::cout << index << ".)\t" << linked_list.peek(index) << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    linked_list.push("These are the lyrics to Imagine Dragons", 0);
    for (index = 0; index < linked_list.length(); index = index + 1) {
        std::cout << index << ".)\t" << linked_list.peek(index) << std::endl;
    }
    for (index = imagine_dragons.size() / 2; index < imagine_dragons.size(); index = index + 1) {
        other_list.push(imagine_dragons[index]);
    }
    linked_list = linked_list + other_list;
    std::cout << "-------------------------------------------------------" << std::endl;
    for (index = 0; index < linked_list.length(); index = index + 1) {
        std::cout << index << ".)\t" << linked_list.peek(index) << std::endl;
    }
    linked_list.swap();
    std::cout << "-------------------------------------------------------" << std::endl;
    for (index = 0; index < linked_list.length(); index = index + 1) {
        std::cout << index << ".)\t" << linked_list.peek(index) << std::endl;
    }
}