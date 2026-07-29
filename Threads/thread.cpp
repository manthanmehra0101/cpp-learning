/* Topics includes concept of-
std::thread
lambda
macros
chrono literals
std::atomic with store() and load()
*/
#include <iostream>
#include <string>
#include <thread>
#include <atomic>
#define PR_DEBUG 1
#if defined(PR_DEBUG)
#define print(a) std::cout << a << "\n"
#endif
int main(){
    std::atomic<bool> executed{false};
    std::string a = "Working";
    auto run = [&](){
        do{
            using namespace std::literals::chrono_literals;
            print(a);
            std::this_thread::sleep_for(1s);
        }while(!executed.load());
    };
    std::thread console_print(run);
    print(std::this_thread::get_id());
    std::cin.get();
    executed.store(true);
    console_print.join();
    print("Done!");
    return 0;
}