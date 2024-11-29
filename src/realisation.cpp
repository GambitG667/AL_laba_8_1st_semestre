#include <algorithm>
#include <cstddef>
#include <iostream>
#include "header.hpp"


char* CopyString(const char* str){
    size_t len{};
    while(*(str+len) != '\0') ++len;

    char* new_str = new char[len+1];
    std::copy(str, str+len+1,new_str);
    return new_str;
}

char* ConcatinateStrings(const char* a, const char* b){
    size_t len_a{};
    size_t len_b{};

    while(*(a+len_a) != '\0') ++len_a;

    while(*(a+len_b) != '\0') ++len_b;

    char* new_str = new char[len_a+len_b+1];
    std::copy(a,a+len_a, new_str);
    std::copy(b, b+len_b, new_str+len_a);
    new_str[len_a+len_b]='\0';
    
    return new_str;
}

// Создает заполненную нулями матрицу n x m.
void Construct(Matrix& out, size_t n, size_t m){
    out.n_ = n;
    out.m_ = m;
    out.data_ = new int*[m];
    for(int i{}; i < m; ++i){
        out.data_[i] = new int[n];
        for(int j{}; j<n; ++j){
            out.data_[i][j] = 0;
        }
    }
}
// Освобождает выделенную память.
void Destruct(Matrix& in){
    for(int i{}; i < in.m_; ++i){
        delete[] in.data_[i];
    }
    delete[] in.data_;
}

// Создает копию матрицы |matrix|.
Matrix Copy(const Matrix& matrix){
    Matrix result;
    Construct(result, matrix.n_, matrix.m_);
    for(int i{}; i < matrix.m_; ++i){
        for(int j{}; j < matrix.n_; ++j){
            result.data_[i][j] = matrix.data_[i][j];
        }
    }
    return result;
}
// Возвращает сумму двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Add(const Matrix& a, const Matrix& b){
    Matrix result;
    if(a.m_ != b.n_) return result;
    if(a.n_ != b.n_) return result;

    Construct(result, a.n_, a.m_);

    for(int i{}; i<result.m_; ++i){
        for(int j{}; j<result.n_; ++j){
            result.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }
    return result;
}
// Возвращает разницу двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Sub(const Matrix& a, const Matrix& b){
    Matrix result;
    if(a.m_ != b.n_) return result;
    if(a.n_ != b.n_) return result;

    Construct(result, a.n_, a.m_);

    for(int i{}; i<result.m_; ++i){
        for(int j{}; j<result.n_; ++j){
            result.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }
    return result; 
}
// Возвращает произведение двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Mult(const Matrix& a, const Matrix& b){
    Matrix result;
    if(a.n_ != b.m_) return result;
    Construct(result, a.m_, b.n_);
    for(int i{}; i < result.m_; ++i){
        for(int j{}; j < result.n_; ++j){
            for(int k{}; k < a.n_; ++k){
                result.data_[i][j] += a.data_[i][k] * b.data_[k][j];
            }
        }
    }
    return result;
}

// Транспонирование матрицы.
void Transposition(Matrix& matrix){
    Matrix* bufer = new Matrix;
    Construct(*bufer, matrix.m_, matrix.n_);
    for(int i{}; i < bufer->m_; ++i){
        for(int j{}; j < bufer->n_; ++j){
            bufer->data_[i][j] = matrix.data_[j][i];
        }
    }

    for(int i{}; i < matrix.m_; ++i){
        delete[] matrix.data_[i];
    }
    delete[] matrix.data_;
    matrix.data_ = bufer->data_;
    int buf;
    buf = matrix.m_;
    matrix.m_ = matrix.n_;
    matrix.n_ = buf;
}

// Сравнение двух матриц.
bool operator==(const Matrix& a, const Matrix& b){
    if(a.m_ != b.m_) return false;
    if(a.n_ != b.n_) return false;

    for(int i{}; i < a.m_; ++i){
        for(int j{}; j < a.n_; ++j){
            if(a.data_[i][j] != b.data_[i][j]) return false;
        }
    }
    return true;
}

void PrintMatrix(Matrix& matrix){
    for(int i{}; i < matrix.m_; ++i){
        for(int j{}; j < matrix.n_; ++j){
            std::cout << matrix.data_[i][j]<< ' ';
        }
        std::cout << std::endl;
    }
}