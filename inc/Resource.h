/*
 * Implementing SMART POINTER
 * Provides a mechanism to manage resources, can be used to
 * manage the time life of a dynamically allocated object
 * */

#pragma once

#include <iostream>

class Resource {
public:
    Resource()
    {
        std::cout << " Creating resource" << std::endl;
    }
    ~Resource()
    {
        std::cout << " Destroying resource" << std::endl;
    }

    void do_something() {
        std::cout << "  Doing something" << std::endl;
    }
};
