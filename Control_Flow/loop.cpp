#include <iostream>
#include "Log.h"
int main(){
    for(int i = 0; i<5; i++)
    {
        L("Hello!");
    }
    L("=========================");
    int j = 0;
    bool condition = true;
    for(; condition; )
    {
        L("Hello again!");
        j++;
        if(j >= 5)
        {
            condition = false;
        }
    }
    L("=========================");
    //difference between while and do-while is that do-while will execute at least once even if the condition is false  
    int k = 0;
    while(k < 5)
    {
        L("Hello once more!");
        k++;
    }
    L("=========================");
    do{
        L("Hello for the last time!");
        
    }while (false);
    return 0;
}