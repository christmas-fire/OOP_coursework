#include "database.h"
#include "meal.h"
#include "output.h"

int main() {
    Database db("meals.db");
    Output my_output;

    // Если файл БД не открылся, выводим сообщение об ошибке и завершаем работу программы
    if (!db.open()) {
        std::cerr << "Error: can't open database" << std::endl;
        return 1;
    }

    // Если таблица в БД не создалась, выводим сообщение об ошибке и завершаем работу программы
    if (!db.createTable()) {
        std::cerr << "Error: can't create table" << std::endl;
        return 1;
    }
    
    while (true) {
        std::string date, type, name;
        int calories;
        int choice;

        my_output.printMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                int subChoice;
                my_output.printSubMenu();
                std::cin >> subChoice;
                std::cin.ignore();

                switch (subChoice) {
                    case 1: {
                        // Ищем и выводим все приемы пищи
                        std::vector<std::unique_ptr<Meal>> meals = db.getAllMeals();
                        my_output.printTable(meals);
                        break;
                    }
                    case 2: {
                        // Ищем и выводим все завтраки
                        std::vector<std::unique_ptr<Meal>> breakfasts = db.getAllBreakfast();
                        my_output.printTable(breakfasts);
                        break;
                    }
                    case 3: {
                        // Ищем и выводим все обеды
                        std::vector<std::unique_ptr<Meal>> lunches = db.getAllLunch();
                        my_output.printTable(lunches);
                        break;
                    }
                    case 4: {
                        // Ищем и выводим все ужины
                        std::vector<std::unique_ptr<Meal>> dinners = db.getAllDinner();
                        my_output.printTable(dinners);
                        break;
                    }
                    case 5: {
                        // Ищем и выводим конкретные приемы пищи
                        std::string nameToSearch;
                        std::cout << "Введите название блюда для поиска: ";
                        std::getline(std::cin, nameToSearch);

                        std::vector<std::unique_ptr<Meal>> meals = db.getByName(nameToSearch);
                        my_output.printTable(meals);
                        break;
                    }
                    case 6: {
                        // Ищем и выводим приемы пищи в конкретную дату
                        std::string dateToSearch;
                        std::cout << "Введите дату для поиска: ";
                        std::getline(std::cin, dateToSearch);

                        std::vector<std::unique_ptr<Meal>> meals = db.getByDate(dateToSearch);
                        my_output.printTable(meals);
                        break;
                    }
                    case 7: {
                        // Завершаем работу меню вывода БД
                        std::cout << "Вы вышли из меню вывода БД." << std::endl;
                        break;
                    }
                }
                break;
            }
            case 2: {
                // Ввод информации о приеме пищи
                std::cout << "Введите дату: ";
                std::getline(std::cin, date);
                std::cout << "Введите прием пищи: ";
                std::getline(std::cin, type);
                std::cout << "Введите название блюда: ";
                std::getline(std::cin, name);
                std::cout << "Введите кол-во калорий этого блюда: ";
                std::cin >> calories;
                std::cin.ignore();

                // Добавляем запись в базу данных
                if (type == "Breakfast" || type == "завтрак" || type == "breakfast" || type == "Завтрак") {
                    Breakfast toAdd(date, name, calories);
                    db.addMeal(toAdd);
                } else if (type == "Lunch" || type == "обед" || type == "lunch" || type == "Обед") {
                    Lunch toAdd(date, name, calories);
                    db.addMeal(toAdd);
                } else if (type == "Dinner" || type == "ужин" || type == "dinner" || type == "Ужин") {
                    Dinner toAdd(date, name, calories);
                    db.addMeal(toAdd);
                } else {
                    std::cerr << "Error: unknown type of meal." << std::endl;
                    return 1;
                }
                break;
            }
            case 3: {
                // Завершаем работу программы
                std::cout << "Вы вышли из программы." << std::endl;
                return 0;
            } 
        }
    }
    db.close();
    return 0;
}
