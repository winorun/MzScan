cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

set(PROJECT_NAME MzScan)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/install)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doxyDoc COMMAND ${DOXYGEN_EXECUTABLE} "${CMAKE_HOME_DIRECTORY}/doxyfile"
        WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}
        COMMENT "Building user's documentation into doxyDoc build dir..."
    )
endif()

include (cmake/DeployQt5.cmake)

# Find the Qt library
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5WinExtras REQUIRED)

#option(CREATE_BUNDLE "Create application bundle then install" ON)
add_subdirectory(src)
add_subdirectory(lib)

SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "0")

FIND_PACKAGE(Git)
if(GIT_FOUND)
message("git found: ${GIT_EXECUTABLE}")
EXECUTE_PROCESS(
      COMMAND ${GIT_EXECUTABLE}  rev-list HEAD --count
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      OUTPUT_VARIABLE GIT_PACKAGE_VERSION_PATCH
  )
STRING(STRIP "${GIT_PACKAGE_VERSION_PATCH}"  CPACK_PACKAGE_VERSION_PATCH)
message("version: ${CPACK_PACKAGE_VERSION_PATCH}")
endif()

set(CPACK_PACKAGE_DIRECTORY ${CMAKE_HOME_DIRECTORY}/install)
set(CPACK_NSIS_MODIFY_PATH "ON")
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_HOME_DIRECTORY}/COPYING.rtf)
set(CPACK_NSIS_MUI_ICON "${CMAKE_HOME_DIRECTORY}/src/scanner.ico")
set(CPACK_GENERATOR "NSIS")
set(CPACK_CREATE_DESKTOP_LINKS "MzScan")
INSTALL(FILES ${CMAKE_HOME_DIRECTORY}/COPYING.rtf DESTINATION .)
#install_files(${CMAKE_HOME_DIRECTORY}/COPYING.rtf)
INCLUDE(CPack)
