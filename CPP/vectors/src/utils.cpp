#include "utils.h"

public class VectorUtils {
private:
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
        // TODO: Calculates dimension of Input Vector
        return InputVector.size();    
    }
 
    template <typename T>
    void _print_vector_oneD(T InputVector) {
        for (size_t i = 0; i < InputVector.size(); i++) {
            std::cout << InputVector[i] << " ";
        }
        std::cout << std::endl;
    }

    template <typename T>
    void _print_vector_twoD(T InputVector) {
        for (size_t i = 0; i < InputVector.size(); i++) {
            for (size_t j = 0; j < InputVector[i].size(); j++) {
                std::cout << InputVector[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    template <typename T>
    void _print_vector_threeD(T InputVector) {
        for (size_t i = 0; i < InputVector.size(); i++) {
            for (size_t j = 0; j < InputVector[i].size(); j++) {
                for(size_t k = 0; k < InputVector[j].size(); k++) {
                    std::cout << InputVector[i][j][k] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    template <typename T>
    void _print_vector(T InputVector, int dimension) {
        if (dimension == 1) {
            // typedef typename T::value_type _I_InputVector;
            _print_vector_oneD<int>(InputVector);
        } else if (dimension == 2) {
            _print_vector_twoD<int>(InputVector);
        } else if (dimension == 3) {
            _print_vector_threeD<int>(InputVector);
        }
        else std::cout << "Dimension not supported yet" << std::endl;
    }
public: 
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
    std::vector<int> flatten(std::vector<T> InputVector) {
        // Calculate dimension of Input Vector
        std::vector<int> ret;
        for (size_t i = 0; i < InputVector.size(); i++) {
            ret.insert(ret.end(), InputVector[i].begin(), InputVector[i].end());
        }
        return ret;
    } 

    template <typename T>
    void print_vector(std::vector<T> InputVector) {
        // _I_InputVector means Inside InputVector
        typedef typename std::vector<T>::value_type _I_InputVector;
        // std::cout << is_std_vector<_I_InputVector>::value << std::endl;
        if (is_std_vector<_I_InputVector>::value == true) {
            // that means it's dimension is >= 2
            typedef typename T::value_type _II_InputVector;
            if (is_std_vector<_II_InputVector>::value == true) {
                // means it's dimension is >= 3
                _print_vector_threeD<std::vector<std::vector<std::vector<_II_InputVector>>>>(&InputVector);
            } else {
                // _print_vector<std::vector<std::vector<_II_InputVector>>>(InputVector, /*dimension=*/ 2);
                _print_vector_twoD<std::vector<std::vector<_II_InputVector>>>(InputVector);
            }
        } else {
            // typedef typename T::value_type _example;
            // _print_vector<std::vector<_example>>(InputVector, /*dimension=*/ 1);
            _print_vector_oneD<std::vector<_I_InputVector>>(InputVector);
        }
    }

    template <typename T>
    void add_element(std::vector<T>& inputVector, T element) {
        // This function just adds an element to the inputVector
        // But uses value_type, just a way to understand how we can use value_type
        typedef typename std::vector<T>::value_type _Tp;
        _Tp x = element;
        inputVector.push_back(x);
    }
}
