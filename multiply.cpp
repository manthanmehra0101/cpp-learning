#include <iostream>
void L(const char* mess);
int mul(int a, int b){
    L("Multiply result:");
    return a*b;
}
int main(){
    std::cout<<mul(9, 11)<<std::endl;
    std::cin.get();
    return 0;
}