//after smart pointer , concept of manual new and delete should be seperated as per need.
#include <iostream>
#include <string>
#include <memory>
class Empower{
    public:
        Empower(){ 
            std::cout << "Constructor Created" << std::endl;
         }
        ~Empower(){
            std::cout << "Destructur Called, Memory Freed" << std::endl;
        }
};
int main(){
    {
        //new scope
        //cannot do like e = new Empower() , because its explicitly stated in unique_ptr
        //so it need to be stated as "std::unique_ptr<Empower> e(new Empower());"
        //preferred way , otherwise doing as above stated way will lead constructor 
        //created exceptions then this ptr will be dangling
        //and not reference and memory leaks
        //disadvantage of unique_ptr is that we can't copy , share
        std::unique_ptr<Empower> e = std::make_unique<Empower>();
        //std::unique_ptr<Empower> e2 = e; can't share
        std::shared_ptr<Empower> e3 = std::make_shared<Empower>();
        std::shared_ptr<Empower> e4 = e3;// can do so because shared_ptr allocates two 
        //different memory one for class and one for control block for reference count
        //shared_ptr to shared_ptr inrcreases reference count
        //but weak_ptr to shared_ptr doesn't , not taking ownership like shared_ptr
        //only reference 
        std::weak_ptr<Empower> w = e3;
    }
    std::cin.get();
    return 0;
}