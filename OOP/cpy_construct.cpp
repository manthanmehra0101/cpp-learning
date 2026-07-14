#include <iostream>
#include <string>
#include <cstring>
class ten{
    char* name;
    unsigned int size;
    public:
        ten(const char* ss){
            size = strlen(ss);
            name = new char[size];
            memcpy(name, ss, size);
        }
        // copy construct for not getting double free error
        ten(const ten& o) : size(o.size) {
            std::cout << "Copy Constructor, finally!" << std::endl;
            name = new char[size];
            memcpy(name, o.name, size);
        }
        ~ten(){
            delete[] name;
        }
    char& operator[](unsigned int i){
        return name[i];
    }
   friend std::ostream& operator<<(std::ostream& stream, const ten& t);
};
std::ostream& operator<<(std::ostream& stream, const ten& t){
    stream << t.name;
    return stream;
}
void prt(const ten& ten){
    std::cout << ten << std::endl;
}
int main(){
    ten t{"Manthan"};
    ten s = t;
    s[1] = 'o';
    prt(t);
    prt(s);
    std::cin.get();
    return 0;
}