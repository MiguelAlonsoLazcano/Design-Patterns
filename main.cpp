#include <iostream>
#include <mutex>
#include "Lock.h"
#include "Membership.h"
#include "pimpl.h"


void test_rsc_adq_init_desin_pattern ()
{
    std::mutex mt;

    std::cout << "Starting RAII" << std::endl;
    try {
        Lock l(mt);
        std::cout << "Doing stuff" << std::endl;
        throw std::exception();
    } catch (...){
        std::cout << "Exception caught" << std::endl;
        std::cout << std::endl;
    }
}

void test_state_desigin_pattern()
{
    std::cout << "Starting STATE" << std::endl;
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
}

void test_pointer_impl_design_pattern()
{
    std::cout << "Starting PIMPL" << std::endl;
    Container c(10);
    c[3] = 37;
    std::cout << c[3] << std::endl;
}

int main() {
    int op;
    std::cout << "Design Pattern" << std::endl;
    std::cout << "  1) RAII " << std::endl;
    std::cout << "  2) State" << std::endl;
    std::cout << "  3) PIMPL" << std::endl;
    std::cout << "Test: ";
    std::cin >> op;
    switch (op){
        case 1:
            test_rsc_adq_init_desin_pattern();
            break;
        case 2:
            test_state_desigin_pattern();
            break;
        case 3:
            test_pointer_impl_design_pattern();
            break;
        default:
            std::cout << "not valid option - break!" << std::endl;
            break;

    }
    return 0;
}
