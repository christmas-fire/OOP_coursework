#include "output.h"
#include <string>

void Output::printMenu() {
    std::cout << "╔════════════════════════════════╗\n";
    std::cout << "║          MEAL DATABASE         ║\n";
    std::cout << "╠════════════════════════════════╣\n";
    std::cout << "║ 1. Меню вывода БД              ║\n";
    std::cout << "║ 2. Добавление новой записи     ║\n";
    std::cout << "║ 3. Выйти из программы          ║\n";
    std::cout << "╚════════════════════════════════╝\n";
    std::cout << "Выберите пункт: ";
}

void Output::printSubMenu() {
    std::cout << "╔═════════════════════════════════════════╗\n";
    std::cout << "║            МЕНЮ ВЫВОДА БД               ║\n";
    std::cout << "╠═════════════════════════════════════════╣\n";
    std::cout << "║ 1. Вывести все записи                   ║\n";
    std::cout << "║ 2. Вывести все завтраки                 ║\n";
    std::cout << "║ 3. Вывести все обеды                    ║\n";
    std::cout << "║ 4. Вывести все ужины                    ║\n";
    std::cout << "║ 5. Вывести все конкретные блюда         ║\n";
    std::cout << "║ 6. Вывести все записи в конкретный день ║\n";
    std::cout << "║ 7. Выйти из меню вывода БД              ║\n";
    std::cout << "╚═════════════════════════════════════════╝\n";
    std::cout << "Выберите пункт: ";
}

void Output::printTable(const std::vector<std::unique_ptr<Meal>>& meals) {
    if (meals.empty()) {
        std::cout << "Нет записей по этому фильтру." << std::endl;
        return;
    }
    std::cout << std::string(80, '-') << std::endl;
    std::cout << std::left << std::setw(6) << "ID" 
         << std::setw(15) << "Date"
         << std::setw(15) << "Type"
         << std::setw(30) << "Dish name"
         << std::setw(15) << "Calories" 
         << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    int id = 1;
    for (const auto& meal : meals) {
        std::string str_c = std::to_string(meal->getCalories());

        std::cout << std::left << std::setw(6) << id++ 
        << meal->getDate() << std::string(15 - (meal->getDate().length()), ' ')
        << meal->getType() << std::string(15 - (meal->getType().length()), ' ')
        << meal->getName() << std::string(30 - (meal->getName().length()/2), ' ')
        << meal->getCalories() << std::string(15 - (str_c.length()), ' ')
        << std::endl;
    }
    std::cout << std::string(80, '-') << std::endl;
}
