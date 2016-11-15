# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.

set(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find the Qt library
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

FILE(GLOB ProjectFormsGui "*.ui")
FILE(GLOB ProjectHeaders "headers/*.h")
FILE(GLOB ProjectResources "*.qrc")
FILE(GLOB ProjectWinResources "*.rc")
set(ProjectSources  main.cpp
        myimageviewer.cpp
        mainwindow.cpp
)

QT5_WRAP_UI(ProjectFormsMoc ${ProjectFormsGui})

include_directories("headers/")
# Tell CMake to create the helloworld executable
add_executable(${PROJECT_NAME} WIN32 ${ProjectSources} ${ProjectHeaders} ${ProjectFormsMoc} ${ProjectResources} ${ProjectWinResources})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
