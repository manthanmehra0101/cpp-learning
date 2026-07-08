#include <iostream>
//#include <GLFW/glfw3.h>
extern "C" int glfwInit();
int main(){
    int a = glfwInit();
    std::cout << a << "\n";
    std::cin.get();
    return 0;
}