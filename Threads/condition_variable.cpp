/*Topics includes concept of-
        std::condition_variable
        std::mutex
        std::unique_lock
        std::lock_guard
        wait()
        notify_one()
        Lambda predicate
        Producer-Consumer synchronization
        Thread synchronization
        Spurious wakeup prevention
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
std::mutex m;
std::condition_variable c;
bool wait = true;
void worker(){
    std::unique_lock<std::mutex> lock(m);
    std::cout << "Waiting...\n";
    c.wait(lock, []{ return !wait; });
    std::cout << "Working...\n";
}
void boss(){
    using namespace std::literals::chrono_literals;
    if(wait)
        std::this_thread::sleep_for(5s);  
    std::lock_guard<std::mutex> lock(m);
    wait = false;
    std::cout << "Prepare...\n";
    c.notify_one();
}
int main(){
    std::thread t(worker);
    std::thread t1(boss);
    t.join();
    t1.join();
}