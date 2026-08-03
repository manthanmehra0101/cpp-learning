/*Topics includes concept of-
        std::condition_variable
        std::unique_lock
        std::lock_guard
        wait()
        notify_all()
        lambda predicate
        thread synchronization
        producer-consumer style signaling
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
std::mutex m;
std::condition_variable c;
bool ready = false;
void work(int w_id){
    std::unique_lock<std::mutex> lock(m);
    std::cout << "waiting..." << w_id << "\n";
    c.wait(lock, []{ return ready; });
    std::cout << "working..." << w_id << "\n";
}
int main(){
    using namespace std::literals::chrono_literals;
    std::thread t0(work,1);
    std::thread t1(work,2);
    std::thread t2(work,3);
    
    if (ready==0){
        std::this_thread::sleep_for(5s);
        {
            std::lock_guard<std::mutex> lock(m);
            ready = true;
        }
        std::cout << "Notify...\n";
        c.notify_all();
    }
    t0.join();
    t1.join();
    t2.join();
}