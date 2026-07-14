/* This code file is for function and function template pointer as well as lambda usage */
/* std::function used for storing anything callable */
#include <iostream>
#include <string>
#include <array>
#include <functional>
using a = std::array<std::string, 5>;// for function template pointer 'func_3' and void pr(......)
void pr(const a& names, const std::function<void(std::string)>& f){
    for (const auto& name : names ){
        f(name);
    }
}
template<typename s>
void p(const s& data){
    std::cout <<  "First Name list :-" << "\n";
    for(int i = 0; i < data.size(); i++){
        std::cout << data[i] << "\n";
    }
}
void hi(){
    std::cout << "Hello, Console!" << "\n";
}
void console_status(const bool& x){
    if (x==1){
        std::cout << "Console status : " << true << "\n";
        std::cout << "System check! Done" << "\n";
    }
    else if (x==0){
        std::cout << "Console status : " << false << "\n";
    }
}
int main(){
    std::array<std::string, 5> first_name = {"Manthan", "Ram", "Shyam", "Vijay", "Ajay"};
    //p(first_name);
    typedef void(*hii)();
    hii func = hi;
    // alternate method
    auto func_2 = hi;
    auto cs = console_status;
    func();
    cs(1);
    //func_2();
    /* Function template ,so we need to specify which type p() is that compiler is sure of which p() we are 
    talking about */
    auto func_3 = p<a>;
    func_3(first_name);
    std::cout << "=================================" << "\n";
    auto lambda = [](const std::string& s){ std::cout << "Name : " << s << "\n"; };
    pr(first_name, lambda);
    std::cin.get();
    return 0;
}