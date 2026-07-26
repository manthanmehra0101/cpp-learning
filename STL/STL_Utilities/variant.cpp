/*
    Demonstrates std::variant.

    Demonstrates:
    - std::variant
    - std::holds_alternative<T>()
    - std::get<T>()
    - std::variant::index()

    Notes:
    - std::variant stores one value of several possible types.
    - Only one type is active at a time.
    - The size of std::variant is determined by its largest alternative.
    - Use std::holds_alternative<T>() before std::get<T>() to avoid std::bad_variant_access.
*/
#include <iostream>
#include <variant>
#include <string>
int main()
{
    std::variant<int, float, std::string> data;
    std::cout << "Size of data : " << sizeof(data) << "\n";
    data = 100;
    std::cout << sizeof(int) << "\n";
    std::cout << "Index : " <<  data.index() << "\n";
    if (std::holds_alternative<int>(data))
        std::cout << "Integer : " << std::get<int>(data) << "\n";

    data = 3.14f;
    std::cout << sizeof(float) << "\n";
    std::cout << "Index : " << data.index() << "\n";
    if (std::holds_alternative<float>(data))
        std::cout << "Float : " << std::get<float>(data) << "\n";

    data = "Hello, Console!";
    std::cout << sizeof(std::string) << "\n";
    std::cout << "Index : " <<  data.index() << "\n";
    if (std::holds_alternative<std::string>(data))
        std::cout << "String : " << std::get<std::string>(data) << "\n";
    try
    {
        std::cout << std::get<int>(data);
    }
    catch (const std::bad_variant_access& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cin.get();
    return 0;
}