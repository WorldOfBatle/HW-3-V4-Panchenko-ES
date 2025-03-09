#include <iostream>
#include <cmath>

void task1()
{
    const double R1 = 3.0;    // Внутренний «радиус» границы
    const double R2 = 8.0;    // Внешний «радиус» границы
    const double Y_BOUND = 3.0; // Граница по оси Y (|y|)
    
    std::cout << "Введите координаты точки (x и y): ";
    double x = 0.0;
    double y = 0.0;
    std::cin >> x >> y;

    double radius = std::sqrt(x * x + y * y);
    double absY = std::fabs(y);

    // Проверка на границу
    bool isOnBoundary =
        ((radius == R1 || radius == R2) && (absY >= Y_BOUND)) ||
        ((absY == Y_BOUND) && (radius >= R1 && radius <= R2));

    // Проверка на «внутри»
    bool isInside = (radius > R1 && radius < R2) && (absY > Y_BOUND);

    // Выводим результаты
    if (isOnBoundary)
    {
        std::cout << "На границе\n";
    }
    else if (isInside)
    {
        std::cout << "Внутри\n"; // точка внутри
    }
    else
    {
        std::cout << "Снаружи\n"; // точка вне
    }
}

// Заготовка для задачи №2
void task2()
{
    std::cout << "Введите номер карты (от 6 до 14): ";
    int k = 0;
    std::cin >> k;

    // Выведем то, что считали
    std::cout << "Вы ввели k = " << k << std::endl;
}

int main()
{
    task1();
    task2();
    return 0;
}
