







namespace useful_functions {

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

}