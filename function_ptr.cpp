#include <iostream>
#include <string>
#include <array>

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
    p(first_name);
    typedef void(*hii)();
    hii func = hi;
    // alternate method
    auto func_2 = hi;
    auto cs = console_status;
    func();
    cs(1);
    //func_2();
    auto func_3 = p<std::array<std::string, 5>>;
    /* Function template ,so we need to specify which type p() is that compiler is sure of which p() we are 
    talking about */
    func_3(first_name);
    std::cin.get();
    return 0;
}