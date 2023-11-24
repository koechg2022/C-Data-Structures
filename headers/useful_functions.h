/**
 * @author Geoffrey Koech
 * @since Nov 23rd 2023
 * @version 0.8
*/









#ifndef EOF
#include <stdio.h>
#endif





#ifndef EXIT_SUCCESS
#include <stdlib.h>
#endif







namespace useful_functions {


    // TEXT COLORS
    #define black_txt 30
    #define red_txt 31
    #define green_txt 32
    #define yellow_txt 33
    #define blue_txt 34
    #define purple_txt 35
    #define cyan_txt 36
    #define white_txt 37






    // TEXT STYLE
    #define no_style 0
    #define bold_style 1
    #define uline_style 2
    #define neg_1_style 3
    #define neg_2_style 5




    // BACKGROUND COLOR
    #define black_bkg 40
    #define red_bkg 41
    #define green_bkg 42
    #define yellow_bkg 43
    #define blue_bkg 44
    #define purple_bkg 45
    #define cyan_bkg 46
    #define white_bkg 47
    #define default_bkg 49




    typedef unsigned short int us;
    typedef unsigned char bytes;



    namespace {

        /* 
            Using escape sequence to print colors
            esc_start<style>;<color>;<bkg>m<the_string>esc_stop
        */

        #define MOD 1000000007
        #define NOT_IMPLEMENTED_LOGIC 1

        const char* esc_start = "\033[";
        const char* esc_stop = "\033[m";
        

        const char* merge_const = "merge";
        const char* select_const = "select";
        const char* insert_const = "insert";
        const char* bubble_const = "bubble";


        const char case_diff = 'a' - 'A';
        const char A = 'A', Z = 'Z', a = 'a', z = 'z', zero = '0', nine = '9';

        void logic_not_implemented(char* message = (char*) "Logic not yet implemented") {
            fprintf(stderr, "%s", message);
            exit(NOT_IMPLEMENTED_LOGIC);
        }

        bool valid_text_color(us color) {
            return ((color) >= (us) black_txt) && (color <= (us) white_txt);
        }

        bool valid_style(us color) {
            return (color >= (us) no_style) && (color <= (us) neg_1_style) || (color == (us) neg_2_style);
        }

        bool valid_bkg_color(us color) {
            return (color >= (us) black_bkg) && (color <= (us) default_bkg);
        }


        //-------------------------------------Sorting Algorithms-------------------------------------


        template <typename data_> void swap(data_& first, data_& second) {
            data_ temp = first;
            first = second;
            second = temp;
        }


        /**
         * @brief Implementation of Bubble sort.
         * 
         * @note Bubble sort is different from insertion sort in that it "bubbles" the largest or smallest
         * value to the end of the list being sorted and doesn't maintain an sorted section as it does so.
         * 
         * @note Bubble sort is different from selection sort in that "bubbles" the largest or smallest
         * value to the end of the list being sorted and doesn't maintain a sorted section in the same way as selection sort.
         * 
         * @note Bubble sort is unique compared to selection sort and insertion sort in that it "bubbles"
         * the largest or smallest value to the end of the list.
         * 
         * 
         * @param list `(unsigned long* array)` The list to be sorted.
         * 
         * @param length `(unsigned long int)` The length of the list to be sorted.
         * 
         * @param increasing `(bool)` A bool specifying whether the sorting algorithm should sort the data
         * in ascending or descending order.
         * 
         * 
         * @returns void.
        */
        template <typename data_> void bubble_sort(data_* list, unsigned long length, bool ascending = true) {
            unsigned long from_left, from_right;
            data_ temp;
            for (from_right = length - 1; from_right > 0; from_right = from_right - 1) {
                for (from_left = 0; from_left < from_right; from_left = from_left + 1) {

                    if ((!(ascending) && (list[from_left] < list[from_right])) || ((ascending) && (list[from_left] > list[from_right]))) {
                        swap(list[from_left], list[from_right]);
                    }
                }
            }
        }


        /**
         * @brief Implementation of selection_sort.
         * 
         * @note Selection sort is different from bubble sort in that it maintains
         * a sorted and unsorted section of the list, and continually `selecting` and adding the smallest piece 
         * of data (if sorting in increasing order), or the largest piece of data (if sorting 
         * in a decreasing order) to the end of the sorted list.
         * 
         * 
         * 
         * @param list `(unsigned long* array)` The list to be sorted.
         * 
         * @param length `(unsigned long int)` The length of the list to be sorted.
         * 
         * @param increasing `(bool)` A bool specifying whether the sorting algorithm should sort the data
         * in ascending or descending order.
         * 
         * @returns void
        */
        template <typename data_> void selection_sort(data_* list, unsigned long length, bool ascending = true) {
            unsigned long adding_index, checking_index;
            for (checking_index = 0; checking_index < length - 1; checking_index = checking_index + 1) {

                for (adding_index = checking_index + 1; adding_index < length; adding_index = adding_index + 1) {
                    if ((((ascending) && (list[checking_index] > list[adding_index]))) || ((!(ascending) && (list[checking_index] < list[adding_index])))) {
                        swap(list[checking_index], list[adding_index]);
                    }
                }

            }
        }


        /**
         * @brief Implementation of insertion sort algorithm.
         * 
         * @note Insertion sort is different from bubble sort in that it maintains
         * a sorted and unsorted section of the list, and continually `inserts` data
         * from the unsorted section into the sorted section at the proper location in the sorted section.
         * 
         * 
         * @note Insertion sort is very similar to the selection sort algorithm in that
         * it maintains a sorted and unsorted section of the list and inserts data into the sorted
         * section at the proper location of the sorted list.
         * 
         * @param list `(unsigned long* array)` The list to be sorted.
         * 
         * @param length `(unsigned long int)` The length of the list to be sorted.
         * 
         * @param increasing `(bool)` A bool specifying whether the sorting algorithm should sort the data
         * in ascending or descending order.
         * 
         * @returns void
        */
        template <typename data_> void insertion_sort(data_* list, unsigned long length, bool ascending = true) {
            unsigned long sort_index, limit;
            data_ temp;
            for (limit = 1; limit < length; limit = limit + 1) {
                temp = list[sort_index = limit];
                while ((sort_index > 0) && (((ascending) && (list[sort_index - 1] >= temp)) || ((!ascending) && (list[sort_index - 1] <= temp)))) {
                    list[sort_index] = list[sort_index - 1];
                    sort_index = sort_index - 1;
                }
                list[sort_index] = temp;
            }
        }



        template <typename data_> void merge(data_* list, unsigned long lower_start, unsigned long mid_point, unsigned long upper_limit, bool ascending = true) {

            
            // create the two sublists.
            data_ left_list[mid_point - lower_start];
            data_ right_list[upper_limit - mid_point - 1];


            
            // fill the two sublists.
            unsigned long left_index, right_index, list_index;
            for (left_index = 0; left_index < mid_point - lower_start; left_index = left_index + 1) {
                left_list[left_index] = list[left_index + lower_start];
            }
            
            for (right_index = 0; right_index < upper_limit - mid_point; right_index = right_index + 1) {
                right_list[right_index] = list[right_index + mid_point];
            }
            
            //=======================================two sublists filled=======================================//

            // two sublists filled. Now refilling the list 
            left_index = right_index = 0;
            list_index = lower_start;
            
            while ((left_index < (mid_point - lower_start)) && (right_index < (upper_limit - mid_point))) {
                
                if (((ascending) && (left_list[left_index] < right_list[right_index])) || ((!ascending) && (left_list[left_index] > right_list[right_index]))) {
                    list[list_index] = left_list[left_index];
                    left_index = left_index + 1;
                }
                else {
                    list[list_index] = right_list[right_index];
                    right_index = right_index + 1;
                }
                list_index = list_index + 1;
            }

            while (left_index < mid_point - lower_start) {
                list[list_index] = left_list[left_index];
                left_index = left_index + 1;
                list_index = list_index + 1;
            }

            while (right_index < (upper_limit - mid_point)) {
                list[list_index] = right_list[right_index];
                right_index = right_index + 1;
                list_index = list_index + 1;
            }
            fprintf(stdout, "reached with lower_start : %lu, mid_point : %lu, upper_limit : %lu...\n", lower_start, mid_point, upper_limit);
            // fprintf(stdout, "Reached\n");
            // section sorted between lower_start and upper_limit

        }


        template <typename data_> void rec_merge_sort(data_* list, unsigned long start, unsigned long length, bool ascending = true) {

            if (start >= length) {
                return;
            }

            // get the midway point.
            unsigned long mid_index = start + (length - start) / 2;
            rec_merge_sort(list, start, mid_index, ascending);
            // fprintf(stdout, "Reached\n");
            rec_merge_sort(list, mid_index + 1, length, ascending);
            fprintf(stdout, "Reached with start of %lu, mid_index of %lu, and length of %lu.\n", start, mid_index, length);
            merge(list, start, mid_index, length, ascending);

        }


        template <typename data_> void merge_sort(data_* list, unsigned long length, bool ascending = true) {
            rec_merge_sort(list, 0, length, ascending);

        }



    }

    /*=====================================Useable useful functions=====================================*/


    /*=====================================Useful functions generic=====================================*/

    /**
     * @brief Get the absolute value of the data passed in.
     * 
     * @param val `(generic but defaulted to a signed long)` : The value whose
     * absolute value is to be returned.
     * 
     * @note Whatever data type is passed in is also returned.
     * @note Tested and works.
     * 
     * @returns `(generic data type)` the absolute value of the data that is passed in.
    */
    template <typename data_ = signed long> data_ absolute(data_ val) {
        return (val < 0) ? val * -1 : val;
    }



    /**
     * @brief Get the maximum of the two pieces of data passed in.
     * 
     * @note Both arguments passed in must have the same data type.
     * 
     * @param first `(generic)` : One of the two `generics` to be compared.
     * @param second `(generic)` : The other of the two `generics` to be compared.
     * 
     * @returns `(generic)` : The largest value of the two pieces of data passed in.
    */
    template <typename data_> data_ max_data(data_ first, data_ second) {
        return (first >= second) ? first : second;
    }



    /**
     * @brief Get the minimum of the two pieces of data passed in.
     * 
     * @note Both the arguments passed in must have the same data type.
     * 
     * @param first `(generic)` : One of the two `generics` to be compared.
     * @param second `(generic)` : The other of the two `generics` to be compared.
     * 
     * @returns `(generic)` : The smallest value of the two pieces of data passed in.
    */
    template <typename data_> data_ min_data(data_ first, data_ second) {
        return (first <= second) ? first : second;
    }



    /**
     * @brief Get the largest value in an array of a generic type of data.
     * 
     * @note Any piece of data can be passed in, but it must be capable of
     * the greater than or equal to & less than or equal to comparables.
     * 
     * @param list `(list)` : An array of length `length` whose largest piece of data is to be returned.
     * 
     * @param length `(length)` : The length of the array lassed in.
     * 
     * @note Not Tested. But pretty sure it works because it's based off
     * the max_data function which was tested and does work.
     * 
     * @returns `(unsigned long)` : The index of the largest piece of data in the list.
     * 
    */
    template <typename data_> unsigned long max_in_list(data_ list[], unsigned long length) {
        unsigned long the_answer = 0, index;
        for (index = 0; index < length; index = index + 1) {
            the_answer = (max_data(list[index], list[the_answer]) == list[index]) ? index : the_answer;
        }
        return the_answer;
    }



    /**
     * @brief Get the smallest value in an array of a generic type of data.
     * 
     * @note Any piece of data can be passed in, but it must be capable of
     * the greater than or equal to and less than or equal to comparables.
     * 
     * @param list `(Generic)` : An array of length `length` whose smallest piece of data is to be returned.
     * 
     * @param length `(length)` : The length of the array lassed in.
     * 
     * @note Not Tested. But pretty sure it works because it's based off
     * the min_data function which was tested and does work.
     * 
     * @returns `(unsigned long)` : The index of the smallest piece of data in the list.
     * 
    */
    template <typename data_> unsigned long min_in_list(data_ list[], unsigned long length) {
        unsigned long the_answer = 0, index;
        for (index = 0; index < length; index = index + 1) {
            the_answer = (min_data(list[index], list[the_answer]) == list[index]) ? index : the_answer;
        }
        return the_answer;
    }



    /**
     * @brief Get the index of the pointer that points to the largest piece of data.
     * 
     * @note Any piece of data can be passed in, but it must be capable of 
     * the greater than or equal to, and the less than or equal to comparables.
     * 
     * @param list (`Generic)` : An array of length `length` full of pointers.
     * 
     * @param length `(unsigned long)` : The length of the list to be searched.
     * 
     * @note Not Tested, but pretty sure it works because it's based off
     * the max_data which was tested and which works.
     * 
     * @returns `(unsigned long)` : The index with the pointer to the data 
     * that holds the largest data in the list.
     * 
    */
    template <typename data_> unsigned long max_data_ptr(data_* list[], unsigned long length) {
        unsigned long the_answer = 0, index;
        for (index = 0; index < length; index = index + 1) {
            the_answer = (max_data(*list[index], *list[the_answer]) == *list[index]) ? index : the_answer;
        }
        return the_answer;
    }



    /**
     * @brief Get the index of the pointer that points to the smallest piece of data.
     * 
     * @note Any piece of data can be passed in, but it must be capable of 
     * the greater than or equal to, and the less than or equal to comparables.
     * 
     * @param list (`Generic)` : An array of length `length` full of pointers.
     * 
     * @param length `(unsigned long)` : The length of the list to be searched.
     * 
     * @note Not Tested, but pretty sure it works because it's based off
     * the min_data which was tested and which works.
     * 
     * @returns `(unsigned long)` : The index with the pointer to the data 
     * that holds the smallest data in the list.
     * 
    */
    template <typename data_> unsigned long min_data_ptr(data_* list[], unsigned long length) {
        unsigned long the_answer = 0, index;
        for (index = 0; index < length; index = index + 1) {
            the_answer = (min_data(*list[index], *list[the_answer]) == *list[index]) ? index : the_answer;
        }
        return the_answer;
    }



    /**
     * @brief Get any base raised to a real number integer (negative or positive).
     * 
     * @note The function is still being worked on and won't work with any non integer powers.
     * 
     * Will exit program execution in failure if a non-integer is passed in.
     * 
     * @param base `(Generic)` : The base to be raised to a power.
     * 
     * @param pow `(Generic)` : The power to raise the base to.
     * 
    */
    template <typename b, typename p> b power(b base, p pow) {
        if (((pow > 0) && (absolute<p>(pow) < 1)) || (((p) (((long long) pow))))  != pow) {
            logic_not_implemented((char *) "useful_functions::power must have an integer base"); // will exit
        }
        if (pow == ((p) 0)) {
            return 1;
        }
        
        /* factorials */
        if (absolute<p>(pow) < 1) {
            return 0;
        }
        else {
            return base * ((pow > (p) 0) ? (power(base, pow - ((p) 1))) : (power(base, pow + ((p) 1))));
        }
        
    }







    /*=====================================useful functions chars=====================================*/







    /**
     * @brief Check if a character is a capital letter or not.
     * 
     * @note Does not error handle.
     * 
     * @param c `(char)` : The char to be checked to see if it's an
     * upper case character or not.
     * 
     * @returns `(bool)` : true if the char passed in is a capital letter, false if not.
    */
    bool is_caps(char c) {
        return (c >= A) && (c <= Z);
    }



    /**
     * @brief Check if the character passed in is a lower case letter.
     * 
     * @note Does not error handle.
     * 
     * @param c `(char)` : The char to be checked to see if it's a 
     * lower case character or not.
     * 
     * @returns `(bool)` : true if the char passed in is a lower case letter, false if not.
    */
    bool is_lower(char c) {
        return (c >= a) && (c <= z);
    }



    /**
     * @brief Check if the character passed in is a number or not.
     * 
     * @note Does not error handle.
     * 
     * @param c `(char)` : The char to be checked to see if it's a 
     * number or not.
     * 
     * @returns `(bool)` : true if the char passed in is a number, false if not.
    */
    bool is_number(char c) {
        return (c >= zero) && (c <= nine);
    }



    /**
     * @brief Check if the character passed in is a letter.
     * 
     * @note Does not error handle.
     * 
     * @param c `(char)` : The char to be checked to see if it's a 
     * letter or not.
     * 
     * @returns `(bool)` : true if the char passed in is a letter, false if not.
    */
    bool is_letter(char c) {
        return is_caps(c) || is_lower(c);
    }



    /**
     * @brief Returns the capital case form of the character passed in.
     * 
     * @note A char must be passed in. If the char passed in is not a letter, 
     * then the char is returned as is.
     * 
     * @note If the char is a lower case letter, it 
     * is converted to it's uppercase form.
     * 
     * @note If the char is an upper case letter, the same char is returned.
     * 
     * @param c `(char)` : The char whose upper case form is to be returned.
     * 
     * @returns `(bool)` : The capital case form of the char passed in.
    */
    char to_caps(char c) {
        return (is_letter(c) && is_lower(c)) ? c - case_diff : c;
    }



    /**
     * @brief Returns the lower case form of the character passed in.
     * 
     * @note A char must be passed in. If the char passed in is not a letter, 
     * then the char is returned as is.
     * 
     * @note If the char is an upper case letter, it 
     * is converted to it's lower case form.
     * 
     * @note If the char is a lower case letter, the same char is returned.
     * 
     * @param c `(char)` : The char whose lower case form is to be returned.
     * 
     * @returns `(bool)` : The lower case form of the char passed in.
    */
    char to_lower(char c) {
        return (is_letter(c) && is_caps(c)) ? c + case_diff : c;
    }



    /**
     * @brief Get the length of the char* passed in.
     * 
     * @note This is not a C++ std::string. This is a char pointer 
     * whose length is being retrieved.
     * 
     * @param the_string `(char*)` : The char* whose length is to be 
     * retrieved.
     * 
     * @returns `(unsigned long)` : The length of the char* passed in.
    */
    unsigned long string_length(char* the_string) {
        unsigned long the_answer = 0;
        for (; the_string[the_answer] != '\0'; the_answer++);
        return the_answer;
    }



    /**
     * @brief Check if the two chars passed in are the same character or not, 
     * with an option to ignore the cases while comparing them.
     * 
     * @param a `(char)` : One of the two chars to be compared.
     * 
     * @param b `(char)` : The other char to be compared.
     * 
     * @param ignore_case `(bool. Defaults to true)` : A bool flag indicating 
     * whether or not to ignore cases when comparing the two chars.
     * 
     * @returns `(bool)` : true if the two chars are the same char, 
     * and false if they are not, depending on how the ignore_case flag was set.
    */
    bool same_char(char a, char b, bool ignore_case = true) {
        return is_letter(a) && is_letter(b) ? to_caps(a) == to_caps(b) : a == b;
    }



    /**
     * @brief This checks the `first char*` and the `sec char*` to see if they 
     * are the same or not. Optionally, cases can be ignored depending on what 
     * the flag `ignore_case` is set to.
     * 
     * @param first `(char*)` : The first string to be compared to the `sec`.
     * 
     * @param sec `(char*)` : The second string to be compared to the `first`.
     * 
     * @returns `(bool)` : true if the two `char*` pointers are the same, 
     * and false otherwise.
    */
    bool same_string(char* first, char* sec, bool ignore_case = true) {
        unsigned long index;
        for (index = 0; first[index] != '\0' && sec[index] != '\0'; index++) {
            if (!same_char(first[index], sec[index], ignore_case)) {
                // fprintf(stdout, "Determined that %c and %c are not the same\n", first[index], sec[index]);
                return false;
            }
        }
        return (first[index] == sec[index] && first[index] == '\0');
    }


    template <typename data_> void sort_list(data_ list[], unsigned long length, char* sort = (char*) "bubble", bool ascending = true) {
        
        if (same_string((char*) "bubble", sort)) {
            bubble_sort<data_>(list, length, ascending);
        }

        else if (same_string((char *) "selection", sort)) {
            selection_sort<data_>(list, length, ascending);
        }

        else if (same_string((char *) "insertion", sort)) {
            insertion_sort<data_>(list, length, ascending);
        }

        else if (same_string((char *) "merge", sort)) {
            merge_sort(list, length - 1, ascending);
        }

        else {
            fprintf(stdout, "Not yet implemented %s\n for sorting algorithms", sort);
        }

    }


}