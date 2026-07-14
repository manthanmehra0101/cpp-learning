#include <iostream>
//#include <GLFW/glfw3.h>
/*
The compiler only needs the declaration.

The linker later finds the actual implementation
inside GLFW library.

Without the library we get linker errors.

Without the declaration we get compiler errors.
*/
extern "C" int glfwInit();
int main(){
    int a = glfwInit();
    std::cout << a << "\n";
    std::cin.get();
    return 0;
}