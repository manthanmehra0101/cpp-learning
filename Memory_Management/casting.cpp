/* Demonstrates the four C++ casts:
    - static_cast
    - const_cast
    - reinterpret_cast
    - dynamic_cast
   Also compares C-style casting with C++ casts. */
#include <iostream>
class A{
    public:
        A(){}
        virtual ~A(){}
};
class B : public A{
    public:
        int value = 100;
        B(){}
        ~B(){}
};
class C : public A{
    public:
        C(){}
        ~C(){}
};
std::ostream& operator<<(std::ostream& stream, const B& b){
    stream << b.value;
    return stream;
}
int main(){
    // C style casting
    int x = 10;
    float a = 3.33;
    bool b = true;
    int c = (int)(a+b);
    std::cout << c <<"\n";

    // C++ style casting
    // static_cast: compile time checked conversions
    c = static_cast<int>(b+10.1); 
    std::cout << c <<"\n";
    const int e = 10;
    // const_cast: add/remove const qulifier
    int* k = const_cast<int*>(&e);
    std::cout << *k <<"\n";
    // reinterpret_cast: reinterpret raw memory as another type (dangerous)
    int* p = &x;
    char* w = reinterpret_cast<char*>(p);
    std::cout << *p <<"\n";
    // << overloading here
    B obj;
    B* d = reinterpret_cast<B*>(&obj);
    std::cout << *d <<"\n";

    B* n = new B();
    A* m = n;
    B* i = static_cast<B*>(m);
    // dynamic_cast: safe runtime downcasting for polymorhic classes
    B* z = dynamic_cast<B*>(m);
    B* g = reinterpret_cast<B*>(m);
    return 0;
}