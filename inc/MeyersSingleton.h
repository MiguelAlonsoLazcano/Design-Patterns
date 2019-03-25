/*
 * Meyers Singleton
 * Meyers implementation for Singleton design patter
 * A class that contains a static instance inside of a
 * static function, the static instance is created on the
 * first run and it remains during the lifecycle of the
 * program. It returns a reference to the instance instead of
 * a pointer
 * */

#pragma once

#include <iostream>

class MeyersSingleton {
    // Prevent construction and copying
    MeyersSingleton() {};
    MeyersSingleton(const MeyersSingleton&);
    MeyersSingleton& operator=(const MeyersSingleton&);

public:
    static  MeyersSingleton& instance(){
        static MeyersSingleton _instance;
        return _instance;
    }

    void do_it() const {
        std::cout << "Doing it " << std::endl;
    }
};

