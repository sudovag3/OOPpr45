#ifndef POINT_H
#define POINT_H

class Point
{
    private:
        int x, y;
    public:
        // Конструктор по умолчанию
        Point();
        // Конструктор инициализации
        Point(int x_, int y_);
        // Функция для задания значений координат точки
        void set(int x_, int y_);
        // Функции для получения значений координат точки
        int getx();
        int gety();
        // Перегрузка оператора сложения для точек
        Point operator+(Point p);
        // Перегрузка оператора вычитания для точек
        Point operator-(Point p);
        // Перегрузка оператора умножения для точки на скаляр
        Point operator*(int c);
        // Функция для вычисления расстояния между двумя точками
        float distance(Point p);
};

#endif // POINT_H
