#include "meal.h"

void Meal::setDate(const std::string& d) {
    date = d;
}

void Meal::setType(const std::string& t) {
    type = t;
}

void Meal::setName(const std::string& n) {
    name = n;
}

void Meal::setCalories(int c) {
    calories = c;
}

const std::string& Meal::getDate() const {
    return date;
}

const std::string& Meal::getType() const {
    return type;
}

const std::string& Meal::getName() const {
    return name;
}

int Meal::getCalories() const {
    return calories;
}

