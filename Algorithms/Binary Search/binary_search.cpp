// Binary Searching through an ORDERED Array
// Time Complexity: O(log n)
// Lesson: "Implementing Binary Search"

#include <cmath>
#include <iostream>
#include <assert.h>

bool binary_search(int haystack[], int haystack_size, int needle) {
    
    int lo = 0;
    int hi = haystack_size;
    
    do {
        int m = std::floor(lo + (hi - lo) / 2);
        int v = haystack[m];

        // Found the value
        if (v == needle) {
            return true;
        }

        // Value is in the left side of the searching area
        else if (v > needle) {
            hi = m;
        }

        // Value is in the right side of the searching area
        else {
            lo = m + 1;
        }

    } while (lo < hi);

    // Number not found
    return false;
}

void run_tests() {
    bool test_result;

    int test_array_1[4] = {4, 6, 9, 10};
    test_result = binary_search(test_array_1, 4, 9);
    assert(test_result == true);

    if (test_result == true) { std::cout << "Test 1 Passed with result: true" << std::endl;
    } else { std::cout << "Test 1 Failed..." << std::endl; }

    int test_array_2[5] = {0, 3, 7, 10, 28};
    test_result = binary_search(test_array_2, 5, 29);
    assert(test_result == false);

    if (test_result == false) { std::cout << "Test 2 Passed with result: false" << std::endl;
    } else { std::cout << "Test 2 Failed..." << std::endl; }
}

int main(int argc, char const *argv[])
{
    run_tests();
    return 0;
}
