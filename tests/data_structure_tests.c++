#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include "../headers/useful_functions.h"
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




template <typename data_> void print_list(data_* list, unsigned long length);




void useful_function();




void linear_linked_list_tests();




int main(int len, char** args) {
    bool clear_before = false, only_fails = true;
    int index, increase = 1;

    for (index = 1; index < len; index = index + 1) {
        
    }
    useful_function();
    fprintf(stdout, "Test results : %lu / %lu. (%s)\n", passed, passed + failed, (failed == 0) ? "All passed" : (passed > 0 && failed > 0) ? "Partial success" : "All failed");
    return 0;
}




template <typename data_> data_ get_random() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<data_> distr( -1 * limit, limit);
    return (data_) distr(gen);
}




template <typename data_> void print_list(data_* list, unsigned long length) {
    unsigned long index;
    for (index = 0; index < length; index = index + 1) {
        fprintf(stdout, "%lu%s", list[index], (index + 1 < length) ? ", " : "\n");
    }
}









void useful_function() {

    // for useful_functions::absolute
    signed long val, other;
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



    // useful_functions::max_data(data_, data_)
    for (index = 0; index < limit; index = index + 1) {
        other = get_random<signed long>();
        val = get_random<signed long>();
        if (val >= other) {
            (useful_functions::max_data<signed long>(val, other) == val) ? passed++ : failed++;
            continue;
        }
        (useful_functions::max_data<signed long>(val, other) == other) ? passed++ : failed++;
    }

    // useful_functions::min_data(data_, data_)
    for (index = 0; index < limit; index = index + 1) {
        other = get_random<signed long>();
        val = get_random<signed long>();
        if (val <= other) {
            (useful_functions::min_data<signed long>(val, other) == val) ? passed++ : failed++;
            continue;
        }
        (useful_functions::min_data<signed long>(val, other) == other) ? passed++ : failed++;
    }



    //==================sorting algorithm tests=======================//

    
    unsigned long u_list[limit], other_list[limit];
    signed long s_list[limit], so_list[limit];


    //=========================bubble sort==========================//
    // Works

    for (index = 0; index < limit; index = index + 1) {
        u_list[index] = get_random<unsigned long>();
    }

    useful_functions::sort_list<unsigned long>(u_list, limit, (char *) "bubble", true);
    for (index = 0; index < limit; index = index + 1) {
        other_list[index] = u_list[limit - index - 1];
    }
    useful_functions::sort_list<unsigned long>(other_list, limit, (char *) "bubble", false);

    for (index = 0; index < limit; index = index + 1) {
        (u_list[index] == other_list[limit - index - 1]) ? passed++ : failed++;
    }

    for (index = 0; index < limit; index = index + 1) {
        s_list[index] = get_random<signed long>();
    }
    useful_functions::sort_list(s_list, limit, (char *) "bubble", true);
    for (index = 0; index < limit; index = index + 1) {
        so_list[index] = s_list[limit - index - 1];
    }
    useful_functions::sort_list<signed long>(so_list, limit, (char *) "bubble", false);

    for (index = 0; index < limit; index = index + 1) {
        (so_list[index] == s_list[limit - index - 1]) ? passed++ : failed++;
    }


    //======================selection sort=======================//
    // Works

    for (index = 0; index < limit; index = index + 1) {
        u_list[index] = get_random<unsigned long>();
    }

    useful_functions::sort_list<unsigned long>(u_list, limit, (char *) "selection", true);
    for (index = 0; index < limit; index = index + 1) {
        other_list[index] = u_list[limit - index - 1];
    }
    useful_functions::sort_list<unsigned long>(other_list, limit, (char *) "selection", false);

    for (index = 0; index < limit; index = index + 1) {
        (u_list[index] == other_list[limit - index - 1]) ? passed++ : failed++;
    }

    for (index = 0; index < limit; index = index + 1) {
        s_list[index] = get_random<signed long>();
    }
    useful_functions::sort_list(s_list, limit, (char *) "selection", true);
    for (index = 0; index < limit; index = index + 1) {
        so_list[index] = s_list[limit - index - 1];
    }
    useful_functions::sort_list<signed long>(so_list, limit, (char *) "selection", false);

    for (index = 0; index < limit; index = index + 1) {
        (so_list[index] == s_list[limit - index - 1]) ? passed++ : failed++;
    }


    //======================insertion sort=======================//
    // Works

    for (index = 0; index < limit; index = index + 1) {
        u_list[index] = get_random<unsigned long>();
    }

    useful_functions::sort_list<unsigned long>(u_list, limit, (char *) "insertion", true);
    for (index = 0; index < limit; index = index + 1) {
        other_list[index] = u_list[limit - index - 1];
    }
    useful_functions::sort_list<unsigned long>(other_list, limit, (char *) "insertion", false);

    for (index = 0; index < limit; index = index + 1) {
        (u_list[index] == other_list[limit - index - 1]) ? passed++ : failed++;
    }

    for (index = 0; index < limit; index = index + 1) {
        s_list[index] = get_random<signed long>();
    }
    useful_functions::sort_list(s_list, limit, (char *) "insertion", true);
    for (index = 0; index < limit; index = index + 1) {
        so_list[index] = s_list[limit - index - 1];
    }
    useful_functions::sort_list<signed long>(so_list, limit, (char *) "insertion", false);

    for (index = 0; index < limit; index = index + 1) {
        (so_list[index] == s_list[limit - index - 1]) ? passed++ : failed++;
    }


    //=======================merge sort=========================//

    for (index = 0; index < limit; index = index + 1) {
        u_list[index] = get_random<unsigned long>();
    }

    useful_functions::sort_list<unsigned long>(u_list, limit, (char *) "merge", true);
    for (index = 0; index < limit; index = index + 1) {
        other_list[index] = u_list[limit - index - 1];
    }
    useful_functions::sort_list<unsigned long>(other_list, limit, (char *) "merge", false);

    for (index = 0; index < limit; index = index + 1) {
        (u_list[index] == other_list[limit - index - 1]) ? passed++ : failed++;
    }

    for (index = 0; index < limit; index = index + 1) {
        s_list[index] = get_random<signed long>();
    }
    useful_functions::sort_list(s_list, limit, (char *) "merge", true);
    for (index = 0; index < limit; index = index + 1) {
        so_list[index] = s_list[limit - index - 1];
    }
    useful_functions::sort_list<signed long>(so_list, limit, (char *) "merge", false);

    for (index = 0; index < limit; index = index + 1) {
        (so_list[index] == s_list[limit - index - 1]) ? passed++ : failed++;
    }


    //=====================merge sort end=======================//

    unsigned char c;
    for (c = 0; c < (unsigned char) - 1; c = c + 1) {

        if ((c >= 'A') && (c <= 'Z')) {
            (useful_functions::is_caps(c)) ? passed++ : failed++;
            (!useful_functions::is_lower(c)) ? passed ++ : failed++;
            (useful_functions::is_letter(c)) ? passed++ : failed++;
            (!useful_functions::is_number(c)) ? passed++ : failed++;
        }

        else if ((c >= 'a') && (c <= 'z')) {
            (!useful_functions::is_caps(c)) ? passed++ : failed++;
            (useful_functions::is_lower(c)) ? passed ++ : failed++;
            (useful_functions::is_letter(c)) ? passed++ : failed++;
            (!useful_functions::is_number(c)) ? passed++ : failed++;
        }

        else if ((c >= '0') && (c <= '9')) {
            (!useful_functions::is_caps(c)) ? passed++ : failed++;
            (!useful_functions::is_lower(c)) ? passed ++ : failed++;
            (!useful_functions::is_letter(c)) ? passed++ : failed++;
            (useful_functions::is_number(c)) ? passed++ : failed++;
        }

        else {
            // fprintf(stdout, "%c\n", c);
            (!useful_functions::is_caps(c)) ? passed++ : failed++;
            (!useful_functions::is_lower(c)) ? passed++ : failed++;
            (!useful_functions::is_letter(c)) ? passed++ : failed++;
            (!useful_functions::is_number(c)) ? passed++ : failed++;
        }
    }


}







void linear_linked_list_tests() {

    data_structures::linear_linked_list<std::string> dragons_list;
    (dragons_list.empty()) ? passed++ : failed++;
    (dragons_list.length() == 0) ? passed++ : failed++;

}





