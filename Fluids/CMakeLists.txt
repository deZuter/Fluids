
project(Fluids)

# Настройка пути к заголовочным файлам
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/Factories
    ${CMAKE_CURRENT_SOURCE_DIR}/Fluids
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Добавление исполняемого файла
add_executable(Main Main.cpp)
