#include <iostream>
#include <mutex>
#include "CRTP.h"
#include "DCLSingleton.h"
#include "Lock.h"
#include "Membership.h"
#include "MeyersSingleton.h"
#include "NaiveSingleton.h"
#include "PIMPL.h"
#include "Resource.h"
#include "Smart.h"


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

void test_smart_ptr_design_pattern()
{
    std::cout << "Starting SMART PTR" << std::endl;

    Ptr<Resource> pr(new Resource());
    pr->do_something();

}

void test_polymorphism_typically_implementation(){
    Base* base = new Derived();
    std::cout << "Polymorphism: " << base->return_data() << std::endl;
}

void test_crtp_implementation(){
    BaseCRTP<DerivedCRTP> base;
    std::cout << "Static Polymorphism: " << base.return_data() << std::endl;
}
void test_dcl_singleton_implementation(){
    std::cout << "DCL Implementation " << std::endl;
    DCLSingleton *inst = DCLSingleton::instance();
    inst->do_it();
}

void test_meyer_singleton_implementation(){
    std::cout << "Meyer Singleton " << std::endl;
    MeyersSingleton& inst = MeyersSingleton::instance();
    inst.do_it();
}

int main() {
    int op;
    std::cout << "Design Pattern" << std::endl;
    std::cout << "  1) RAII " << std::endl;
    std::cout << "  2) State" << std::endl;
    std::cout << "  3) PIMPL" << std::endl;
    std::cout << "  4) SMART PTR" << std::endl;
    std::cout << "  5) Polymorphism" << std::endl;
    std::cout << "  6) CRTP Static Polymorphism" << std::endl;
    std::cout << "  7) DCL Singleton" << std::endl;
    std::cout << "  8) Meyer Singleton" << std::endl;
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
        case 4:
            test_smart_ptr_design_pattern();
            break;
        case 5:
            test_polymorphism_typically_implementation();
            break;
        case 6:
            test_crtp_implementation();
            break;
        case 7:
            test_dcl_singleton_implementation();
            break;
        case 8:
            test_meyer_singleton_implementation();
            break;
        default:
            std::cout << "not valid option - break!" << std::endl;
            break;

    }
    return 0;
}
