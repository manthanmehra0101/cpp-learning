#include <iostream>
#include <mutex>
#include <thread>
std::mutex m;
int counter = 0;
void worker(){
    std::unique_lock<std::mutex> lock(m, std::defer_lock);
    while(counter <= 5){
        counter++;
    }
    lock.lock();
    for (int i = 0; i <= 10; i++){
         std::cout << i << " Working...///....\n";
    }
    lock.unlock();
}

int main(){
    std::thread t1(worker);
    t1.join();
    std::cout << "======================\n";
    std::thread t2(worker);
    t2.join();
}