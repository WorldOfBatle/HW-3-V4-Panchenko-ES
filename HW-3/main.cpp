#include <iostream>
#include <cmath>

void task1()
{
    std::cout << "Введите координаты точки (x и y): ";
    double x = 0.0;
    double y = 0.0;
    std::cin >> x >> y;

    double radius = std::sqrt(x * x + y * y);
    double absY = std::fabs(y);

    // Проверка на границу
    bool isOnBoundary =
        ((radius == 3.0 || radius == 8.0) && (absY >= 3.0)) ||
        ((absY == 3.0) && (radius >= 3.0 && radius <= 8.0));

    // Проверка на «внутри»
    bool isInside = (radius > 3.0 && radius < 8.0) && (absY > 3.0);

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

int main()
{
    task1();
    return 0;
}
