# Understanding how Vectors work (Part-1): push_back

This blog is focused to explain how vectors work in the backend, and we'll specially look at `push_back` method of the vector container. Looking at the source code helps to understand the implementation, and how vectors can be used efficiently.

Vector Containers are type of sequenced containers in C++ commonly uses as a better alternative of arrays. They are also known as dynamic arrays, and as the term suggests - it's one of the advantages they hold over native arrays in C++. You might have heard of STL containers like `vector`, `set`, `queue`, `priority_queue` before. They all have base methods inherited from STL Containers class that we will discuss later.

Let's start with a basic comparison of using arrays and vectors in C++:

```cpp
// Create an array of fixed size: 10
int* InputArray = new int[10];
for (int i = 0; i < 10; i++) {
    // Let's assign values to the array
    // Values are same as indices
    InputArray[i] = i;
}
```

We can do the same (from what you see above) using `vector`:

```cpp
// Include this to be able to use vector container
#include <vector>

std::vector<int> InputVector {};
for (int i = 0; i < 10; i++) {
    InputVector.push_back(i);
}
```

While both do the same, but there are many important differences that happen in the backend. Let's start with performance.

* The piece of code using vector containers in C++ took 23.834 microseconds.
* The piece of code using arrays in C++ took 3.26 microseconds.

If we had to do this for 10k numbers, the performance might be significant:

* The piece of code using vector containers in C++ (for 10k numbers) took 713 microseconds.
* The piece of code using arrays in C++ took 173 microseconds.

As in software development, there is always a tradeoff. Since vectors aim to provide dynamic memory allocation, they lose some performance while trying to `push_back` elements in the vectors since the memory is not allocated before. This can be constant if memory is allocated before.

Let's try to infer this from the source code of vector container. The signature of a vector container looks like this:

```cpp
template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
    class vector : protected _Vector_base<_Tp, _Alloc>
```

Where `_Tp` is the type of element, and `_Alloc` is the allocator type (defaults to `std::allocator<_Tp>`). Let's start from the constructor of `vector` (when no parameter is passed):

```cpp
#if __cplusplus >= 201103L
      vector() = default;
#else
      vector() { }
#endif
```

The constructor when called with no params, creates a vector with no elements. As always, there are various ways to initialize a vector object.

I want to focus more on `push_back` today, so let's take a look at it's signature. It's located in `stl_vector.h` file.

```cpp
// Note that value_type is defined as: typedef _Tp value_type as a public type
void push_back(const value_type& __x)
{
    if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
    {
        _GLIBCXX_ASAN_ANNOTATE_GROW(1);
        _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
                        __x);
        ++this->_M_impl._M_finish;
        _GLIBCXX_ASAN_ANNOTATE_GREW(1);
    }
    else
        _M_realloc_insert(end(), __x);
}
```