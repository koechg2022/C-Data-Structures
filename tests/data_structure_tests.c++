#include <iostream>
#include <vector>
#include <random>
#include "../headers/useful_functions.h"





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
    "With the hands at the center......"
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






unsigned long const limit = 1000;
unsigned long passed = 0, failed = 0;


template <typename data_> data_ get_random();



void useful_function_tests();




int main(int len, char** args) {
    bool clear_before = false, only_fails = true;
    int index, increase = 1;

    for (index = 1; index < len; index = index + 1) {
        
    }
    useful_function_tests();
    fprintf(stdout, "Test results : %lu / %lu. (%s)\n", passed, passed + failed, (failed == 0) ? "All passed" : (passed > 0 && failed > 0) ? "Partial success" : "All failed");
    return 0;
}




template <typename data_> data_ get_random() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<data_> distr( -1 * limit, limit);
    return (data_) distr(gen);
}




void useful_function_tests() {

    // for useful_functions::absolute
    signed long val;
    unsigned long index;
    for (index = 0; index < limit; index = index + 1) {
        val = get_random<signed long>();
        if (val < 0) {
            if ((useful_functions::absolute<signed long>(val) > 0) && ((useful_functions::absolute<signed long>(val) == (-1 * val)))) {
                passed = passed + 1;
            }
            else {
                failed = failed + 1;
                fprintf(stdout, "va < 0 fail. Failing on %li : %li\n", val, useful_functions::absolute<signed long>(val));
            }
        }
        else if (val == 0) {
            (useful_functions::absolute<signed long>(val) == val) ? passed++ : failed++;
        }
        else {
            if ((useful_functions::absolute<signed long>(val) > 0) && ((useful_functions::absolute<signed long>(val) == val))) {
                passed = passed + 1;
            }
            else {
                fprintf(stdout, "else branch fail. Failing on %li : %li\n", val, useful_functions::absolute<signed long>(val));
                failed = failed + 1;
            }
        }
    }



    //



}