#include <iostream>
#include <string>
using string = std::string;

class player{
    string p_name;
    int p_age;
    int p_score;
    string rank;
    public:
        player() : p_name("unknown"), p_age(12), p_score(1){}
        //Default constructor for default info.
        player(const string name, const int age, const int score) : p_name(name), p_age(age), p_score(score){}
        //User input info , when player enter data to update by second constructor. 
        string getName() const { return p_name; }
        int getAge() const { return p_age; }

        void Rank(){
            if (p_score >= 1000) {
                rank = "DIAMOND";
            } else if (p_score >= 500) {
                rank = "PLATINUM";
            } else if (p_score >= 100) {
                rank = "GOLD";
            } else if (p_score >= 50) {
                rank = "SILVER";
            } else if (p_score >= 10) {
                rank = "BRONZE";
            } else {
                rank = "UNRANKED";
            }
            std::cout << rank << std::endl;
        }
};

int main(){
    //calling default constructor
    std::cout << "=================================================" << std::endl;
    player p;
    std::cout << p.getName() << std::endl;
    std::cout << p.getAge() << std::endl;
    p.Rank();
    std::cout << "=================================================" << std::endl;
    //calling constructor cause of user update
    player p1("MANTHAN", 20, 1200);
    std::cout << p1.getName() << std::endl;
    std::cout << p1.getAge() << std::endl;
    p1.Rank();
    std::cout << "=================================================" << std::endl;
    //checking how we instantiate an object
    player p3;
    {
        player* p2 = new player("Ram", 23, 200);//heap allocation
        p3 = *p2;
        std::cout << p3.getName() << std::endl;
        std::cout << p3.getAge() << std::endl;
        p3.Rank();
        delete p2;//whenever we use new we must use delete and if not then it will cause memory leaks
    }
    std::cout << "=================================================" << std::endl;
    return 0;
}