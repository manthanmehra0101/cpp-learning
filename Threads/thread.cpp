/* Topics includes concept of-
std::thread
lambda
macros
chrono literals
*/
#include <iostream>
#include <string>
#include <thread>
#define PR_DEBUG 1
#if defined(PR_DEBUG)
#define print(a) std::cout << a << "\n"
#endif
int main(){
    
    bool executed = false;
    std::string a = "Working";
    auto run = [&](){
        do{
            using namespace std::literals::chrono_literals;
            print(a);
            std::this_thread::sleep_for(1s);
        }while(!executed);
    };
    std::thread console_print(run);
    std::cin.get();
    executed = true;
    console_print.join();
    print("Done!");
    std::cin.get();
    return 0;
}