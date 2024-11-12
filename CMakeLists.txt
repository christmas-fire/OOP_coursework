# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(MealDatabaseProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление исходных файлов
set(SOURCE_FILES
    src/main.cpp
    src/database.cpp
    src/meal.cpp
    src/output.cpp
)

# Подключение SQLite3
find_package(SQLite3 REQUIRED)

# Создаем исполняемый файл
add_executable(MealDatabase ${SOURCE_FILES})

# Связываем проект с SQLite3
target_link_libraries(MealDatabase PRIVATE SQLite::SQLite3)
