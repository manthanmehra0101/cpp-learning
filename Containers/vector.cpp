#include <iostream>
#include <vector>
class ver{
    public:
        float x,y,z;
    ver(float w, float s, float d) : x(w), y(s), z(d) {}
    ver(const ver& q) : x(q.x), y(q.y), z(q.z) {
        std::cout << "copy copy!" << std::endl;
    }
};
std::ostream& operator<<(std::ostream& stream, const ver& v){
    stream << v.x << " " << v.y << " " << v.z;
    return stream;
}
int main(){
    /*std::vector<ver> a;
    a.push_back({1,3,5});
    a.push_back({2,4,6});
    for (int i = 0; i < a.size(); i++){
        std::cout << a[i] << std::endl;
    }
    std::cout << "=====" << std::endl;
    a.erase(a.begin());//for erasing from beginning
    for (ver& b : a){
        std::cout << b << std::endl;
    }
    //a.clear();//for clearing values*/
    //comment out above part if running below one or vice-versa
    std::vector<ver> c;
    c.reserve(3);
    c.emplace_back(1,2,3);//will create 6 copies, as compiler needs to place this values in
    c.emplace_back(4,5,6);//allocated vector, but its without reserve() and after using it 
    c.emplace_back(7,8,9);//will get 3 copies which is half, but if using emplace_back() 
    //instead of push_back() we can directly place value in vector allocated memory
    std::cin.get();
    return 0;
}