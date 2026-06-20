#include <iostream>
class printable{
    public: 
       virtual std::string GetClassName() = 0;
};
class entity : public printable{
    public:
       virtual std::string GetName(){ return "Entity"; }
       std::string GetClassName() override {return "Entity";}
};
class player : public entity{
std::string p_name;
public:
    player(const std::string& name)
        :p_name(name){}
    std::string  GetName() override {return p_name;}
    std::string GetClassName() override {return "Player";}
};
void pr(printable* obj){
    std::cout << obj->GetClassName() << std::endl;
}
void print(entity* entity){
    std::cout << entity->GetName() << std::endl;
}
int main(){
    entity* e = new entity();
    //print(e);
    pr(e);
    player* p = new player("Manthan");
    //print(p);
    pr(p);
    return 0;
}