/*
 * DCL Singleton
 * DCL implementation for Singleton design patter
 * A class that contains a static pointer to a single instance
 * to get it with a static function that creates on first call,
 * it uses a private constructor to prevent create instances by
 * it self and disables copying, it uses a Mutex to check if
 * the instance is not been created.
 * */

#pragma once

#include <iostream>
#include <mutex>

class DCLSingleton {
    static DCLSingleton *_instance;

    // Private default constructor
    DCLSingleton() {};
    // Prevent copying
    DCLSingleton(const DCLSingleton&);
    DCLSingleton& operator=(const DCLSingleton&);
    static std::mutex mtx;

public:
    static  DCLSingleton* instance(){
        // first check
        if (!_instance)
        {
            // acquire lock
            mtx.lock();
            // second check
            if(!_instance)
            {
                _instance = new DCLSingleton();
            }
            mtx.unlock();
        }
        return _instance;
    }

    void do_it() const {
        std::cout << "Doing it " << std::endl;
    }
};

std::mutex DCLSingleton::mtx;
DCLSingleton *DCLSingleton::_instance = nullptr;