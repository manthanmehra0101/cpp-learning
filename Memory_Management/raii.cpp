#include <iostream>
class allocate{
    public:
        int i;
        int* x;
        allocate() : i(25){
           x = new int[i]{};
           std::cout << "Constuctor Called!\n";
        }
        
        ~allocate(){
            delete[] x;
            std::cout << "Destructor Called!\n";
        }
};
int main(){
    allocate a;
}