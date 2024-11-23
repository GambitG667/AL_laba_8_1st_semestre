#include <cstddef>
#include <iostream>
#include "header.hpp"


int main(){
    const char hello[6] = "hello";
    const char world[6] = "world";
    char* hello_2 = CopyString(hello);
    char* hello_world = ConcatinateStrings(hello, world);

    size_t len{};
    while(*(hello_2+len) != '\0'){
        std::cout << *(hello_2+len);
        ++len;
    }
    std::cout << std::endl;

    len = 0;
    while(*(hello_world+len) != '\0'){
        std::cout << *(hello_world+len);
        ++len;
    }
    std::cout << std::endl;

    std::cout << "------------" << std::endl;
    Matrix matrix1;
    Matrix matrix2;

    Construct(matrix1, 2,3);
    Construct(matrix2, 3, 2);

    int arr[3][2] = {{1,2}, {3, 4}, {5, 6}};
    int arr2[2][3] = {{1,2,3}, {4,5,6}};

    for(int i{}; i < 3; ++i){
        for(int j{}; j < 2; ++j){
            matrix1.data_[i][j] = arr[i][j];
        }
    }

    for(int i{}; i < 2; ++i){
        for(int j{}; j < 3; ++j){
            matrix2.data_[i][j] = arr2[i][j];
        }
    }

    PrintMatrix(matrix1);
    std::cout << "--------------\n";
    PrintMatrix(matrix2);
    std::cout << "--------------\n";

    Matrix res = Mult(matrix1, matrix2);
    PrintMatrix(res);
    std::cout << "--------------\n";

    Matrix A;
    Construct(A, 3, 3);
    Matrix B;
    Construct(B, 3, 3);

    int arr_A[3][3] = {{1,2,3},
                        {4,5,6},
                        {7, 8, 9}};
    
    int arr_B[3][3] = {{1,2,0},
                        {0,3,8},
                        {1,5,4}};
    
    for(int i{}; i < 3; ++i){
        for(int j{}; j<3; ++j){
            A.data_[i][j] = arr_A[i][j];
            B.data_[i][j] = arr_B[i][j];
        }
    }

    PrintMatrix(A);
    std::cout << "-----------------\n";
    PrintMatrix(B);
    std::cout << "-----------------\n";
    Matrix summ = Add(A, B);
    PrintMatrix(summ);
    std::cout << "-----------------\n";
    Transposition(summ);
    PrintMatrix(summ);
    std::cout << "-----------------\n";







    return 0;
}