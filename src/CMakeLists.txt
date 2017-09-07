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
target_link_libraries(${PROJECT_NAME} Qt5::Widgets eztwain Qt5::WinExtras)
#INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION bin)

if(WIN32)
   install_qt5_platform (.)
   install_qt5_lib (. Core Widgets Gui)
#                         ${Qt5_REQUERED})
#    install_qt5_V8 (bin)
#    install_qt5_icu (bin)
#    install_qt5_imageformats (bin ${Qt5_ImageFormats})
#    install_qt5_qml_plugin(bin ${Qt5_QML_PLUGINS})

    if(MINGW)
        install_qt_mingw_rt (.)
    endif(MINGW)
endif(WIN32)

INSTALL(FILES ${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME}.exe DESTINATION .)
#INSTALL(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
