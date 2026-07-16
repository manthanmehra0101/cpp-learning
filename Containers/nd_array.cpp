#include <iostream>

int main(){
    //1 dimensional
    int* arr = new int[10];
    //2 dimensional, here int** is a pointer->int* and we allocate to these int* 10 places
    int** arr2 = new int*[10];
    for(int i = 0; i < 10; i++){
        arr2[i] = new int[10];
    }
    //here 1st [] is of pointer access and 2nd [] is of actual int values
    arr2[0][0] = 0;
    arr2[0][1] = 1;
    //2d array should be deleted like this , if we try delete[][] arr2 it will cause memory leaks
    for(int i = 0; i < 10; i++){
        delete[] arr2[i];
    }
    delete[] arr2;
    //3 dimensional
    int*** arr3 = new int**[10];
    for(int i = 0; i < 10; i++){
        arr3[i] = new int*[10];
        for(int j = 0; j < 10; j++){
            arr3[i][j] = new int[10];
        }
    }
    //here 1st and 2nd [] are of pointer and array of pointers and 3rd [] is of actual int values 
    arr3[0][0][0] = 0;
    //deletion for 3d array, almost same concept of cleaning deepest to upper paths 
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            delete[] arr3[i][j];
        }
        delete[] arr3[i];
    }
    delete[] arr3;
    std::cin.get();
    return 0;
}