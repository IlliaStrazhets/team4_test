/*Автономність портативної зарядної станції
Максімко - СШІ-13*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

int main()
{
    //Задання змінних
    std::string modelStation;
    int years, charge, hours, minutes;
    float capacity, eff, power, capacity_eff, E_stored, E_useful, E_loss, time;

    //Оголошення змінних і перевірка на правильність введених даних
    std::cout << "Введіть модель станції: "; 
    std::cin >> modelStation;
    //Валідація моделі станції за ознакою того, що кількість символів не довша 31-го
    if(modelStation.size() > 31)
    {
        std::cout << "Назва моделі повинна бути не довша 31 символу!" << std::endl;
        return 1;
    }

    std::cout << "Введіть паспортну ємність: ";
    std::cin >> capacity;
    //Валідація на правильний тип введених даних
    if(std::cin.fail())
    {
        std::cout << "Введені дані повинні бути числом!" << std::endl;
        return 1;
    }
    //Валідація ємності станції за тим, що вона більше 0 та не більша 5000 Вт*год
    if(capacity <= 0 || capacity > 5000) 
    {
        std::cout << "Паспортна ємність повинна бути більше 0 і не більша 5000!" << std::endl;
        return 1;
    }

    std::cout << "Введіть вік станції: ";
    std::cin >> years;
    //Валідація на правильний тип введених даних
    if(std::cin.fail())
    {
        std::cout << "Введені дані повинні бути числом!" << std::endl;
        return 1;
    }
    //Валідація віку станції за тим, що він не менше 0 та не більше 20 років
    if(years < 0 || years > 20) 
    {
        std::cout << "Вік станції повинен бути від 0 до 20 років!" << std::endl;
        return 1;
    }

    std::cout << "Введіть рівень заряду: ";
    std::cin >> charge;
    //Валідація на правильний тип введених даних
    if(std::cin.fail())
    {
        std::cout << "Введені дані повинні бути числом!" << std::endl;
        return 1;
    }
    //Валідація заряду станції за тим, що він не менше 0 та не більше 100 %
    if(charge < 0 || charge > 100)
    {
        std::cout << "Рівень заряду повинен бути від 0 до 100!" << std::endl;
        return 1;
    }

    std::cout << "Введіть ККД інвертора: ";
    std::cin >> eff;
    //Валідація на правильний тип введених даних
    if(std::cin.fail())
    {
        std::cout << "Введені дані повинні бути числом!" << std::endl;
        return 1;
    }
    //Валідація ККД інвертора за тим, що воно більше 0 і не більше 100 %
    if(eff <= 0 || eff > 100)
    {
        std::cout << "ККД інвертора повинне бути більше 0, але не більше 100!" << std::endl;
        return 1;
    }

    std::cout << "Введіть потужність приладу: ";
    std::cin >> power;
    //Валідація на правильний тип введених даних
    if(std::cin.fail())
    {
        std::cout << "Введені дані повинні бути числом!" << std::endl;
        return 1;
    }
    //Валідація потужності приладу за тим, що він повинен бути не менше 0 та не більше 21000 Вт
    if(power <= 0 || power > 21000)
    {
        std::cout << "Потужність приладу повинна бути більше 0 і не більше 21000!" << std::endl;
        return 1;
    }
    
    //Константа втрати ємності
    const double LOSS = 2.0;

    //Розрахунок фактичної ємності
    capacity_eff = capacity * std::pow(1 - LOSS/100, years);
    
    //Розрахунок запасу енергії при поточному заряді
    E_stored = capacity_eff * charge / 100;

    //Розрахунок корисної енергії
    E_useful = E_stored * eff / 100;

    //Розрахунок втрати на перетворення приладу
    E_loss = E_stored - E_useful;

    //Розрахунок часу роботи
    time = E_useful / power;
    //Розрахунок повних годин
    hours = std::floor(time);
    //Розрахунок хвилин
    minutes = std::floor((time - hours) * 60);

    //Виведення даних
    std::cout << std::endl << "Модель: " << modelStation << std::endl;
    std::cout << "Паспортна ємність: " << std::fixed << std::setprecision(1) << capacity << " Вт*год " << std::endl; 
    std::cout << "Вік станції: " << years << " р. "<< std::endl;
    std::cout << "Фактична ємність: " << std::fixed << std::setprecision(1) << capacity_eff << " Вт*год " << std::endl;
    std::cout << "Рівень заряду: " << charge << " % " << std::endl;
    std::cout << "ККД інвертора: " << std::fixed << std::setprecision(2) << eff << " % " << std::endl;
    std::cout << "Запас енергії: " << std::fixed << std::setprecision(1) << E_stored << " Вт*год " << std::endl;
    std::cout << "Корисна енергія: " << std::fixed << std::setprecision(1) << E_useful << " Вт*год " << std::endl;
    std::cout << "Втрати на перетворенні: " << std::fixed << std::setprecision(1) << E_loss << " Вт*год " << std::endl;
    std::cout << "Час роботи: " << std::fixed << std::setprecision(2) << time << " год = " << std::fixed << std::setprecision(0) << hours << " год " << std::setfill('0') << std::setw(2) << minutes << " хв " << std::endl;
    return 0;
}