#include <iostream>
#include <string>
class ant{
    public:
        void p(const std::string& x) const {
            std::cout << x << std::endl;
        }
};
class scp_ptr{
    ant* awm;
    public:
        scp_ptr(ant* xy) : awm(xy) {}
        ~scp_ptr(){ delete awm; }
        //operator overloading of arrow operator
        ant* operator->(){ return awm; }

};
int main(){
    ant e;
    e.p("Hello Console!");
    e.p("===========================");
    ant* a = &e;
    a->p("Hello Console Again!");
    (*a).p("Hi! The one typing.");
    // cannot a.p()
    scp_ptr s = new ant();
    s->p("hello");
    std::cin.get();
    return 0;
}