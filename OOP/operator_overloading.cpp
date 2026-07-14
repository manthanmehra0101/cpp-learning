#include <iostream>
struct vec1{
    float x,y;
    vec1(float a, float b) : x(a), y(b) {} 
    vec1 operator+(const vec1& m) const {
        return vec1(x+ m.x, y+m.y);
    }
    vec1 operator*(const vec1& c) const {
        return vec1(x*c.x, y*c.y);
    }
};
//without this we get error by compiler for printing.
std::ostream& operator<<(std::ostream& stream, const vec1& value){
    stream << value.x << ", " << value.y;
    return stream;
}
int main (){
    vec1 origin(0.0,0.0);
    vec1 coordinate(4.6,5.5);
    vec1 speed(3,3.5);
    vec1 res = origin + coordinate * speed;
    std::cout << res << std::endl;
    return 0;
}