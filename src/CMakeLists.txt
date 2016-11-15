# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(AUTOUIC_OPTIONS mainwindow.ui)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the Qt library
find_package(Qt5Widgets)
#find_package(Qt5Winextras)

set(SOURCES  main.cpp
        myimageviewer.cpp
        mainwindow.cpp
)
include_directories("headers/")
# Tell CMake to create the helloworld executable
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
