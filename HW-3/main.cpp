#include <iostream>

void task1()
{
    std::cout << "Введите координаты точки (x и y): ";
    double x = 0.0;
    double y = 0.0;
    std::cin >> x >> y;

    // Пока просто проверим, что считали данные
    std::cout << "Вы ввели: (" << x << ", " << y << ")\n";
}

int main()
{
    task1();
    return 0;
}
