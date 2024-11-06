#include "database.h"
#include "meal.h"
#include <iostream>

using namespace std;

int main() {
    Database db("meals.db");

    if (!db.open()) {
        std::cerr << "Error: can't open database" << std::endl;
        return 1;
    }

    if (!db.createTable()) {
        std::cerr << "Error: can't create table" << std::endl;
        return 1;
    }
    
    while (true) {
        std::string date, type, name;
        int calories;
        int pick;

        std::cout << "1. Посмотреть всю БД" << std::endl;
        std::cout << "2. Добавить запись" << std::endl;
        std::cout << "3. Выйти из программы" << std::endl;
        std::cout << "Выберите пункт: " << std::endl;
        cin >> pick;

        // Очищаем буфер ввода после целочисленного ввода
        cin.ignore();

        switch (pick) {
            case 1: {
                string searchDate;
                cout << "Введите дату для поиска: ";
                getline(cin, searchDate);  // Используем getline для ввода даты

                std::vector<std::unique_ptr<Meal>> meals = db.getOnDate(searchDate);

                if (meals.empty()) {
                    std::cout << "Нет записей на эту дату." << std::endl;
                } else {
                    for (const auto& meal : meals) {
                        std::cout << "Дата: " << meal->getDate() << ", Прием пищи: " << meal->getType() 
                                  << ", Блюдо: " << meal->getName() << ", Калории: " << meal->getCalories() << std::endl;
                    }
                }
                break;
            }
            case 2: {
                cout << "Введите дату: ";
                getline(cin, date);  // Используем getline вместо cin >>
                cout << "Введите прием пищи: ";
                getline(cin, type);  // Используем getline вместо cin >>
                cout << "Введите название блюда: ";
                getline(cin, name);  // Используем getline вместо cin >>
                cout << "Введите кол-во калорий этого блюда: ";
                cin >> calories;

                // Очищаем буфер ввода после целочисленного ввода
                cin.ignore();

                // Добавляем запись в базу данных
                if (type == "Breakfast" || type == "завтрак" || type == "Breakfast" || type == "Завтрак") {
                    Breakfast to_add(date, name, calories);
                    db.addMeal(to_add);
                } else if (type == "Lunch" || type == "обед" || type == "Lunch" || type == "Обед") {
                    Lunch to_add(date, name, calories);
                    db.addMeal(to_add);
                } else if (type == "Dinner" || type == "ужин" || type == "Dinner" || type == "Ужин") {
                    Dinner to_add(date, name, calories);
                    db.addMeal(to_add);
                } else {
                    std::cout << "Неизвестный тип приема пищи!" << std::endl;
                }

                break;
            }
            case 3: {
                std::cout << "Вы вышли из программы." << std::endl;
                return 0;
            } 
        }
    }

    db.close();
    return 0;
}
