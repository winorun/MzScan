cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

set(PROJECT_NAME MzScan)
project(${PROJECT_NAME})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doxyDoc COMMAND ${DOXYGEN_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/doxyfile"
        WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}
        COMMENT "Building user's documentation into doxyDoc build dir..."
    )
endif()

include (cmake/DeployQt5.cmake)

# Find the Qt library
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

#option(CREATE_BUNDLE "Create application bundle then install" ON)
add_subdirectory(src)
add_subdirectory(lib)

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

set(CPACK_GENERATOR NSIS)
set(CPACK_PACKAGE_NAME "MyLib")
set(CPACK_PACKAGE_VENDOR "CMake.org")

