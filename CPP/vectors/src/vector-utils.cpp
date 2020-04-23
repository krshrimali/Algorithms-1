// This file includes all the utility functions which might be useful in our other projects
#include "utils.h"
#include <type_traits>

// Add test here
int main() {
    std::cout << std::boolalpha;
    std::vector<std::vector<int>> X { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    X = sliceVector1d<std::vector<int>>(X, 0, 2);
    X.at(0);
    // print_vector<std::vector<int>>(X);
    std::cout << "Now pushing 10, 11, 12 to the vector. " << std::endl;
    add_element<std::vector<int>>(X, {10, 11, 12});
    std::cout << "After pushing 10, 11, 12: vector is: " << std::endl;
    // print_vector<std::vector<int>>(X);
    typedef typename std::vector<int>::value_type _II_InputVector;
    _print_vector_twoD<std::vector<std::vector<_II_InputVector>>>(X);
    
    // std::cout << "Flatten the vector now: " << std::endl;
    // std::vector<int> flattened_X = flatten<std::vector<int>>(X);
    // print_vector<int>(flattened_X);
    // std::cout << is_std_vector<std::vector<int>>::value << std::endl;
    // std::vector<std::vector<std::vector<int>>> X_threeD = { { {1, 2, 3}, {4, 5, 6}},  { {7, 8, 9}, {10, 11, 12} }};
    // std::cout << "printing three dimension" << std::endl;
    // _print_vector_threeD<std::vector<std::vector<std::vector<int>>>> (X_threeD);
}