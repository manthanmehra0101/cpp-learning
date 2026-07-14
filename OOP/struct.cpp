#include <iostream>
//struct is public by default.
struct player{
    int x,y;
    int health;
    int speed;

    void move(int newX, int newY){
        x += newX*speed;
        y += newY*speed;
    }
};
int main(){
    player p1;
    p1.x = 10;//no error: 'int player::x' is public within this context
    p1.y = 20;
    p1.health = 100;
    p1.speed = 2;
    p1.move(5, 5);
    std::cout<<"Health: "<<p1.health<<std::endl;
    std::cout<<"Position: ("<<p1.x<<", "<<p1.y<<")"<<std::endl;
    std::cout<<"Speed: "<<p1.speed<<std::endl;
    std::cout<<"Player moved to new position successfully." <<std::endl; 
    return 0;
}