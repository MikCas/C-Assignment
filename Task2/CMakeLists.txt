cmake_minimum_required(VERSION 3.9)
project(Assignment2C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FIL1 Task2a.c functions.h menu.c menu.h main.c)
add_library(Task2a ${SOURCE_FIL1})

set(SOURCE_FIL2 Task2b.c functions.h menu.c menu.h main.c)
add_library(Task2b ${SOURCE_FIL2})

set(SOURCE_FIL3 Task2c.c functions.h menu.c menu.h main.c)
add_library(Task2c ${SOURCE_FIL3})

set(SOURCE_FILXA main.c functions.h menu.c menu.h)
add_executable(QAMain ${SOURCE_FILXA})
target_link_libraries(QAMain  Task2A)

set(SOURCE_FILXB main.c functions.h menu.c menu.h)
add_executable(QBMain ${SOURCE_FILXB})
target_link_libraries(QBMain Task2b)

set(SOURCE_FILXC main.c functions.h menu.c menu.h)
add_executable(QCMain ${SOURCE_FILXC})
target_link_libraries(QCMain Task2c)




