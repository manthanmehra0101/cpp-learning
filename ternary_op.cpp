#include <iostream>
#include <string>
class world_map{
    public:
        int x;
        int y;
        int speed;
        int pos_x, pos_y;
        int new_pos(){
            pos_x = x*speed;
            pos_y = y*speed;
            std::cout << "New position of X : " << pos_x << std::endl;
            std::cout << "New position of Y : " << pos_y << std::endl;
            return sizeof(char32_t);// casually , no meaning
        }
};
int main(){
    world_map m;
    m.x = 15;
    m.y = m.x > 5 ? 10 : 5;
    m.speed = m.x && m.y > 8 ? 2 : 4;
    std::cout << m.new_pos() << std::endl;
    return 0;
}