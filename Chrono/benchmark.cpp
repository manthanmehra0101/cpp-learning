/*
    Learning Source : Cherno C++ series
    Demonstrates concept of benchmarking as well :
    Compares:
    - Stack allocation (local array)
    - Heap allocation (new/delete)

    Notes:
    - Stack allocation is very fast (pointer adjustment).
    - Heap allocation is slower due to allocator overhead.
    - This benchmark measures allocation/deallocation cost,
      not memory access speed.
*/
#include <iostream>
#include <string>
#include <chrono>
class time_benchmark{
    std::chrono::time_point<std::chrono::steady_clock>(start_point);
    public:
        time_benchmark(const std::string& n){
            start_point = std::chrono::steady_clock::now();
            std::cout << n;
        }
        ~time_benchmark(){
            benchmark();
        }
        void benchmark(){
            auto stop_point = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_point - start_point);
            std::cout << duration.count() << "ns\n";
        }
};
int main(){
    {
        time_benchmark time("Stack allocated array : ");
        // for not to cause time overhead in both cases.
        for(int i = 0; i < 1000000; i++){
        int arr[10000];
        arr[0] = i;
        }
    }
    std::cout << "\n";
    {
        time_benchmark time("Heap allocated array : ");
        for(int i = 0; i < 1000000; i++){
        int* arr2= new int[10000];
        arr2[0] = i;
        delete[] arr2;
        }
    }
}