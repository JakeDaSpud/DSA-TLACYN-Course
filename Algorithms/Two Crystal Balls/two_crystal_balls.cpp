// Binary Searching through an ORDERED boolean Array
// Time Complexity: O(sqrt(n))
// Lesson: "Implementing Two Crystal Balls"

#include <math.h>
#include <assert.h>
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>

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

    // Small tweak to the algo here, "j <= jumpAmount" used to just be <, which means that we can't return the very last element! A test case i had...
    for (int j = 0; j <= jumpAmount && i < breaks_size; j++, i++) {
        if (breaks[i] == true) {

            // Found element at this index, return it
            return i;
        }
    }

    // Never found the element in the Array, return sentinel
    return -1;
}

void run_tests() {

    // This whole random test is adapted from other JS implementations i've looked up
    std::srand((int) std::time(0));
    const int data_size = 10000;
    int index = floor((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 10000);
    bool data[data_size] = {false};

    for (int i = index; i < data_size; i++) {
        data[i] = true;
    }

    assert(two_crystal_balls(data, data_size) == index);
    std::cout << "Random Test 01: Passed with index: " << index << std::endl;

    int test_result;

    bool test_array_1[1000] = {
        false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,
        false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,false, false, false, false, false,
        true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,
        true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true,true, true, true, true, true
    };
    test_result = two_crystal_balls(test_array_1, 1000);

    if (test_result == 500) { std::cout << "Test 01: Passed with index: " << test_result << std::endl;
    } else { std::cout << "Test 01: Failed with index: " << test_result << std::endl; }
    assert(test_result == 500);

    bool test_array_2[5] = {false, false, false, false, true};
    test_result = two_crystal_balls(test_array_2, 5);

    if (test_result == 4) { std::cout << "Test 02: Passed with index: " << test_result <<std::endl;
    } else { std::cout << "Test 02: Failed with index: " << test_result << std::endl; }
    assert(test_result == 4);
}

int main(int argc, char const *argv[])
{
    run_tests();
    return 0;
}
