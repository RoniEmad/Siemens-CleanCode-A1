#include <iostream>
#include <cassert>
#include <array>

using namespace std;

/*
    You need to refactor the following function using clean code guidelines
        - Meaningful names
        - Functions
        - Comments
        - Formatting
        - Error Handling
    After finishing, you are requested to write unite tests below in the main code for the function.
*/

// Assignemnt Answer by: Roni Emad

int arraySum(int array[], int startIndex, int size) {

    if(array == nullptr){
        throw std::invalid_argument("Error: Invalid array (null pointer)");
    }
    if(startIndex < 0){
        throw invalid_argument("Error: Start Index < 0");
    }
    if(size < 1){
        throw invalid_argument("Error: Size < 1");
    }
    if(startIndex >= size){
        throw invalid_argument("Error: Start Index >= Size");
    }

    int sum = 0;
    for(int i = startIndex; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int main () {
    // Unit tests
    int array[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);

    // Test 1: Valid range
    int startIndex1 = 1;
    int sum1 = arraySum(array, startIndex1, size);
    assert(sum1 == 20);

    cout << "Test 1 passed!" << endl;

    // Test 2: Valid range (full array)
    int startIndex2 = 0;
    int sum2 = arraySum(array, startIndex2, size);
    assert(sum2 == 21);

    cout << "Test 2 passed!" << endl;

    // Test 3: Valid range (just below the limit)
    int startIndex3 = size - 1;
    int sum3 = arraySum(array, startIndex3, size);
    assert(sum3 == array[size - 1]);

    cout << "Test 3 passed!" << endl;

    // Test 4: Valid range (part of the array)
    int startIndex4 = 0;
    int size4 = 4;
    int sum4 = arraySum(array, startIndex4, size4);
    assert(sum4 == 10);

    cout << "Test 4 passed!" << endl;

    // Test 5: Invalid range (startIndex = size)
    try{
        int startIndex5 = size;
        arraySum(array, startIndex5, size);
        // The code should not reach this point due to the exception
        assert(false);
    }
    catch(const std::invalid_argument& e) {
        cout << "Test 5 passed! (" << e.what() << ")" << endl;
    }

    // Test 6: Invalid range (startIndex > size)
    try{
        int startIndex6 = size + 1;
        arraySum(array, startIndex6, size);
        // The code should not reach this point due to the exception
        assert(false);
    }
    catch(const std::invalid_argument& e) {
        cout << "Test 6 passed! (" << e.what() << ")" << endl;
    }

    // Test 7: Invalid range (size < 1)
    try{
        int startIndex7 = 0;
        int size7 = 0;
        arraySum(array, startIndex7, size7);
        // The code should not reach this point due to the exception
        assert(false);
    }
    catch(const std::invalid_argument& e) {
        cout << "Test 7 passed! (" << e.what() << ")" << endl;
    }

    // Test 8: Invalid range (start index < 0)
    try{
        int startIndex8 = -1;
        arraySum(array, startIndex8, size);
        // The code should not reach this point due to the exception
        assert(false);
    }
    catch(const std::invalid_argument& e) {
        cout << "Test 8 passed! (" << e.what() << ")" << endl;
    }

    // Test 9: Invalid array (nullptr)
    try{
        int* nullArray = nullptr;
        int startIndex9 = 0;
        int size9 = 5; // Size doesn't matter since the array is invalid
        arraySum(nullArray, startIndex9, size9);
        // The code should not reach this point due to the exception
        assert(false);
    }
    catch(const std::invalid_argument& e) {
        cout << "Test 9 passed! (" << e.what() << ")" << endl;
    }

    std::cout << "All unit tests passed!" << std::endl;

    return 0;
}
