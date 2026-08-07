#include <iostream>
#include <vector>
#include <thread>
#include <future>
std::vector<int> fibonacci(int n){
    std::vector<int> series;
    int a = 0;
    int b = 1;
    for (int i = 0; i <= n; i++){
        series.push_back(a);
        int next = a + b;
        a = b;
        b = next;
    }
    return series;
}
int main(){
    std::packaged_task<std::vector<int>(int)> task(fibonacci);
    auto outcome = task.get_future();
    std::thread t(std::move(task),8);
    std::cout << "Result with packaged_task :\t";
    auto s = outcome.get();
    for (auto i : s)
        std::cout << i << ' ';
    std::cout << '\n';
    t.join();
}