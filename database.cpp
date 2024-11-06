#include "database.h"
#include <iostream>
#include <memory>

Database::Database(const std::string& dbFile) : db(nullptr), dbFile(dbFile) {}

Database::~Database() {
    close();
}

bool Database::open() {
    int rc = sqlite3_open(dbFile.c_str(), &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

void Database::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::createTable() {
    const char* sql = "CREATE TABLE IF NOT EXISTS meals ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "date TEXT NOL NULL, "
                      "type TEXT NOT NULL, "
                      "name TEXT NOT NULL, "
                      "calories INTEGER NOT NULL);";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::addMeal(const Meal& meal) {
    std::string sql = "INSERT INTO meals (date, type, name, calories) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // Используем виртуальные методы для получения информации о приёме пищи
    sqlite3_bind_text(stmt, 1, meal.getDate().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, meal.getType().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, meal.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, meal.getCalories()); // Исправлено на 3, так как это третий параметр

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc != SQLITE_DONE) {
        std::cerr << "Failed to insert data: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

std::vector<std::unique_ptr<Meal>> Database::getAllMeals() {
    std::vector<std::unique_ptr<Meal>> meals;
    const char* sql = "SELECT date, type, name, calories FROM meals;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return meals;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int calories = sqlite3_column_int(stmt, 3);

        // Создаем объект соответствующего типа на основе типа из базы данных
        if (type == "Breakfast") {
            meals.emplace_back(std::make_unique<Breakfast>(date, name, calories));
        } else if (type == "Lunch") {
            meals.emplace_back(std::make_unique<Lunch>(date, name, calories));
        } else if (type == "Dinner") {
            meals.emplace_back(std::make_unique<Dinner>(date, name, calories));
        }
    }

    sqlite3_finalize(stmt);
    return meals;
}

std::vector<std::unique_ptr<Meal>> Database::getOnDate(const std::string& searchDate) {
    std::vector<std::unique_ptr<Meal>> meals;
    const char* sql = "SELECT date, type, name, calories FROM meals WHERE date = ?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return meals;
    }

    // Привязываем значение searchDate к параметру в запросе
    sqlite3_bind_text(stmt, 1, searchDate.c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int calories = sqlite3_column_int(stmt, 3);

        // Создаем объект соответствующего типа на основе типа из базы данных
        if (type == "Breakfast") {
            meals.emplace_back(std::make_unique<Breakfast>(date, name, calories));
        } else if (type == "Lunch") {
            meals.emplace_back(std::make_unique<Lunch>(date, name, calories));
        } else if (type == "Dinner") {
            meals.emplace_back(std::make_unique<Dinner>(date, name, calories));
        }
    }

    sqlite3_finalize(stmt);
    return meals;
}


// реализовать принт в зависимости от функции (или вынести все в отдельный файл output.cpp)
void Database::printTable() {
    for (const auto& meal : this->getAllMeals()) {
        std::cout
        << "| " << meal->getDate() << " |" << " "
        << "| " << meal->getType() << " |" << " "
        << "| " << meal->getName() << " |" << " "
        << "| " << meal->getCalories() << " |" << "\n";
    }
}