#include "database.h"

Database::Database(const std::string& dbFile) : db(nullptr), dbFile(dbFile) {}

Database::~Database() {
    close();
}

// Открыть БД
bool Database::open() {
    int rc = sqlite3_open(dbFile.c_str(), &db);
    if (rc) {
        std::cerr << "Error: can't open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

// Закрыть БД
void Database::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

// Создать таблицу
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
        std::cerr << "Error: SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

// Добавить запись
bool Database::addMeal(const Meal& meal) {
    std::string sql = "INSERT INTO meals (date, type, name, calories) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Error: failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // Привязываем поля класса приема пищи к параметрам в запросе
    sqlite3_bind_text(stmt, 1, meal.getDate().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, meal.getType().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, meal.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, meal.getCalories());

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc != SQLITE_DONE) {
        std::cerr << "Error: failed to insert data: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

// Получить все записи
std::vector<std::unique_ptr<Meal>> Database::getAllMeals() {
    std::vector<std::unique_ptr<Meal>> meals;
    const char* sql = "SELECT date, type, name, calories FROM meals;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Error: failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return meals;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int calories = sqlite3_column_int(stmt, 3);

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

// Получить все завтраки
std::vector<std::unique_ptr<Meal>> Database::getAllBreakfast() {
    std::vector<std::unique_ptr<Meal>> meals;
    const char* sql = "SELECT date, type, name, calories calories FROM meals WHERE type = 'Breakfast';";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Error: failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return meals;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int calories = sqlite3_column_int(stmt, 3);

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

// Получить все обеды
std::vector<std::unique_ptr<Meal>> Database::getAllLunch() {
    std::vector<std::unique_ptr<Meal>> meals;
    const char* sql = "SELECT date, type, name, calories calories FROM meals WHERE type = 'Lunch';";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Error: failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return meals;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int calories = sqlite3_column_int(stmt, 3);

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

// Получить все обеды
std::vector<std::unique_ptr<Meal>> Database::getAllDinner() {
    std::vector<std::unique_ptr<Meal>> meals;
    const char* sql = "SELECT date, type, name, calories calories FROM meals WHERE type = 'Dinner';";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Error: failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return meals;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int calories = sqlite3_column_int(stmt, 3);

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

// Получить все записи с конкретным названием блюда
std::vector<std::unique_ptr<Meal>> Database::getByName(const std::string& nameToSearch) {
    std::vector<std::unique_ptr<Meal>> meals;
    const char* sql = "SELECT date, type, name, calories FROM meals WHERE name = ?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Error: failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return meals;
    }

    // Привязываем значение nameToSearch к параметру в запросе
    sqlite3_bind_text(stmt, 1, nameToSearch.c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int calories = sqlite3_column_int(stmt, 3);

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

// Получить все записи в конкретный день
std::vector<std::unique_ptr<Meal>> Database::getByDate(const std::string& dateToSearch) {
    std::vector<std::unique_ptr<Meal>> meals;
    const char* sql = "SELECT date, type, name, calories FROM meals WHERE date = ?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Error: failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return meals;
    }

    // Привязываем значение dateToSearch к параметру в запросе
    sqlite3_bind_text(stmt, 1, dateToSearch.c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int calories = sqlite3_column_int(stmt, 3);

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
