#include <iostream>
class myclass{
    public:
    int x,y;
    myclass(){
        x=0;
        y=0;
        std::cout<<"Constructor called"<<std::endl;
    }
    ~myclass(){
        std::cout<<"Destructor called"<<std::endl;
    }
    void display(){
        std::cout<<"x: "<<x<<", y: "<<y<<std::endl;
    }
};
int main(){
    myclass c1;
    c1.display();
    return 0;
}