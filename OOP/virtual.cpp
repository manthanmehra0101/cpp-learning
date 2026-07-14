#include <iostream>
class entity{
    public:
       virtual std::string GetName(){ return "Entity"; }
};
class player : public entity{
std::string p_name;
public:
    player(const std::string& name)
        :p_name(name){}
    std::string  GetName() override {return p_name;}
};
void print(entity* entity){
    std::cout << entity->GetName() << std::endl;
}
int main(){
    entity* e = new entity();
    print(e);
    player* p = new player("Manthan");
    print(p);
    return 0;
}