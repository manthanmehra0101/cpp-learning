#include <iostream>
void increment(int* x){
    (*x)++;
}
void inc(int& x){
    x++;
}
int main(){
    int a = 5;
    int* b = &a;
    int& c = a;
    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"b: "<<*b<<std::endl;    
    std::cout<<"c: "<<c<<std::endl;
    c=10;
    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"b: "<<*b<<std::endl;
    std::cout<<"c: "<<c<<std::endl;
    increment(b);
    std::cout<<"a: "<<a<<std::endl;
    inc(c);
    std::cout<<"a: "<<a<<std::endl;
    return 0;
}