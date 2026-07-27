/*
    Demonstrates std::any.

    Demonstrates:
    - std::any
    - std::any_cast
    - std::any::type
    - std::any::has_value
    - std::any::reset

    Notes:
    - std::any can store any copyable type.
    - The stored type is determined at runtime.
    - Retrieve the value using std::any_cast<T>().
    - Wrong casts throw std::bad_any_cast.
*/
#include <iostream>
#include <any>
#include <string>

int main(){
    std::any value;
    std::cout << "Size of std::any : " << sizeof(value) << "\n\n";
    value = 100;
    std::cout << "Has value : " << value.has_value() << "\n";
    std::cout << "Integer : " << std::any_cast<int>(value) << "\n\n";
    value = 3.14f;
    std::cout << "Float : " << std::any_cast<float>(value) << "\n\n";
    value = std::string("Hello, Console!");
    std::cout << "String : " << std::any_cast<std::string>(value) << "\n\n";
    //Will return some non readable as 'NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE' 
    //for current type which means std::string for this case.
    //For int is i , float is f , char is c , double is d
    std::cout << "Current type : " << value.type().name() << "\n\n";

    // Remove stored value
    value.reset();
    std::cout << "Has value after reset : " << value.has_value() << "\n";
    try{
        value = 100;
        std::cout << std::any_cast<float>(value);
    }
    catch (const std::bad_any_cast& e)
    {
        std::cout << e.what() << '\n';
    }
}