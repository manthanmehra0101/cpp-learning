#include <iostream>
class Engine{
    public:
        int x = 0,y = 1,z = 2;
        char* buffer;
        Engine(): buffer(new char[26]){
            std::cout << "Constructor Called\n";
        }
        ~Engine(){
            delete[] buffer;
            std::cout << "Destructor Called\n";
        }
        Engine(const Engine& other): x(other.x), y(other.y), z(other.z){
            buffer = new char[26];
            for(int i = 0; i < 26; i++){
                buffer[i] = other.buffer[i];
            }
            std::cout << "Copy Constructor\n";
        }
        Engine& operator=(const Engine& other){
            if(this == &other){
                return *this;
            }
            delete[] buffer;
            buffer = new char[26];
            for(int i = 0; i < 26; i++){
                buffer[i] = other.buffer[i];
            }
            std::cout << "Copy Assignment\n";
            return *this;
        }

};
int main(){
    Engine e;
    for(int i = 0; i < 26; i++){
        e.buffer[i] += 'a'+i;
    }
    std::cout << "Character array :\t";
    for(int i = 0; i < 26; i++){
        std::cout << e.buffer[i] << ' ';
    }
    std::cout << '\n';
    Engine s = e;
    for (int i = 0; i < 26; i++) {
        s.buffer[i] = 'A' + i;
    }
    std::cout << "Character array :\t";
    for(int i = 0; i < 26; i++){
        std::cout << s.buffer[i] << ' ';
    }
    std::cout << '\n';
    Engine v;
    v = e;

}