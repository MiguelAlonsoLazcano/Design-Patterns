/*
 * Implementing SMART POINTER
 * Provides a mechanism to manage resources, can be used to
 * manage the time life of a dynamically allocated object
 * */

#pragma once

#include <iostream>

template <typename T>
class Ptr {
    T* _ptr;

    // Prevent copying
    Ptr(const Ptr&);
    Ptr& operator=(const Ptr&);

public:
    explicit Ptr(T* p = 0) : _ptr(p){}
    ~Ptr() { delete _ptr; }

    T* operator->() const { return _ptr; }
    T& operator*() const { return *_ptr; }
};
