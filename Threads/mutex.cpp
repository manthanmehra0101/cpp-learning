#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int counter = 0;
void work(){
    for(int i = 0; i < 5; i++){
        std::lock_guard<std::mutex> lock(m);
        counter++;
        std::cout << "Thread " << std::this_thread::get_id() << " Counter : " << counter << "\n";
    }
}
int main(){
    std::thread t1(work);
    std::thread t2(work);
    t1.join();
    t2.join();
    std::cout << "Final Counter : " << counter;
    std::cin.get();
}