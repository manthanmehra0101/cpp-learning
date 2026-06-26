#include <iostream>
#include <string>
using string = std::string;

class supercore_mac{
    string os;
    int* buffer = new int[12]{0,0,0,0,0,0,0,0,0,0,0,0};
    int core_thread;
    int core_count;
    public:
        supercore_mac(const string& name) : os(name), core_count(16), core_thread(24) {}
        supercore_mac(const int& thread) : os("pop_os!"), core_count(4)
        , core_thread(thread) {}
        //if we use explicit keyword then compiler doesn't implicitly convert anymore
        explicit supercore_mac() : os("win_10"), core_count(4), core_thread(8) {}
        const string OS_ver() const {
            return os;
        }
         const string pipeline() const {
            return std::to_string(core_thread) + "," + std::to_string(*buffer) + "," 
            + std::to_string(core_count);
        }
        ~supercore_mac(){ delete[] buffer; }
};

int main(){
    //implicit conversion but here we had to use ""s because compiler was showing error as
    //compiler couldn't convert implicitly into 2 steps 
    using namespace std::string_literals;
    supercore_mac s = "Win_11_WSL"s;
    //for single step implicit conversion compiler do so automatically without errors
    supercore_mac s1 = 8;
    //explicit one can't be like above. But can be like s1(8). 
    supercore_mac s2;
    std::cout << s.OS_ver() << std::endl;
    std::cout << s.pipeline() << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << s1.OS_ver() << std::endl;
    std::cout << s1.pipeline() << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << s2.OS_ver() << std::endl;
    std::cout << s2.pipeline() << std::endl;
    return 0;
}