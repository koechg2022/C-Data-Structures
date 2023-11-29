#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include "../headers/useful_functions.h"
#include "../headers/structures.h"




unsigned long const limit = 1000;
unsigned long passed = 0, failed = 0;



template <typename data_> data_ get_random();




template <typename data_> void print_list(data_* list, unsigned long length);




void useful_functions_tests();




void useful_functions_tests_2();




void linear_linked_list_tests();




void binary_search_tree_tests();




int main(int len, char** args) {
    useful_functions_tests();
    useful_functions_tests_2();
    linear_linked_list_tests();
    binary_search_tree_tests();
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




void useful_functions_tests() {

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

    unsigned long* u_list_ptr[limit], *other_list_ptr[limit];
    signed long* s_list_ptr[limit], *so_list_ptr[limit];


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

    // Algorithm works, but the tests needs to be remade


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



void useful_functions_tests_2() {
    unsigned long index, div = 1;
    signed long* list[limit / div], *other_list[limit / div];
    for (index = 0; index < limit / div; index = index + 1) {
        list[index] = new signed long(get_random<signed long>());
        other_list[limit / div - index - 1] = new signed long(*list[index]);
    }
    useful_functions::sort_list<signed long>(list, limit / div, (char *) "bubble", true);
    useful_functions::sort_list<signed long>(other_list, limit / div, (char *) "bubble", false);
    for (index = 0; index < limit / div; index = index + 1) {
        (*list[index] == *other_list[limit / div - index - 1]) ? passed++ : failed++;
    }

    for (index = 0; index < limit / div; index = index + 1) {
        delete list[index];
        delete other_list[index];
    }


    // for selection sort

    for (index = 0; index < limit / div; index = index + 1) {
        list[index] = new signed long(get_random<signed long>());
        other_list[limit / div - index - 1] = new signed long(*list[index]);
    }
    useful_functions::sort_list<signed long>(list, limit / div, (char *) "selection", true);
    useful_functions::sort_list<signed long>(other_list, limit / div, (char *) "selection", false);
    for (index = 0; index < limit / div; index = index + 1) {
        (*list[index] == *other_list[limit / div - index - 1]) ? passed++ : failed++;
    }

    for (index = 0; index < limit / div; index = index + 1) {
        delete list[index];
        delete other_list[index];
    }


    // for insertion sort

    for (index = 0; index < limit / div; index = index + 1) {
        list[index] = new signed long(get_random<signed long>());
        other_list[limit / div - index - 1] = new signed long(*list[index]);
    }
    useful_functions::sort_list<signed long>(list, limit / div, (char *) "selection", true);
    useful_functions::sort_list<signed long>(other_list, limit / div, (char *) "selection", false);
    for (index = 0; index < limit / div; index = index + 1) {
        (*list[index] == *other_list[limit / div - index - 1]) ? passed++ : failed++;
    }

    for (index = 0; index < limit / div; index = index + 1) {
        delete list[index];
        delete other_list[index];
    }


    // for merge sort

    for (index = 0; index < limit / div; index = index + 1) {
        list[index] = new signed long(get_random<signed long>());
        other_list[limit / div - index - 1] = new signed long(*list[index]);
    }
    useful_functions::sort_list<signed long>(list, limit / div, (char *) "merge", true);
    useful_functions::sort_list<signed long>(other_list, limit / div, (char *) "merge", false);
    for (index = 0; index < limit / div; index = index + 1) {
        (*list[index] == *other_list[limit / div - index - 1]) ? passed++ : failed++;
    }

    for (index = 0; index < limit / div; index = index + 1) {
        delete list[index];
        delete other_list[index];
    }

}




void linear_linked_list_tests() {
    data_structures::linear_linked_list<unsigned long> list;
    unsigned long data[] = {get_random<unsigned long>(), get_random<unsigned long>(), get_random<unsigned long>()};
    (list.empty()) ? passed++ : failed++;
    (list.length() == 0) ? passed++ : failed++;
    list.push(data[0]);
    (list.length() == 1) ? passed++ : failed++;
    list.push(data[1]);
    (list.length() == 2) ? passed++ : failed++;
    list.push(data[2]);
    (list.length() == 3) ? passed++ : failed++;
    (!list.empty()) ? passed++ : failed++;
    (list.length() == 3) ? passed++ : failed++;
    (list.peek(0) == data[0]) ? passed++ : failed++;
    (list.peek(1) == data[1]) ? passed++ : failed++;
    (list.peek(2) == data[2]) ? passed++ : failed++;
    (list[0] == data[0]) ? passed++ : failed++;
    (list[1] == data[1]) ? passed++ : failed++;
    (list[2] == data[2]) ? passed++ : failed++;

}



void binary_search_tree_tests() {

    data_structures::binary_search_tree<signed long> tree;
    signed long list[] = {get_random<signed long>(), get_random<signed long>()};
    (tree.empty()) ? passed++ : failed++;
    (tree.get_size() == 0) ? passed++ : failed++;
    (tree.get_height() == -1) ? passed++ : failed++;
    // fprintf(stdout, "tree size before adding anything %li\n", tree.get_size());
    // fprintf(stdout, "tree height before adding anything %li\n", tree.get_height());
    tree.add(list[0]);
    // fprintf(stdout, "\ntree size after adding one thing %li\n", tree.get_size());
    // fprintf(stdout, "tree height after adding one thing %li\n", tree.get_height());
    tree.add(list[1]);
    // fprintf(stdout, "\ntree size after adding two thing %li\n", tree.get_size());
    // fprintf(stdout, "tree height after adding two thing %li\n", tree.get_height());
    tree.empty() == false ? passed++ : failed++;
    tree.get_size() == 2 ? passed++ : failed++;
    fprintf(stdout, "height of of %li is %li\n", list[0], tree.index_of(list[0]));
    fprintf(stdout, "height of of %li is %li\n", list[1], tree.index_of(list[1]));
    // tree.contains(list[0]) ? passed++ : failed++;
    // tree.contains(list[1]) ? passed++ : failed++;
    fprintf(stdout, "Reached\n");

}

