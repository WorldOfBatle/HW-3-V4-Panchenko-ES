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

void task4()
{
    // Выводим числа от 41 до 80
    // Каждый раз, когда текущее число % 10 == 0, делаем перевод строки
    for (int i = 41; i <= 80; i++)
    {
        std::cout << i << " ";

        // Если число заканчивается на 0 (50, 60, 70, 80) - перевод строки
        if (i % 10 == 0)
        {
            std::cout << std::endl;
        }
    }
}

// Вспомогательная функция для вычисления y = sqrt(5 - x^3), для задачи №5.
// Предполагается, что 5 - x^3 >= 0 (проверка вне функции).
double calculateFunction(double x)
{
    return std::sqrt(5.0 - x * x * x);
}

// Основная функция для задачи №5
void task5()
{
    // Считываем a, b, h
    std::cout << "Введите границы интервала [a, b] и шаг h: ";
    double a = 0.0;
    double b = 0.0;
    double h = 0.0;
    std::cin >> a >> b >> h;

    // Выводим шапку таблицы
    std::cout << "\nТаблица значений функции y = sqrt(5 - x^3)\n";
    std::cout << "   x            y\n";
    std::cout << "-----------------------\n";

    // Небольшой допуск, чтобы гарантировать прохождение до b
    const double EPS = 1e-9;

    // Цикл по x
    for (double x = a; x <= b + EPS; x += h)
    {
        // Сначала проверяем, не < 0 ли подкоренное выражение
        double expr = 5.0 - x * x * x;
        if (expr < 0.0)
        {
            // Функция не определена
            std::cout << x << "    Функция не определена\n";
        }
        else
        {
            // Вычисляем y через вспомогательную функцию
            double y = calculateFunction(x);
            std::cout << x << "    " << y << "\n";
        }
    }
}

// Вспомогательная функция для вычисления y по кусочно-заданной формуле, для задачи №6
double computePiecewiseValue(double x)
{
    double absX = std::fabs(x);
    if (absX <= 0.1)
    {
        // x^3 - 0.1
        return x * x * x - 0.1;
    }
    else if (absX <= 0.2)
    {
        // 0.2x - 0.1
        return 0.2 * x - 0.1;
    }
    else
    {
        // x^3 + 0.1
        return x * x * x + 0.1;
    }
}

// Основная функция для задачи №6
void task6()
{
    // Считываем a, b, h
    std::cout << "Введите границы интервала [a, b] и шаг h: ";
    double a = 0.0;
    double b = 0.0;
    double h = 0.0;
    std::cin >> a >> b >> h;

    // Шапка таблицы
    std::cout << "\nТаблица значений функции:\n";
    std::cout << "   x            y\n";
    std::cout << "-----------------------\n";

    // Небольшой допуск, чтобы учесть погрешности с плавающей точкой
    const double EPS = 1e-9;

    // Цикл
    for (double x = a; x <= b + EPS; x += h)
    {
        // Вычисляем y
        double y = computePiecewiseValue(x);

        // Выводим пару (x, y)
        std::cout << x << "    " << y << "\n";
    }
}

int main()
{
    task1();
    task2();
    task3();
    std::cout << "\n--- Переход к задаче 4 ---\n\n";
    task4();
    task5();
    task6();
    return 0;
}
