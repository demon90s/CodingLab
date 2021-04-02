cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(inifile2lab)

set(LIBS "")
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # Linux
	set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Windows
    #add_definitions(/wd"4996" /wd"4819" /wd"4129")
endif()

# choose c++ standard
#set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*)
#source_group(TREE ${PROJECT_SOURCE_DIR}/src FILES ${SRC_FILES})

add_executable(main ${SRC_FILES})
target_link_libraries(main ${LIBS})
