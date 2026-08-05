/*
Topics includes concept of -

        std::future
        std::async
        std::launch::async

        Asynchronous execution
        Lambda capture by reference
        future.get()
        RAII
        Dynamic memory allocation

*/
#include <iostream>
#include <future>
class allocate{
    public:
        int i;
        int* x;
        allocate() : i(25){
           x = new int[i]{};
           std::cout << "Constuctor Called!\n";
        }
        
        ~allocate(){
            delete[] x;
            std::cout << "Destructor Called!\n";
        }
};
int main(){
    {
        allocate a;
        auto value = [&a]{
            for(int j = 0; j < a.i; j++){
                a.x[j] += 2; 
            }
            std::cout << "Value of array :\t";
            for (int j = 0; j < a.i; j++){
                std::cout << a.x[j] << " ";
            }
            std::cout << "\n";
        };
        std::future<void> result = std::async(std::launch::async, value);
        result.get();// not std::cout as future is void
    }
}