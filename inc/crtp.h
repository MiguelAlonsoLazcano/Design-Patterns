/*
 * Implementing CRTP
 * Curiously Recurring Template Pattern
 * Provides a mechanism for static polymorphism, removes the need for
 * virtual functions by defining a template base class that uses a derived
 * class as its template parameter
 * */



/*
 * Polymorphism is typically implemented by using virtual functions, this is the normal way that
 * libraries are implemented but there is a run time cost in using virtual functions that may be
 * prohibited in low latency applications
 * */
class Base {
protected:
    virtual int get_value() const = 0;
public:
    virtual ~Base(){}
    int return_data() const { return this->get_value(); }
};

class Derived : public Base {
private:
    int get_value() const override {
        return 10;
    }
};

/*
 * Static Polymorphism is implemented using the CRTP design patterns
 * it uses a lot less overhead than using the traditional implementation
 * */
template <typename D>
class BaseCRTP {
public:
    /*
     * Helper function, returns a reference to the derived type
     * */
    D& derived() {
        return static_cast<D&>(*this);
    }

    /*
     * Call derived type function
     * */
    int return_data() { return derived().get_value(); }
};

class DerivedCRTP : public BaseCRTP<DerivedCRTP>{
public:
    int get_value()  const { return 100; }
};
