#include <iostream>
enum color{
    red,
    green,
    blue
};
int main(){
    color c1=red;
    color c2=green;
    color c3=blue;
    if (c1==red){
        std::cout<<true<<std::endl;
    }
    return 0;
}