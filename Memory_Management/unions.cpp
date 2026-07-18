/*
Topic      : Unions
Source     : Cherno C++ Series
Concepts   :
- union
- Shared memory
- Memory overlap
- Type reinterpretation
- Anonymous union
- Anonymous struct
- Alternative views of the same data
- Struct + Union combination
- Vector component aliasing (x,y,w,z <-> q,r)

Purpose    :
Understand how multiple members can occupy the same memory location,
allowing different interpretations of identical bytes while saving memory.
*/
#include <iostream>
struct entity{
    float x, y;
};
struct entity_2{
    union{
        struct{
            float x, y, w, z;
        };
        struct{
            entity q, r;
        };
    };
};
int main(){
    union data {
        int a;
        float b;
    };
    data d;
    d.a = 10;
    std::cout << "d.a = " << d.a << "\n";
    std::cout << "d.b = " << d.b << "\n";//interpret same bits as float as unions 
    //share same memory to value of d.a
    std::cout << "memory address of d.a is " << &d.a << "\nmemory address of d.b is " << &d.b << "\n";
    d.b = 10.0f;
    std::cout << "d.a = " << d.a << "\n";
    std::cout << "d.b = " << d.b << "\n";
    std::cout << "memory address of d.a is " << &d.a << "\nmemory address of d.b is " << &d.b << "\n";
    std::cout << "============================================\n";
    entity_2 e;
    e.x = 1;
    e.y = 2;
    e.w = 3;
    e.z = 4;
    std::cout << "x, y, w, z = " << e.x << ", " << e.y << ", " << e.w << ", " << e.z << "\n";
    std::cout << "Viewing same memory as entity :\n";
    std::cout << "q = " << e.q.x << "," << e.q.y;
    std::cout << "\nr = " << e.r.x << "," << e.r.y;
    e.r.x = 900;
    std::cout << "\nw = " << e.w << "\n";
    std::cout << "r.x = " << e.r.x << "\n";// r.x = w, r.y = z, q.x = x, q.y = y
    std::cin.get();
    return 0;
}