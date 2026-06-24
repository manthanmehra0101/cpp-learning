#include <iostream>
#include <string>
class player{
std::string p_name;
int p_score;
public:
    player()
        : p_name("Ram"), p_score(1234)//initializer list same like ordinary constructor
        //but before {} and after player() : 
    {
        //if we initialize specifically after initializer list like p_nmae = "Uma";
        //then we are creating second string with "Uma" as value and 1st string declared
        //one of them wasted.
    }
    player(const std::string name, int score){
        p_name = name;
        p_score = score;
    }
    std::string getData() const { return "Name : "+p_name +" , Score : "+ std::to_string(p_score) ;}
};
int main(){
    player p;
    std::cout << p.getData() << std::endl;
    player p1("Manthan", 100000);
    std::cout << p1.getData() << std::endl;
    return 0;
}
