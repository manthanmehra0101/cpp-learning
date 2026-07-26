/* Demonstrates std::optional for safe return values.
   Demonstrates:
    - std::optional<T>
    - std::ifstream
    - Reading an entire file using std::istreambuf_iterator
    - Checking whether a value exists before accessing it

    Notes:
    - std::optional represents a value that may or may not exist.
    - std::istreambuf_iterator reads the entire file directlyinto a std::string.
    - Access the stored value using *optional or optional.value().
*/
#include <iostream>
#include <fstream>
#include <optional>

std::optional<std::string> readFile(const std::string& path){
    std::ifstream stream(path);
    if (stream)
    {
        std::string result((std::istreambuf_iterator<char>(stream)),std::istreambuf_iterator<char>());
        return result;
    }
    return {};
}

int main(){
    std::optional<std::string> data = readFile("optional_data.txt");
    if (data)
    {   
        std::cout << "Reads file successfully!\n";
        std::cout << *data << "\n"; // or data.value()
    }
    else
    {
        std::cout << "Failed to read file!\n";
    }
}