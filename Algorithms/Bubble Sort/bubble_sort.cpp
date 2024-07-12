// Bubble Sorting an Array
// Sort-in-place Algorithm
// Time Complexity: O(n^2)
// Lesson: "Implementing Bubble Sort"

#include <assert.h>
#include <iostream>

void bubble_sort(int arr[], int arr_size) {

    // Go through every element
    for (int i = 0; i < arr_size; i++) {

        // Don't include last element (we have a + 1 in the code)
        // Don't include whatever the i is, as we know every i puts the next largest element on the end
        for (int j = 0; j < arr_size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {

                // Temporary int way
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // XOR bit masking way (no temporary int)
                //arr[j] = arr[j] ^ arr[j + 1];
                //arr[j + 1] = arr[j] ^ arr[j + 1];
                //arr[j] = arr[j] ^ arr[j + 1];
            }
        }

    }
}

void run_tests() {
    int test1[5] = {9, 6, 4, 2, 0};
    int test1_sorted[5] = {0, 2, 4, 6, 9};

    bubble_sort(test1, 5);

    for (int i = 0; i < 5; i++) {
        assert(test1[i] == test1_sorted[i]);
    }

    std::cout << "Test 1 Passed" << std::endl;

    
    int test2[10] = {120, 6, 280, 321, 100, 320, 9, 127, 3, 300};
    int test2_sorted[10] = {3, 6, 9, 100, 120, 127, 280, 300, 320, 321};

    bubble_sort(test2, 10);

    for (int i = 0; i < 10; i++) {
        assert(test2[i] == test2_sorted[i]);
    }

    std::cout << "Test 2 Passed" << std::endl;

    std::cout << "Finished Tests" << std::endl;

}

int main(int argc, char const *argv[])
{
    run_tests();
    return 0;
}
