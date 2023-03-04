#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix {
    private:
        int rows; // количество строк
        int cols; // количество столбцов
        double **data; // двумерный массив для хранения данных матрицы

    public:
        // Конструктор по умолчанию
        Matrix();

        // Конструктор с параметрами
        Matrix(int r, int c);

        // Конструктор копирования
        Matrix(const Matrix &m);

        // Деструктор
        ~Matrix();

        // Оператор присваивания
        Matrix& operator=(const Matrix &m);

        // Оператор сложения
        Matrix operator+(const Matrix &m);

        // Оператор умножения на число
        Matrix operator*(double scalar) const;
       
        // Оператор умножения матриц
        Matrix operator*(const Matrix &m);

        // Оператор индексации
        double* operator[](int index);

        // Метод для получения количества строк
        int get_rows() const;

        // Метод для получения количества столбцов
        int get_cols() const;

        // Метод для вывода матрицы в консоль
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};

#endif
