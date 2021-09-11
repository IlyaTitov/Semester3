cmake_minimum_required(VERSION 3.20)
project(Semester3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Semester3
        vector.cpp main.cpp src/Rocket.h src/Key.h src/Barrier.h src/Square.h src/Gas.h src/Barrier.cpp src/Square.cpp src/constants.h src/Gas.cpp)

# sfml include magic

include_directories(src /usr/include c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-modules")
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Semester3 ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()