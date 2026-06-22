#include <iostream>
#include <string>// if we don't include this header file named "string" we can still use 
// std::string , but we can't print this anymore
int main(){
    const char* name = "Shyam";
    std::cout << name << std::endl;
    char name2[7] = {'M','a','n','t','h','a','n'};
    std::cout << name2 << std::endl;
    std::string name3 = "Ram";
    std::cout << name3 << std::endl;
    std::string Food = "Daal"; //+ "Rice" this way produces error
    // Other ways which doesn't produces an error
    // Method 1
    std::string food2 = "Dosa";
    food2 += " Sambar";
    std::cout << food2 << std::endl;
    // Method 2
    std::string food3 = std::string("Paratha") + " Achar";
    bool contain = food3.find("th") != std::string::npos;
    // this std::string::npos is for not found but we passed != ,so it returns true or 1
    std::cout << food3 << std::endl;
    std::cout << contain << std::endl;
    std::cin.get();
}