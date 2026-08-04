/*
Topics includes concept of-

        std::shared_mutex
        std::shared_lock
        std::unique_lock

        Multiple readers
        Single writer

        Reader-writer synchronization
        Shared ownership
        Exclusive ownership
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
using namespace std::literals::chrono_literals;
std::shared_mutex m;
void reader(int r_id){
    std::shared_lock<std::shared_mutex> lock(m);
    std::cout << "Reader " << r_id << " : Reading...\n";
    std::this_thread::sleep_for(5s);
    std::cout << "Reader " << r_id << " : Read\n";
}
void writer(){
    std::unique_lock<std::shared_mutex> lock(m);
    std::cout << "Writing...\n";
    std::this_thread::sleep_for(2s);
    std::cout << "Written\n";
}
int main(){
    std::thread t0(reader,1);
    std::thread t1(reader,2);
    std::thread t2(reader,3);
    std::this_thread::sleep_for(100ms);
    std::thread t3(writer);
    t0.join();
    t1.join();
    t2.join();
    t3.join();
}