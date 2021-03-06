# Set standards
cmake_minimum_required(VERSION 2.8)
project(World_Imaker C CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/modules)

# /////////////////////////////////////////////////////////////////////////////
# ////////////////////////////// PROJECT FILES ////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

file(GLOB_RECURSE MY_COMMON src/*)

# /////////////////////////////////////////////////////////////////////////////
# /////////////////////////////// DEPENDENCIES ////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

find_package(OpenGL REQUIRED)

# On windows
if (WIN32) 
    set(SDL2_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/lib/SDL2-2.0.10/include)
    set(SDL2_LIBRARIES ${CMAKE_SOURCE_DIR}/lib/SDL2-2.0.10/lib/x64/SDL2.lib;
                       ${CMAKE_SOURCE_DIR}/lib/SDL2-2.0.10/lib/x64/SDL2main.lib)

# On linux
else()
    find_package(SDL2 REQUIRED)
endif()


find_package(EIGEN3 REQUIRED)
message(STATUS ${EIGEN3_INCLUDE_DIR})
message(STATUS ${EIGEN3_LIBRARY})

# ------------------------------ BUILD IF NEEDED ------------------------------

add_library(GLAD STATIC "lib/glad/src/glad.c")
file(GLOB_RECURSE IMGUI_SOURCES lib/imgui/*)
add_library(IMGUI STATIC ${IMGUI_SOURCES})

# /////////////////////////////////////////////////////////////////////////////
# ///////////////////////////////// INCLUDES //////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    lib/glad/include
    lib/imgui
    lib
    src
)

# /////////////////////////////////////////////////////////////////////////////
# /////////////////////////////////// BUILD ///////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${MY_COMMON} ${MY_SOURCES})
target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${SDL2_LIBRARIES}
    GLAD
    IMGUI
)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} -ldl)
endif()

if (WIN32) # Copy .dll to build folder
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/SDL2-2.0.10/lib/x64/SDL2.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()
