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

        const char* esc_start = "\033[";
        const char* esc_stop = "\033[m";
        

        const char* merge_const = "merge";
        const char* select_const = "select";
        const char* insert_const = "insert";
        const char* bubble_const = "bubble";


        const char case_diff = 'a' - 'A';
        const char A = 'A', Z = 'Z', a = 'a', z = 'z', zero = '0', nine = '9';

        bool valid_text_color(us color) {
            return ((color) >= (us) black_txt) && (color <= (us) white_txt);
        }

        bool valid_style(us color) {
            return (color >= (us) no_style) && (color <= (us) neg_1_style) || (color == (us) neg_2_style);
        }

        bool valid_bkg_color(us color) {
            return (color >= (us) black_bkg) && (color <= (us) default_bkg);
        }

        template <typename data_> void swap(data_& first, data_& second) {
            data_ temp = first;
            first = second;
            second = first;
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
     * the greater than or equal to & less than or equal to comparables.
     * 
     * @param list `(list)` : An array of length `length` whose smallest piece of data is to be returned.
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


    template <typename data_> unsigned long max_data_ptr(data_* list[], unsigned long length) {
        unsigned long the_answer = 0, index;
        for (index = 0; index < length; index = index + 1) {
            the_answer = (max_data(*list[index], *list[the_answer]) == *list[index]) ? index : the_answer;
        }
        return the_answer;
    }


    template <typename data_> unsigned long min_data_ptr(data_* list[], unsigned long length) {
        unsigned long the_answer = 0, index;
        for (index = 0; index < length; index = index + 1) {
            the_answer = (min_data(*list[index], *list[the_answer]) == *list[index]) ? index : the_answer;
        }
        return the_answer;
    }


    /*=====================================useful functions chars=====================================*/


    bool is_caps(char c) {
        return (c >= A) && (c <= Z);
    }

    bool is_lower(char c) {
        return (c >= a) && (c <= z);
    }

    bool is_number(char c) {
        return (c >= zero) && (c <= nine);
    }

    bool is_letter(char c) {
        return is_caps(c) || is_lower(c);
    }

    char to_caps(char c) {
        return (is_letter(c) && is_lower(c)) ? c - case_diff : c;
    }

    char to_lower(char c) {
        return (is_letter(c) && is_caps(c)) ? c + case_diff : c;
    }

    unsigned long string_length(char* the_string) {
        unsigned long the_answer = 0;
        for (; the_string[the_answer] != '\0'; the_answer++);
        return the_answer;
    }

    bool same_char(char a, char b, bool ignore_case = true) {
        return is_letter(a) && is_letter(b) ? to_caps(a) == to_caps(b) : a == b;
    }

    bool same_string(char* first, char* sec, bool ignore_case = true) {
        unsigned long index;
        for (index = 0; first[index] != '\0' && sec[index] != '\0'; index++) {
            if (!same_char(first[index], sec[index], ignore_case)) {
                return false;
            }
        }
        return (first[index] == sec[index] == '\0');
    }


}