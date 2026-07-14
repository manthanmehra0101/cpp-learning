#include <iostream>
class entity{
    public:
    int x,y;
    entity(int a,int b){
        x=a;
        y=b;
    }
    void status(bool isActive){
        if(isActive){
            std::cout<<"Entity is active"<<std::endl;
        }
        else{
            std::cout<<"Entity is inactive"<<std::endl;
        }
    }
    void move(int dx,int dy){
        x+=dx;
        y+=dy;
    }
    virtual~entity(){
        std::cout<<"Entity destructor called"<<std::endl;
    }
};
class player : public entity{
    public:
    int health;
    void setHealth(int h){
        health=h;
    }
    void displayHealth(){
        std::cout<<"Health: "<<health<<std::endl;
    }
    void attack(){
        if (health>0){
            std::cout<<"Player is attacking"<<std::endl;
        }
        else{
            std::cout<<"Player is dead and cannot attack"<<std::endl;
        }
    }
    using entity::entity; // Inherit the constructor of the base class
    ~player() override{
        std::cout<<"Player destructor called"<<std::endl;
    }// Override the destructor of the base class
};

int main(){
    player p1(2,5); // Call the constructor of the base class
    p1.setHealth(100);
    p1.displayHealth();
    p1.attack();
    p1.move(10,20);
    std::cout<<"Player position: ("<<p1.x<<","<<p1.y<<")"<<std::endl;
    p1.status(true);
    return 0;
}