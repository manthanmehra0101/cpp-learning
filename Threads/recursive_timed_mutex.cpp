#include <iostream>
#include <thread>
#include <mutex>
std::recursive_timed_mutex m;

void recursive(int n){
    using namespace std::literals::chrono_literals;
    if (m.try_lock_for(2s)){
        std::cout << std::this_thread::get_id() << "\n";
        std::cout << "Locked: " << n << '\n';
        std::this_thread::sleep_for(1s);
        if (n > 1)
            recursive(n - 1);
        m.unlock();
    }
    else{
        std::cout << "Timeout\n";
    }

}
int main(){
    std::thread t(recursive, 3);
    std::thread t1(recursive,3);
    t.join();
    t1.join();
}