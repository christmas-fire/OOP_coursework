#ifndef DATABASE_H
#define DATABASE_H

#include "meal.h"
#include <sqlite3.h>

#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>

// Класс "БД"
class Database {
private:
    sqlite3* db;
    std::string dbFile;
public:
    Database(const std::string& dbFile);
    ~Database();

    bool open();
    void close();

    bool createTable();
    bool addMeal(const Meal& meal);

    std::vector<std::unique_ptr<Meal>> getAllMeals();
    std::vector<std::unique_ptr<Meal>> getAllBreakfast();
    std::vector<std::unique_ptr<Meal>> getAllLunch();
    std::vector<std::unique_ptr<Meal>> getAllDinner();
    std::vector<std::unique_ptr<Meal>> getByName(const std::string& searchName);
    std::vector<std::unique_ptr<Meal>> getByDate(const std::string& searchDate);
};

#endif // DATABASE_H
