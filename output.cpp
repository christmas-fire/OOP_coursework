#include "output.h"

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
    std::cout << "║ 1. Вывести все записи (приемы пищи)     ║\n";
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

    std::cout << "+-----+---------------+--------------+------------------------------------+---------------+" << std::endl;
    std::cout << "|ID   |Дата           |Тип           |Блюдо                               |Калории        |" << std::endl;
    std::cout << "+-----+---------------+--------------+------------------------------------+---------------+" << std::endl;
    int id = 1;
    for (const auto& meal : meals) {
        std::string to_str = std::to_string(meal->getCalories());
        std::cout << std::left << std::setw(8) << id++ 
        << std::left << std::setw(15) << meal->getDate() 
        << std::left << std::setw(16) << meal->getType() 
        << std::left << std::setw(38) << meal->getName() 
        << std::right << std::setw(15) << to_str << std::endl;
    }
    std::cout << "+-----+---------------+--------------+------------------------------------+---------------+" << std::endl;
}
