
project(Fluids)

# Настройка пути к заголовочным файлам
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Добавление исполняемого файла
add_executable(Algorithms   main.c
                            search.c
                            sort.c
                            recursion.c
                            leetCode.c)
