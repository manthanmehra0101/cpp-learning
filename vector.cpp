#include <iostream>
#include <vector>
class ver{
    public:
        float x,y,z;
};
std::ostream& operator<<(std::ostream& stream, ver& v){
    stream << v.x << " " << v.y << " " << v.z;
    return stream;
}
int main(){
    std::vector<ver> a;
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
    //a.clear();//for clearing values

    std::cin.get();
    return 0;
}