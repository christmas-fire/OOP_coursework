#ifndef OUTPUT_H
#define OUTPUT_H

#include "database.h"

class Output {
public:
    void printMenu();
    void printSubMenu();
    void printTable(const std::vector<std::unique_ptr<Meal>>& meals);
};

#endif // OUTPUT_H