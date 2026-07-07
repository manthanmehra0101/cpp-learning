#include <iostream>
#include <string>
int count=10; // Declaration of the external variable 'count' in stat.cpp
// if we declare count as static in stat.cpp, it will not be accessible in other files, and we will get a linker error when trying to use it in Base_class.cpp. To fix
// this, we should remove the static keyword from the declaration of count in stat.cpp and declare it as an external variable in Base_class.cpp using the extern keyword. This way, both files can access the same variable without any linker errors.
void displayCount() {
    std::cout << "Count: " << count << std::endl;
}   
class sun{
    public:
        static sun& get(){
            static sun i;// if we don't make this static , i will get deleted after return
            return i;//of here.
        }
        void hi() {
            std::cout << "Hello!\n";
        }
};
int main() {
    sun::get().hi();
    displayCount(); // Call the function to display the value of 'count'
    return 0;
}