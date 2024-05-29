project(StringSearcher)

# Настройка пути к заголовочным файлам
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Добавление исполняемого файла
add_executable(StringSearcher   main.c)
