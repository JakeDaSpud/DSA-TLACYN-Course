// Binary Searching through an ORDERED boolean Array
// Time Complexity: O(sqrt(n))
// Lesson: "Implementing Two Crystal Balls"

#include <math.h>
#include <assert.h>
#include <iostream>

/// @param breaks[] a boolean array, false where the ball doesn't break, true where it does
/// @param breaks_size number of elements in the breaks[] array
/// @return index of first true in the array
int two_crystal_balls(bool breaks[], int breaks_size) {
    int jumpAmount = floor(sqrt(breaks_size));

    int i = jumpAmount;

    // Keep jumping forward sqrt(n), until the ball breaks (i.e. the element is true)
    for (; i < breaks_size; i += jumpAmount) {
        if (breaks[i]) {
            break;
        }
    }

    // If we get to the end of the Array, or we broke out of the previous loop, we walk back one sqrt(n) and walk it forward linearly
    i -= jumpAmount;

    for (int j = 0; j < jumpAmount && i < breaks_size; j++, i++) {
        if (breaks[i] == true) {

            // Found element at this index, return it
            return i;
        }
    }

    // Never found the element in the Array, return sentinel
    return -1;
}

// THESE TESTS DO NOT REFLECT THE CODE PROPERLY, I THINK I DO NOT KNOW HOW TO TEST IT RIGHT??
void run_tests() {
    int test_result;

    bool test_array_1[500] = {
        false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,
        true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true
    };
    test_result = two_crystal_balls(test_array_1, 250);
    std::cout << test_result << std::endl;
    //assert(test_result == 2);

    if (test_result == 250) { std::cout << "Test 1 Passed with index: " << test_result << std::endl;
    } else { std::cout << "Test 1 Failed... index" << test_result << std::endl; }

    bool test_array_2[5] = {false, false, false, false, true};
    test_result = two_crystal_balls(test_array_2, 5);
    //assert(test_result == 4);

    if (test_result == 4) { std::cout << "Test 2 Passed with index: " << test_result <<std::endl;
    } else { std::cout << "Test 2 Failed... index" << test_result << std::endl; }
}

int main(int argc, char const *argv[])
{
    run_tests();
    return 0;
}
