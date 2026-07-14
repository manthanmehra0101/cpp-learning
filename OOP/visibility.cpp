#include <iostream>
class entity{
    protected:
    int x,y;
    public:
        entity(){
            x = 2;
        }
        virtual void l() const{
            std::cout << "X :" <<" " << x << std::endl;
        }
        ~entity(){};
    };
class player : public entity{
public:
    
    player(){
        y = 22;
    }
    void l() const override {
            std::cout << "Y :" <<" " << y << std::endl;
        }

    ~player(){};
};

int main(){
    entity e;
    e.l();
    player p;
    p.l();
    return 0;
}