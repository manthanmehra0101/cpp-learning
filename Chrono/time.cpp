#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
struct Time{
   std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
   std::chrono::duration<float> duration;
   Time(){
    start = std::chrono::high_resolution_clock::now();
   }
   ~Time(){
    stop = std::chrono::high_resolution_clock::now();
    duration = stop-start;
    float t_taken = duration.count();
    std::cout << "Execution time : " << t_taken << "s\n";
   }
};
void p(const std::vector<int>& n){
    Time t;
    int i = 0;
    if (n.empty()) return;
    do{
        std::cout << n[i] << "\n";
        i++;
    }while(i < n.size());
}
int main (){
    std::vector<int> _count;
    for (int v = 0; v <= 100; v++){
        _count.push_back(v);
    }
    p(_count);
    std::cin.get();
    return 0;
}