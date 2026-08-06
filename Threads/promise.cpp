#include <iostream>
#include <vector>
#include <future>
#include <thread>
class allocate{
    public:
        std::vector<int> x;
        allocate() : x(25,0){
           std::cout << "Constuctor Called!\n";
        }
        ~allocate(){
            std::cout << "Destructor Called!\n";
        }
};
int main()
{
    {
        allocate a;
        auto work = [&a](std::promise<std::vector<int>>& p){
            using namespace std::literals::chrono_literals;
            std::this_thread::sleep_for(5s);
            for(int j = 0; j < a.x.size(); j++){
              a.x[j] += 2;
            }
            
            p.set_value(a.x);
        };
        std::promise<std::vector<int>> p;
        std::future<std::vector<int>> f = p.get_future();
        std::thread t(work, std::ref(p));
        std::cout << "Waiting...\n";
        auto vec = f.get();
        std::cout << "Received in main:\n";
        for (int x : vec){
            std::cout << x << ' ';
        }
        std::cout << '\n';
        t.join();
    }
}