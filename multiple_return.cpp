#include <iostream>
#include <string>
#include <tuple>
#include <utility>
struct player{
    std::string name;
    unsigned int age;
    unsigned int p_id;
    player(const std::string& x, unsigned int y, unsigned int z) : name(x), age(y), p_id(z) {}
    const std::tuple<std::string, unsigned int, unsigned int> getData() const{
        return {name, age, p_id};
    }
    const std::pair<std::string, unsigned int> getPair() const{
        
        return {name, age};
    }
}; 
int main(){
    player p{"Manthan", 20, 1001};
    auto data = p.getData();
    std::cout << std::get<0>(data) << "\n";
    std::cout << std::get<1>(data) << "\n";
    std::cout << std::get<2>(data) << "\n";
    std::cout << "===========================" << "\n";
    auto pair = p.getPair();
    std::cout << pair.first << "\n";
    std::cout << pair.second << "\n";
    p.getPair();
    std::cin.get();
    return 0;
}