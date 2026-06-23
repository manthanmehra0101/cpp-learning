#include <iostream>
#include <string>
class user_identity{
std::string user_name;
std::string user_email;
mutable int user_password;
public:
    std::string getCredentials() const {
        return "Name : "+ user_name + " , Email : "+ user_email;
        user_password = 123;// mutable can in constant
    }
    void setCredentials(std::string name,std::string email){
        user_name = name;
        user_email = email;
    }
};
int main(){
    const int max_marks = 100;
    int* a = new int;//1. if we type const before int* then it is not possible for *a = 2
    // or anything but a = &b can be done
    //2. if we type const after int* then it is not possible for a = &b but *a = 2 can be 
    // done 
    //3. if we add like both 'const int* const a = new int;' then there is nothin we can do
    int b=20;
    *a = 2;
    a = &b;
    user_identity u;
    u.setCredentials("Manthan","abc@gmail.com");
    std::cout << u.getCredentials() << std::endl;
    std::cin.get();
    return 0;
} 