# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.

set(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

FILE(GLOB ProjectFormsGui "*.ui")
FILE(GLOB ProjectHeaders "headers/*.h")
FILE(GLOB ProjectHeadersLib "../lib/*.h")
FILE(GLOB ProjectResources "*.qrc")
FILE(GLOB ProjectWinResources "*.rc")
set(ProjectSources  main.cpp
        myimageviewer.cpp
        mainwindow.cpp
)

QT5_WRAP_UI(ProjectFormsMoc ${ProjectFormsGui})

include_directories("headers/" "../lib/")
# Tell CMake to create the helloworld executable
add_executable(${PROJECT_NAME} WIN32 ${ProjectSources} ${ProjectHeaders} ${ProjectHeadersLib} ${ProjectFormsMoc} ${ProjectResources} ${ProjectWinResources})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets eztwain)
#INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION bin)
INSTALL(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .
                                LIBRARY DESTINATION .)
INCLUDE(CPack)
