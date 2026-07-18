/*
Topic      : Virtual Destructor
Source     : Cherno C++ Series

Concepts
- Polymorphism
- Base class pointer
- Dynamic allocation (new/delete)
- Destructor chaining
- virtual keyword

Purpose
Ensure that deleting a derived object through a base-class pointer
calls both the derived and base destructors.

Rule
If a class is intended to be used polymorphically (has virtual functions
or will be deleted through a base pointer), its destructor should almost
always be virtual.
*/
#include <iostream>
#define print(x) std::cout << x << "\n"
class A{
    public:
        A(){ print("Constructor of A"); }
        virtual ~A(){ print("Destructor of A"); }
};
class B : public A{
    public:
        B(){ print("Constructor of B"); }
        ~B(){ print("Destructor of B"); }
};
int main(){
    A* a = new A();
    delete a;
    print("=========================");
    B* b = new B();
    delete b;
    print("=========================");
    A* p = new B();
    delete p;
    return 0;
}