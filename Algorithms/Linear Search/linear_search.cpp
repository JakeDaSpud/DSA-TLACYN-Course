// Linear Searching through an Array
// Time Complexity: O(n)
// Lesson: "Linear Search & Kata Setup"

#include <iostream>
#include <assert.h>

bool linear_search(int haystack[], int haystack_size, int needle) {
    for (int i = 0; i < haystack_size; i++) {
        if (haystack[i] == needle) {
            return true;
        }
    }

    return false;
}

void run_tests() {
    bool test_result;

    int test_array_1[3] = {2, 4, 5};
    test_result = linear_search(test_array_1, 3, 5);
    assert(test_result == true);

    if (test_result == true) { std::cout << "Test 1 Passed with result: true" << std::endl;
    } else { std::cout << "Test 1 Failed..." << std::endl; }

    int test_array_2[5] = {0, 3, 7, 10, 28};
    test_result = linear_search(test_array_2, 5, 9);
    assert(test_result == false);

    if (test_result == false) { std::cout << "Test 2 Passed with result: false" << std::endl;
    } else { std::cout << "Test 2 Failed..." << std::endl; }
}

int main(int argc, char const *argv[])
{
    run_tests();
    return 0;
}
