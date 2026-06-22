#include <iostream>
#include <array>
int main(){
    //creating raw array like this initializes array in stack memory of ram , in which
    //array will be deleted automatically after return 0
    int example[8] = {0};
    for (int i = 0; i < 8; i++){
        example[i]+=2;
    }
    std::cout << "Array : " ;
    for (int i = 0; i < 8; i++){
        std::cout << example[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "===========================================" << std::endl;
    //creating raw array like this initializes array in heap memory of ram , in which
    //array will only be deleted after delete
    int* arr = new int[5];
    std::cout << "Second_Array : " ;
    for (int i = 0; i < 5; i++){
        arr[i] = 2;
        std::cout  <<arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
    std::cout << "===========================================" << std::endl;
    //method of standard array , and can now use size() to know number of elements in array
    //above two methods need something like 'int size = sizeof(arr)/sizeof(int)' to know number
    //of elements and can't use size()
    std::array<int,10> boring = {0};
    std::cout << "Third_Array : " ;
    for (int i = 0; i < boring.size(); i++){
        boring[i] = 8;
        std::cout  <<boring[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
