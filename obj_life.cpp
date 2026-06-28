#include <iostream>
class wx{
    public:
        wx(){
            std::cout << "constructor" << std::endl;
        }
        ~wx(){
            std::cout << "destructor" << std::endl;
        }
};
int* fillData(){
    int array1[48];
    //int* array = new int[48];// heap allocation 
    return array1;
}
class scope_ptr{
    // scope pointer is the pointer that deletes itself when out of scope
    wx* xptr;
    public:
        scope_ptr(wx* pt) : xptr(pt) {}
        ~scope_ptr(){ delete xptr; }
};
int main(){
    scope_ptr s = new wx();
    fillData();//nothing as its stack allocated so doesn't gonna work , will show local var error
    wx w;// stack allocated , gets deallocated after scope
    wx* w1 = new wx;// heap allocated , only deallocated after deleting
    delete w1;
    std::cin.get();
    return 0;
}