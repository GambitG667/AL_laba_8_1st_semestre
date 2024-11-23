#include <cstddef>

char* CopyString(const char* str);

char* ConcatinateStrings(const char* a, const char* b);

struct Matrix {
  int** data_ = nullptr;
  size_t n_ = 0u; // количество столбцов
  size_t m_ = 0u; // количество строк
};

// Создает заполненную нулями матрицу n x m.
void Construct(Matrix& out, size_t n, size_t m);
// Освобождает выделенную память.
void Destruct(Matrix& in);

// Создает копию матрицы |matrix|.
Matrix Copy(const Matrix& matrix);
// Возвращает сумму двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Add(const Matrix& a, const Matrix& b);
// Возвращает разницу двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Sub(const Matrix& a, const Matrix& b);
// Возвращает произведение двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Mult(const Matrix& a, const Matrix& b);

// Транспонирование матрицы.
void Transposition(Matrix& matrix);

// Сравнение двух матриц.
bool operator==(const Matrix& a, const Matrix& b);

void PrintMatrix(Matrix& matrix);