#ifndef DATABASE_H
#define DATABASE_H

#include "meal.h"
#include <sqlite3.h>
#include <string>
#include <vector>
#include <memory>


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
    void printTable();
    bool addMeal(const Meal& meal); // Изменение здесь
    // все с датой!
    std::vector<std::unique_ptr<Meal>> getAllMeals(); // все с датой!
    std::vector<std::unique_ptr<Meal>> getAllBreakfast();// все с датой!
    std::vector<std::unique_ptr<Meal>> getAllLunch();// все с датой!
    std::vector<std::unique_ptr<Meal>> getAllDinner();// все с датой!
    std::vector<std::unique_ptr<Meal>> getAllName();// все с датой! все названия блюд
    std::vector<std::unique_ptr<Meal>> getAllCalories();// все с датой!
    std::vector<std::unique_ptr<Meal>> getOnDate(const std::string& searchDate); // все приемы пищи в конкретный день
};

#endif // DATABASE_H
