// This file includes all the utility functions which might be useful in our other projects
#include "utils.h"

#define ASSERT_EQUAL(X, Y) \
    if (X != Y) \
        aFailure(std::to_string(X) + " not equal to " + std::to_string(Y)); \
    else \
        aSuccess(std::to_string(X) + " equal to " + std::to_string(Y));

void aFailure(std::string failureMessage) {
    std::cout << failureMessage << std::endl;
    std::cout << "Exiting..." << std::endl;
    exit(EXIT_FAILURE);
}

void aSuccess(std::string successMessage) {
    std::cout << successMessage << std::endl;
}

template <typename T>
int8_t calcDimension(std::vector<T>& InputVector) {
    // Calculates dimension of Input Vector
    // This needs work
    return InputVector.size();    
}

// Example Vector:
// {
//   { 1, 2, 3 }
//   { 4, 5, 6 }
//   { 7, 8, 9 }
// }

// x[0:2] output should be
// { { 1, 2, 3 }, { 4, 5, 6 } } 
template <typename T>
std::vector<T> sliceVector1d(std::vector<T> InputVector, int begin, int end) {
    // First assert vector is of 1 Dimension
    // ASSERT_EQUAL(calcDimension(InputVector), 1); 

    std::vector<T> slicedInputVector;
    for (int i = 0; i < InputVector.size(); i++) {
        if (i >= begin && i < end) {
            slicedInputVector.push_back(InputVector[i]);
        }
    }
    return slicedInputVector;
}

template <typename T>
std::vector<T> flatten(std::vector<T>& InputVector) {
    // Calculate dimension of Input Vector
    std::vector<T> ret;
    for (int i = 0; i < InputVector.size(); i++) {
        InputVector.insert(ret.end(), InputVector[i].begin(), InputVector[i].end());
    }
    return ret;
}

template <typename T>
void print_vector(const std::vector<T> InputVector) {
    for (int i = 0; i < InputVector.size(); i++) {
        for (int j = 0; j < InputVector[i].size(); j++) {
            std::cout << InputVector[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Add test here
int main() {
    std::cout << std::boolalpha;
    std::vector<std::vector<int>> X { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    X = sliceVector1d<std::vector<int>>(X, 0, 2);
    print_vector<std::vector<int>>(X);
    check_array();
}
