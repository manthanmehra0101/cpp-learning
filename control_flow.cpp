#include <iostream>
#include "Log.h"
int main(){
    for(int i = 0; i<5; i++)
    {
        if(i%2 == 0)
        {
            continue; //skip the rest of the loop body and move to the next iteration
        }
        L("Hello!");
        std::cout<<"i: "<<i<<std::endl; 
    }
    L("=========================");
    for(int i = 0; i<5; i++)
    {
        if(i== 1)
        {
            break; //exit the loop immediately
        }
        L("Hello again!");
        std::cout<<"i: "<<i<<std::endl; 
    }
    L("=========================");
     for(int i = 0; i<5; i++)
    {
        if(i== 1)
        {
            return 0; //exit the program immediately
        }
        L("Hello once more!");
        std::cout<<"i: "<<i<<std::endl; 
    }
     return 0;
}