// string literals are always stored in read only memory or .rodata
#include <iostream>
#include <string>
#include <cstring>
int main(){
    const char name[8] = "Manthan";
    std::cout << strlen(name) << std::endl;
    //char* name2 = "Ram"; needs const as cpp forbids
    // name2[1] = 'm'; won't work as it is undefined as char* name2 is read only data
    char name3[] = "Ram";//created on stack memory as local mutable string array
    std::cout << name3 << std::endl;
    name3[1]='m';
    std::cout << name3 << std::endl;
    //some other char types
    const char* n = "ajsjd";// can be written as const char* n = u8"ajsjd"; char is 1 byte
    // i.e. 8 bit
    std::cout << n << std::endl;
    const wchar_t* u = L"klfvh";// wchar_t is 2 bytes i.e. 16 bit
    std::wcout << u << std::endl;
    const char16_t* j = u"jkhkgjkl";// char16_t is also 2 bytes i.e. 16 bit
    std::cout << j << std::endl;
    const char32_t* h = U"dsjkfas";// char32_t is 4 bytes i.e. 32 bit
    std::cout << h << std::endl;
    // Important new 
    using namespace std::string_literals;
    std::string k = "lsls"s + "krkr";// same as std::string("lsls")+"krkr" since c++ 14
    std::cout << k << std::endl;
    std::wstring o = L"dkask"s + L"dkfa"; // same for char16_t as u16string and char32_t as 
    // u32string and replace L with u or U
    std::wcout << o << std::endl;//needs wcout as we are using wstring
    const char* na = R"(line1
    line2
    line3)";
    std::cout << na << std::endl;
    //or const char* na = "line1\n"
    //"line2\n"
    //"line3\n" means same but R helps when we want to print paragraph
    std::cin.get();
    return 0;
}