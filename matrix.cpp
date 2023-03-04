#include "matrix.h"

// Конструктор по умолчанию
Matrix::Matrix() {
    rows = 0;
    cols = 0;
    data = nullptr;
}

// Конструктор с заданными размерами
Matrix::Matrix(int rows_, int cols_) {
    rows = rows_;
    cols = cols_;
    // Выделяем память для двумерного массива data
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        // Заполняем матрицу нулями
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0;
        }
    }
}

// Конструктор копирования
Matrix::Matrix(const Matrix &m) {
    rows = m.rows;
    cols = m.cols;
    // Выделяем память для двумерного массива data и копируем данные
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = m.data[i][j];
        }
    }
}

// Деструктор
Matrix::~Matrix() {
    // Освобождаем память выделенную для двумерного массива data
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

// Оператор присваивания
Matrix& Matrix::operator=(const Matrix &m) {
    if (this == &m) {
        return *this;
    }
    // Освобождаем старую память
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
    // Выделяем новую память и копируем данные
    rows = m.rows;
    cols = m.cols;
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = m.data[i][j];
        }
    }
    return *this;
}

// Оператор сложения матриц
Matrix Matrix::operator+(const Matrix &m) {
    // Проверяем, что размеры матриц совпадают
    if (rows != m.rows || cols != m.cols) {
        throw "Размеры матриц должны совпадать";
    }
    // Создаем новую матрицу и заполняем ее суммой матриц
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = data[i][j] + m.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &m) {
    // Проверяем, что умножение возможно
    if (cols != m.rows){
        throw "Умножение невозможно";
    }

    Matrix res(rows, m.cols);
    
    // Заполняем матрицу res элементами, вычисляемыми по формуле умножения матриц
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            double sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += data[i][k] * m.data[k][j];
            }
            res.data[i][j] = sum;
        }
    }

    return res;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            out << m.data[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

int Matrix::get_rows() const {
    return rows;
}

int Matrix::get_cols() const {
    return cols;
}

double* Matrix::operator[](int index) {
    return data[index];
}
