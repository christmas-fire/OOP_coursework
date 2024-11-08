#ifndef MEAL_H
#define MEAL_H

#include <string>

// Интерфейс "прием пищи"
class Meal {
private:
    std::string date;
    std::string type;
    std::string name;
    int calories;
public:
    Meal(const std::string& date, const std::string& type, const std::string& name, int calories)
        : date(date), type(type), name(name), calories(calories) {}
    virtual ~Meal() = default;

    virtual void setDate(const std::string& d);
    virtual void setType(const std::string& t);
    virtual void setName(const std::string& n);
    virtual void setCalories(int c);

    virtual const std::string& getDate() const;
    virtual const std::string& getType() const;
    virtual const std::string& getName() const;
    virtual int getCalories() const;
};

// Класс "завтрак"
class Breakfast : public Meal {
public:
    Breakfast(const std::string& date, const std::string& name, int calories)
        : Meal(date, "Breakfast", name, calories) {}

    void setDate(const std::string& d) override { Meal::setDate(d); }
    void setType(const std::string& t) override { Meal::setType(t); }
    void setName(const std::string& n) override { Meal::setName(n); }
    void setCalories(int c) override { Meal::setCalories(c); }

    const std::string& getDate() const override { return Meal::getDate(); }
    const std::string& getType() const override { return Meal::getType(); }
    const std::string& getName() const override { return Meal::getName(); }
    int getCalories() const override { return Meal::getCalories(); }
};

// Класс "обед"
class Lunch : public Meal {
public:
    Lunch(const std::string& date, const std::string& name, int calories)
        : Meal(date, "Lunch", name, calories) {}
    
    void setDate(const std::string& d) override { Meal::setDate(d); }
    void setType(const std::string& t) override { Meal::setType(t); }
    void setName(const std::string& n) override { Meal::setName(n); }
    void setCalories(int c) override { Meal::setCalories(c); }

    const std::string& getDate() const override { return Meal::getDate(); }
    const std::string& getType() const override { return Meal::getType(); }
    const std::string& getName() const override { return Meal::getName(); }
    int getCalories() const override { return Meal::getCalories(); }
};

// Класс "ужин"
class Dinner : public Meal {
public:
    Dinner(const std::string& date, const std::string& name, int calories)
        : Meal(date, "Dinner", name, calories) {}
    
    void setDate(const std::string& d) override { Meal::setDate(d); }
    void setType(const std::string& t) override { Meal::setType(t); }
    void setName(const std::string& n) override { Meal::setName(n); }
    void setCalories(int c) override { Meal::setCalories(c); }

    const std::string& getDate() const override { return Meal::getDate(); }
    const std::string& getType() const override { return Meal::getType(); }
    const std::string& getName() const override { return Meal::getName(); }
    int getCalories() const override { return Meal::getCalories(); }
};

#endif // MEAL_H
