/*
 * Naive Singleton
 * Traditional implementation for Singleton design patter
 * A class that contains a static pointer to a single instance
 * to get it with a static function that creates on first call,
 * it uses a private constructor to prevent create instances by
 * it self and disables copying.
 * */

#pragma once

#include <iostream>

class NaiveSingleton {
    static NaiveSingleton *_instance;

    // Private default constructor
    NaiveSingleton() {};
    // Prevent copying
    NaiveSingleton(const NaiveSingleton&);
    NaiveSingleton& operator=(const NaiveSingleton&);

public:
    static  NaiveSingleton* instance(){
        if (!_instance)
        {
            _instance = new NaiveSingleton();
        }
        return _instance;
    }

    void do_it() const {
        std::cout << "Doing it " << std::endl;
    }
};

NaiveSingleton *NaiveSingleton::_instance = nullptr;
