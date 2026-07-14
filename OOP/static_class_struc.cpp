#include <iostream>
//static in struct means that the variable is shared among all instances of the struct. It is not tied to any specific instance, and it can be accessed using the struct name or through any instance of the struct. In this example, x and y are static members of mystruct, and they are shared between s1 and s2. When we change the value of x and y using s1, it affects the values seen by s2 as well.
//and satic members of a struct can be accessed using the struct name, like mystruct::x and mystruct::y, without needing to create an instance of the struct. This is useful for variables that should have a single shared value across all instances of the struct.
//In this code, we have a struct called mystruct with two static integer members, x and y. We create two instances of mystruct, s1 and s2. When we set the values of x and y using s1, it changes the values for both s1 and s2 because x and y are static members shared by all instances of mystruct. When we call the display function for both s1 and s2, they will show the same values for x and y, which are 30 and 40 respectively.
//and same goes for the display function, it is not static, so it can be called using an instance of the struct, like s1.display() or s2.display(). However, since x and y are static members, they will show the same values regardless of which instance calls the display function.
//static method cannot be used to access non-static members of the struct, because static methods do not have access to the instance-specific data. In this example, if we were to make the display function static, it would not be able to access x and y directly, since they are static members. We would need to use the struct name to access them, like mystruct::x and mystruct::y, within the static display function.
//same goes for class.
struct mystruct
{
    static int x, y;
    void display()
    {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
};
int mystruct::x;
int mystruct::y;
int main()
{
    mystruct s1;
    s1.x = 10;
    s1.y = 20;
    mystruct s2;
    s2.x = 30;
    s2.y = 40;
    s1.display();
    s2.display();
    return 0;
}
