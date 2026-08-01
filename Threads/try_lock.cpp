#include <iostream>
#include <thread>
#include <mutex>
std::mutex m;
void work(int id){
    if (m.try_lock()){
        std::cout << "Thread " << id << " Thread aquired , working...\n";
        using namespace std::literals::chrono_literals;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        m.unlock();
    }
    else{
        std::cout << "Thread " << id << " Thread not aquired... waiting...\n";
    }
}
int main(){
    std::thread t1(work,1);
    std::thread t2(work,2);
    t1.join();
    t2.join();
}