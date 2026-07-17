/*
Topic      : Type Punning
Source     : Cherno C++ Series
Concepts   :
- Memory layout
- Pointer casting
- reinterpretation of memory
- char*
- int*
- Struct memory
Purpose    :
Understand how the same memory can be viewed as different types.
*/
#include <iostream>
struct point{
    int q, w;
};
int main(){
    int a = 10;
    double a1 = (double)a;// normal value , same via a1 = a;
    double b = *(double*)&a;// some different value
    std::cout << a1 << " , " << b << "\n";
    point t{10, 20};
    int* s = (int*)&t;// accessing struct as array
    std::cout << s[0] << " , " << s[1] << "\n";
    int x = *(int*)(char*)&t;// char* advances 1 byte at a time , allowing precise byte offset
    int y = *(int*)((char*)&t+4);// for value of t.w , +4 gonna access value as here is of int type which is of 4 bytes
    std::cout << x << " , " << y << "\n";
    std::cin.get();
    return 0;
}