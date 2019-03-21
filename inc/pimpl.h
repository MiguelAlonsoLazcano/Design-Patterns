/*
 * Implementing PIMPL
 * Pointer to implementation, used for decouple the implementation from the use
 * Provides a method to hide the functionality details and dependencies of a class
 * interface in its header file
 * */

#pragma once

#include <cstdlib>

class Container
{
    // non-copyable
    Container (const Container& other);
    Container&operator =(const Container& other);

    // forward declaration to implementation
    class Impl;

    // pointer to implementation
    // delegates its operations to its implementation
    Impl* _impl;
public:
    Container (const size_t size);

    int& operator[] (const int index);
    const int&operator[] (const int index) const;
};

