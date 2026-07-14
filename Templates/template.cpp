#include <iostream>
#include <string>
/* Template gets created only when we call function specified otherwise not, here in case
of void p if we wrote 'std::cout << date << "\n"' insted of data then there would be no 
error if we hadn't called function p(). But this also depends on compilers also. */
template<typename m>
void p(m data){
    std::cout << data << "\n";
}
template<int e, typename d>
class value{
    d array[e];/* if we did array[e] without template then we would get an error
    as template are determined at compiled time */
    public:
        int getSize() const { return e; }
};
int main(){
    p(55);// or like p<int>(56)
    p("Manthan");// can be done same
    p(10.8f);// same alternate method
    value<10, std::string> a;

    std::cout << a.getSize() << "\n";
    std::cin.get();
    return 0;
}