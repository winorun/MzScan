cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME eztwain)
project(${PROJECT_NAME} C)

add_library(${PROJECT_NAME} SHARED EZTWAIN.C)
target_link_libraries(${PROJECT_NAME} Msvfw32)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .
                                LIBRARY DESTINATION .)
