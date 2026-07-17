/*
Topic      : std::sort
Source     : Cherno C++ Series
Concepts   :
- std::sort
- Custom comparator
- Lambda expressions
- std::greater<>
- Function templates
Purpose    :
Demonstrates different ways to customize sorting.
*/
#include <iostream>
#include <algorithm>
#include <vector>
template<typename k>
void print(k& x){
    for (int val : x){
        std::cout << val << " ";
    }
}
int main(){
    std::vector<int> vec = {9,1,4,3,5,8,6,2,7};
    std::cout << "Sorting 1 :\n";
    std::sort(vec.begin(), vec.end());
    print(vec);
    std::cout << "\nSorting 2 :\n"; 
    std::sort(vec.begin(), vec.end(), [](int a, int b){
        return a>b;
    });
    print(vec);
    std::cout << "\nAlternative Sorting 2 :\n";
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    print(vec);
    std::cout << "\nSorting 3 :\n";
    std::sort(vec.begin(), vec.end(), [](int a, int b){
        if (a==5){ return false; }
        if (b==1){ return true; }
        return a<b;
    });
    print(vec);
    std::cin.get();
    return 0;
}