#include <iostream>
#include <new> // for nothrow object

int main() {
    int input_size;
    std::cout << "Input Size: ";
    std::cin >> input_size;
    // Using std::nothrow points p pointer to nullptr in case of bad memory alloc
    // This is declared in new header
    int* p = new (std::nothrow) int[input_size];
    // p will point to null pointer in case of bad memory alloc
    if (p == nullptr) {
        std::cout << "Unable to allocate memory, exiting..." << std::endl;
        return EXIT_FAILURE;
    } else {
        std::cout << "Memory allocated successfully" << std::endl;
        for (int i = 0; i < input_size; i++) {
            std::cout << p[i] << std::endl;
            p[i] = 100;
        }
        // Let's free the block of memory allocated to p, for other variables/arrays to reference and allocate memory in that block
        delete[] p;
    }
    return EXIT_SUCCESS;
}