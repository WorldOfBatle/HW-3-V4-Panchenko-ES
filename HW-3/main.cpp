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

void task2()
{
    std::cout << "Введите номер карты (от 6 до 14): ";
    int k = 0;
    std::cin >> k;

    switch (k)
    {
    case 14:
        std::cout << "туз\n";
        break;
    case 13:
        std::cout << "король\n";
        break;
    case 12:
        std::cout << "дама\n";
        break;
    case 11:
        std::cout << "валет\n";
        break;
    case 10:
        std::cout << "десятка\n";
        break;
    case 9:
        std::cout << "девятка\n";
        break;
    case 8:
        std::cout << "восьмерка\n";
        break;
    case 7:
        std::cout << "семерка\n";
        break;
    case 6:
        std::cout << "шестерка\n";
        break;
    default:
        // Если вдруг ввели число вне диапазона
        std::cout << "Некорректный номер карты!\n";
        break;
    }
}

// Заготовка для задачи №3
void task3()
{
    // 1) Вывод через for
    std::cout << "--- Вывод через for ---\n";
    for (int i = 25; i <= 35; i++)
    {
        std::cout << i << " "
            << (i + 0.5) << " "
            << (i - 0.2) << std::endl;
    }

    // 2) Вывод через while
    std::cout << "\n--- Вывод через while ---\n";
    int j = 25;
    while (j <= 35)
    {
        std::cout << j << " "
            << (j + 0.5) << " "
            << (j - 0.2) << std::endl;
        j++;
    }

    // 3) Вывод через do while
    std::cout << "\n--- Вывод через do while ---\n";
    int k = 25;
    do
    {
        std::cout << k << " "
            << (k + 0.5) << " "
            << (k - 0.2) << std::endl;
        k++;
    } while (k <= 35);
}

int main()
{
    task1();
    task2();
    task3();
    return 0;
}
