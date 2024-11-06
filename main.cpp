#include "database.h"
#include "meal.h"
#include <iostream>

using namespace std;

void print(std::vector<std::unique_ptr<Meal>>& meals) {
    if (meals.empty()) {
        std::cout << "Нет записей по этому фильтру." << std::endl;
    } else {
        for (const auto& meal : meals) {
            std::cout << "Дата: " << meal->getDate() << ", Прием пищи: " << meal->getType() 
                    << ", Блюдо: " << meal->getName() << ", Калории: " << meal->getCalories() << std::endl;
        }
    }
}

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

        std::cout << "1. Меню вывода БД" << std::endl;
        std::cout << "2. Добавление новой записи" << std::endl;
        std::cout << "3. Выйти из программы" << std::endl;
        std::cout << "Выберите пункт: " << std::endl;
        cin >> pick;
        cin.ignore();

        switch (pick) {
            case 1: {
                int subpick;

                std::cout << "1. Вывести все записи (приемы пищи)" << std::endl;
                std::cout << "2. Вывести все завтраки" << std::endl;
                std::cout << "3. Вывести все обеды" << std::endl;
                std::cout << "4. Вывести все ужины" << std::endl;
                std::cout << "5. Вывести все конкретные блюда" << std::endl;
                std::cout << "6. Вывести все записи в конкретный день" << std::endl;
                std::cout << "7. Выйти из меню вывода БД" << std::endl;
                std::cout << "Выберите пункт: " << std::endl;
                cin >> subpick;
                cin.ignore();

                switch (subpick) {
                    case 1: {
                        vector<unique_ptr<Meal>> meals = db.getAllMeals();
                        print(meals);
                        break;
                    }
                    case 2: {
                        vector<unique_ptr<Meal>> breakfasts = db.getAllBreakfast();
                        print(breakfasts);
                        break;
                    }
                    case 3: {
                        vector<unique_ptr<Meal>> lunches = db.getAllLunch();
                        print(lunches);
                        break;
                    }
                    case 4: {
                        vector<unique_ptr<Meal>> dinners = db.getAllDinner();
                        print(dinners);
                        break;
                    }
                    case 5: {
                        string searchName;
                        cout << "Введите название блюда для поиска: ";
                        getline(cin, searchName);  // Используем getline для ввода даты
                        cin.ignore();

                        std::vector<std::unique_ptr<Meal>> meals = db.getOnName(searchName);
                        print(meals);
                        break;
                    }
                    case 6: {
                        string searchDate;
                        cout << "Введите дату для поиска: ";
                        getline(cin, searchDate);  // Используем getline для ввода даты
                        cin.ignore();

                        std::vector<std::unique_ptr<Meal>> meals = db.getOnDate(searchDate);
                        print(meals);
                        break;
                    }
                    case 7: {
                        std::cout << "Вы вышли из меню вывода БД." << std::endl;
                        break;
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
                break;
            } 
        }
    }

    db.close();
    return 0;
}
