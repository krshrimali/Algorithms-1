#ifndef utils_H
#define utils_H

#include <vector>
#include <string>
#include <iostream>

void aSuccess(std::string);
void aFailure(std::string);


#define ASSERT_EQUAL(X, Y) \
    if (X != Y) \
        aFailure(std::to_string(X) + " not equal to " + std::to_string(Y)); \
    else \
        aSuccess(std::to_string(X) + " equal to " + std::to_string(Y));

template <typename>
struct is_std_vector : std::false_type {};

template <typename T, typename A>
struct is_std_vector<std::vector<T, A>> : std::true_type {};

template <typename T>
int8_t calcDimension(std::vector<T>&);

// Example Vector:
// {
//   { 1, 2, 3 }
//   { 4, 5, 6 }
//   { 7, 8, 9 }
// }
// x[0:2] output should be
// { { 1, 2, 3 }, { 4, 5, 6 } } 
template <typename T>
std::vector<T> sliceVector1d(std::vector<T>, int, int);

template <typename T>
std::vector<int> flatten(std::vector<T>);

template <typename T>
void _print_vector_oneD(T);

template <typename T>
void _print_vector_twoD(T);

template <typename T>
void _print_vector_threeD(T);

template <typename T>
void _print_vector(T, int);

template <typename T>
void print_vector(std::vector<T>);

template <typename T>
void add_element(std::vector<T>&, T);

#endif