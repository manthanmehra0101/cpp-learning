#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::vector<int> vec = {9,1,4,3,5,8,6,2,7};
    std::cout << "Sorting 1 :\n";
    std::sort(vec.begin(), vec.end());
    for (int val : vec){
        std::cout << val << " ";
    }
    std::cout << "\nSorting 2 :\n"; 
    std::sort(vec.begin(), vec.end(), [](int a, int b){
        return a>b;
    });
    for (int val : vec){
        std::cout << val << " ";
    }
    std::cout << "\nAlternative Sorting 2 :\n";
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    for (int val : vec){
        std::cout << val << " ";
    }
    std::cout << "\nSorting 3 :\n";
    std::sort(vec.begin(), vec.end(), [](int a, int b){
        if (a==5){ return false; }
        if (b==1){ return true; }
        return a<b;
    });
    for (int val : vec){
        std::cout << val << " ";
    }
    std::cin.get();
    return 0;
}