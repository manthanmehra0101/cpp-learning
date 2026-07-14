#include <iostream>
//class is private by default.
class player{
    int x,y;
    int health;
    public:
        void setHealth(int h){
            health = h;
        }
        int getHealth(){
            return health;
        }
        void attack(bool damage){
            if(damage == true){
                health -= 10;
            }
            else{
                setHealth(100);
                health-=5;
            }
        }
};
int main(){
    player p1;
   // p1.x = 10;//error: 'int player::x' is private within this context
    p1.setHealth(100);
    std::cout<<"Health: "<<p1.getHealth()<<std::endl;
    p1.attack(true);
    std::cout<<"Health after successful attack: "<<p1.getHealth()<<std::endl;
    p1.attack(false);
    std::cout<<"Health after unsuccessful attack: "<<p1.getHealth()<<std::endl;
    return 0;
}