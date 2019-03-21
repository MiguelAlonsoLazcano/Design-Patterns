#include <iostream>
#include <mutex>
#include "Lock.h"
#include "Membership.h"

int main() {
    std::mutex mt;

    std::cout << "Starting" << std::endl;
    try {
        Lock l(mt);
        std::cout << "Doing stuff" << std::endl;
        throw std::exception();
    } catch (...){
        std::cout << "Exception caught" << std::endl;
        std::cout << std::endl;
    }

    try {
        Member m("MyNewMember");
        std::cout << "Creating a new Member " << m.name() << std::endl;
        std::cout << "Number of current downloads " << m.download_per_day() << std::endl;
        m.upgrade();
        std::cout << "Upgraded, number of current downloads " << m.download_per_day() << std::endl;
        m.upgrade();
        std::cout << "Upgraded, number of current downloads " << m.download_per_day() << std::endl;
        m.upgrade();
        std::cout << "Upgraded, number of current downloads " << m.download_per_day() << std::endl;
        m.upgrade();
        std::cout << "Upgraded, number of current downloads " << m.download_per_day() << std::endl;

    } catch (...){
        std::cout << "Exception caught" << std::endl;
    }

    return 0;

}