

#define useful_functions_h "useful_functions.h"





namespace useful_functions {

    const char case_diff = 'a' - 'A';

    template <typename data_> data_ absolute(data_ value) {
        return ((value < 0) ? (data_) (value * -1) : (data_) value);
    }

    template<typename data_> data_* absolute(data_* value) {
        if (*value < 0) {
            *value = (data_) (*value * -1);
        }
        return value;
    }

    template <typename data_> data_ max(data_ a, data_ b, bool abs) {
        if (abs) {
            if (a == b) {
                return a;
            }
            return (absolute(a) > absolute(b)) ? a : b;
        }
        return (a >= b) ? a : b;
    }

    template <typename data_> data_* max(data_* a, data_* b, bool abs) {
        if (abs) {
            if (*a == *b) {
                return a;
            }
            return (absolute(*a) > absolute(*b)) ? a : b;
        }
        return (*a >= *b) ? a : b;
    }

    template <typename data_> data_* max(unsigned int len, data_* arr[], bool abs = false) {
        unsigned int index;
        data_* the_answer = arr[0];
        for (index = 1; index < len; index = index + 1) {
            the_answer = max(arr[index], the_answer, abs);
        }
        return the_answer;
    }

    template <typename data_> data_ min(data_ a, data_ b, bool abs) {
        if (abs) {
            if (a == b) {
                return a;
            }
            return (absolute(a) < absolute(b)) ? a : b;
        }
        return (a <= b) ? a : b;
    }

    template <typename data_> data_* min(data_* a, data_* b, bool abs) {
        if (abs) {
            if (*a == *b) {
                return a;
            }
            return (absolute(*a) < absolute(*b)) ? a : b;
        }
        return (*a <= *b) ? a : b;
    }

    template <typename data_> data_* min(unsigned int len, data_* arr[], bool abs = false) {
        unsigned int index;
        data_* the_answer = arr[0];
        for (index = 1; index < len; index = index + 1) {
            the_answer = min(the_answer, arr[index], abs);
        }
        return the_answer;
    }

    template<typename data_ = signed long> data_ difference(data_ first, data_ second, bool abs = false) {
        data_ the_answer;
        if (abs) {
            the_answer = max<data_>(first, second) - min<data_>(first, second);
        }
        else {
            the_answer = first - second;
        }
        return the_answer;
    }

    bool is_caps(char c) {
        return ((c >= 'A') && (c <= 'Z')) ? true : false;
    }

    bool is_lower(char c) {
        return ((c >= 'a') && (c <= 'z')) ? true : false;
    }

    bool is_letter(char c) {
        return ((is_caps(c)) || (is_lower(c))) ? true : false;
    }

    char to_caps(char c) {
        return ((is_letter(c)) && (is_lower(c))) ? (c - case_diff) : c;
    }

    char to_lower(char c) {
        return ((is_letter(c)) && (is_caps(c))) ? (c + case_diff) : c;
    }

    unsigned long string_length(char* the_string) {
        unsigned long the_answer;
        for (the_answer = 0; the_string[the_answer] != '\0'; the_answer = the_answer + 1) {}
        return the_answer;
    }

    bool same_char(char first, char second, bool ignore_case = true) {
        if (ignore_case) {
            // std::cout << "\t\tto_caps(first) : " << to_caps(first) << ", to_caps(second) : " << to_caps(second) << std::endl;
            // std::cout << "\t\t\tabout to return " << std::to_string((to_caps(first) == to_caps(second)) ? true : false) << std::endl;
            return (to_caps(first) == to_caps(second)) ? true : false;
        }
        return (first == second) ? true : false;
    }

    bool same_string(char* first, char* second, bool ignore_case = true) {
        unsigned long index;
        for (index = 0; first[index] != '\0' && second[index] != '\0'; index = index + 1) {
            if (!same_char(first[index], second[index], ignore_case)) {
                // std::cout << "\t\"" << first[index] << "\", and \"" << second[index] << "\" are different" << std::endl;
                return false;
            }
            // std::cout << "Continuing...";
        }
        return ((first[index] == second[index]) && (first[index] == '\0')) ? true : false;
    }

}