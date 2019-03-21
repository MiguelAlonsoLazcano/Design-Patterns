#include <iostream>
#include <mutex>
#include "Lock.cpp"

int main() {
    std::mutex mt;

    std::cout << "Starting" << std::endl;
    try {
        Lock l(mt);
        std::cout << "Doing stuff" << std::endl;
        throw std::exception();
    } catch (...){
        std::cout << "Exception caught" << std::endl;
    }

    return 0;

}