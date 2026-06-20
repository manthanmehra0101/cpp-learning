#include <iostream>
#include "Log.h"
int main(){
    int a = 12,b = 5,c = 8;
    if(a>b && a>c){
        L("a is the largest");
    }
    else if(b>a && b>c){
        L("b is the largest");
    }
    else if(c>a && c>b){
        L("c is the largest");
    }
    else{
        L("There is a tie for the largest number");
    }
    return 0;
}