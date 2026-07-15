/* This file is not purely namespace it includes following concepts-
lambda
explicit type conversion
template
std::function
Generic function */
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

namespace data {
    template<typename q>
    void execute(q& vec, std::function<void(q&)>& f){
        f(vec);
    }
}
int main(){
    std::vector<int> a = {1,9,3,5,4,2,6,8,7};
    auto func = [&](std::vector<int>& x) mutable {
        std::sort(x.begin(), x.end());
        for (const auto& i : x){
            std::cout << i << " ";
        }
        std::cout << "\n";
    };
    std::function<void(std::vector<int>&)> func1 = func;
    data::execute(a, func1);

    std::cin.get();
    return 0;
}