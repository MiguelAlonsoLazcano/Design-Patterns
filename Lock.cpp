/*
 * Implementing RAII - Resource Acquisition Is Initialization
 * 	    class Foo {
 *		    Foo() { // do something }
 *   		~Foo() { // undo something }
 * 	    };
 *
 * */
#include <iostream>
#include <mutex>
#include <exception>

class Lock {
public:
    Lock(std::mutex& m) : mtx(m) {
        std::cout << "  Locking" << std::endl;
        mtx.lock();
    }
    ~Lock(){
        std::cout << "  Unlocking" << std::endl;
        mtx.unlock();
    }
private:
    std::mutex& mtx;
};
