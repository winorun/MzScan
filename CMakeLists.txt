cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

set(PROJECT_NAME MzScan)
project(${PROJECT_NAME})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doxyDoc COMMAND ${DOXYGEN_EXECUTABLE} "${CMAKE_BINARY_DIR}/doxyfile"
        WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}
        COMMENT "Building user's documentation into doxyDoc build dir..."
    )
endif()

#option(CREATE_BUNDLE "Create application bundle then install" ON)
add_subdirectory(src)

