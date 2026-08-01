#include <iostream>
#include <thread>
#include <mutex>
std::timed_mutex m;
void work(int t_id){
    using namespace std::literals::chrono_literals;
    if (m.try_lock_for(5s)){
        std::cout << "Thread " << t_id << " Thread aquired, working....\n";
        std::this_thread::sleep_for(10s);//waits for 5s but this thread aquires for 10s so other one will not aquire
        m.unlock(); 
    }
    else{
        std::cout << "Thread " << t_id << " Thread not aquired, after waiting for 5s....\n";
    }
}
void work_until(int t_id){
    using namespace std::literals::chrono_literals;
    if (m.try_lock_until(std::chrono::steady_clock::now()+std::chrono::seconds(4))){
        std::cout << "Thread " << t_id << " Thread aquired, working....\n";
        std::this_thread::sleep_for(5s);;//waits for 4s but this thread aquires for 5s so other one will not aquire
        m.unlock(); 
    }
    else{
        std::cout << "Thread " << t_id << " Thread not aquired, after waiting until 4s....\n";
    }
}
int main(){
    std::thread t1(work,1);
    std::thread t2(work,2);
    t1.join();
    t2.join();
    std::cout << "=============================================================\n";
    std::thread t3(work_until,1);
    std::thread t4(work_until,2);
    t3.join();
    t4.join();
}
