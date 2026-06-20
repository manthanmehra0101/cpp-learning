#include <iostream>
#include "Log.h"
int main(){
    int a;
    std::cout<<"Enter a number: ";
    std::cin>>a;    
    bool ispositive = a >= 0;
    if(ispositive){
        L("a is positive");
    }
    else{
        L("a is not positive");
    }
    return 0;
}