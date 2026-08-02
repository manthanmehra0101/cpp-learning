#include <iostream>
#include <thread>
#include <mutex>
std::recursive_mutex m;
void work(){
    m.lock();
    std::cout << "working\n";
    m.lock();
    std::cout << "working again\n";
    m.unlock();
    m.unlock(); 
}
void recursive(int count){
    m.lock();
    std::cout << "Count : " << count << "\n";
    if (count > 1)
        recursive(count-1);
    m.unlock();
}
int main(){
    std::thread t(work);
    t.join();
    std::cout << "================\n";
    std::thread t1(recursive,4);//if we had used std::mutex instead of std::recursive_mutex 
    //, we would be stuck on 4 as deadlock as its locked on 4 and never unlocked.
    t1.join();
}