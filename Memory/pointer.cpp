#include <iostream>
#include <cstring>//for memset function
#define L(x) std::cout<<x<<std::endl;//because the header file log.h created is for char not of other data types.
int main(){
    int a = 10;
    void* p = &a; //pointer to an integer variable
    L("Value of a: "<<a);
    L("Address of a: "<<&a);
    L("Value of p: "<<p);
    L("Value pointed to by p: "<< *(int*)p); //dereferencing the pointer to get the value of a
    char* Buffer = new char[8]; //pointer to a character array
    memset(Buffer, 0, 8); //initialize the buffer with zeros
    delete[] Buffer; //free the allocated memory
    int* p2 = &a; //pointer to an integer variable
    *p2 = 20; //dereferencing the pointer to change the value of a
    L("Value of a after modification: "<<a); 
    return 0;
}