Modern C++ Design Patterns
==========================
Design patterns, Idioms, Functional programming techniques & key features of C++ 11, C++14

Design Patter is a tested solution to a recurring problem in a particular context, 
patterns are design ideas, one implemented patterns encode best practices -  
helps programmers to produce good code.

##### Advantages:
* Shared language, build on experience 
* Avoid common pitfalls, avoid reinventing the wheel

Christopher Alexander - 23 basic patterns ( The gang of four ) 
Divided in three main groups: 
Creational -ways of creating objects-
Structural -how objects are build into lager structures-
Behavioral -relay on objects run time behavior-  

				Creational	 Structural	Behavioral
    Class Based
    
    Object Based
    

##### Patters
MVC - Model, View, Controller , basis of many UIs, decouple UI from logic

State - Represent changing object state, object states are classes, bank account 
		Context --> State
                     ^
			     ^        ^
			State A	   State B

Singleton - One instance of a type, depending on what does 'one' mean, lifetime issues, initialization, ( one instance per app ? ) 

Observer - notification of state changes, implemented in many frameworks 
		Observer -- register --> Object 
		Observer <-- notifies -- Object
		 
##### Idioms
Language or platform specific, idioms are code level, example: pointers and templates in c++, garbage collector in java 

###### C++ Idioms
RAII - Resource Acquisition Is Initialization

PIMPL - Pointer to implementation, decouple implementation from use, Improve compilation 

SMART Pointers - Provide a mechanism to manage resources, it overload ->, manage resources, provide proxies, Many uses in C++

CRTP - Curiously Recurring Template Pattern, static polymorphism, removes need for virtual func

##### Implementation
Implementing patterns and idioms  - how a patter is implemented 

RAII

	class Lock {
		Lock() { // do something }
		~Lock() { // undo something }
	};

STATE

	class Member {
	    // Interface used to represent a
	    // FreeTier, Basic, Premium Membership
		Membership* role;
	};

PIMPL

    class Container{
        Impl *_impl
        // ...
    };

    class Container::Impl {...};

SMART PTR

    class Ptr<T> {
        T* p;
    public:
        // ...
        T* operator->() const {
            return p;
        }
    };

CRTP

    class B<T> { };
    class D : public B<D> { };

Singletone

    class NaiveSingelton
    class DCLSingleton
    class MeyersSingleton

