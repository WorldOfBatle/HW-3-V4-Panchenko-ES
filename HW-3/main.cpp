#include <iostream>
#include <cmath> // для sqrt, fabs

void task1()
{
    std::cout << "Введите координаты точки (x и y): ";
    double x = 0.0;
    double y = 0.0;
    std::cin >> x >> y;

    // Вычисляем радиус (расстояние до (0,0))
    double radius = std::sqrt(x * x + y * y);

    // Модуль y
    double absY = std::fabs(y);

    std::cout << "Вы ввели: (" << x << ", " << y << ")\n";
    std::cout << "radius = " << radius << ", |y| = " << absY << std::endl;
}

int main()
{
    task1();
    return 0;
}
