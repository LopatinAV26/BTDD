cmake_minimum_required(VERSION 3.28)

project(btdd)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall)

add_executable(${PROJECT_NAME} main.cpp
                                Game.cpp 
                                Map1.cpp 
                                Player.cpp 
                                World.cpp 
                                ForDeveloper.cpp) 

target_link_libraries(${PROJECT_NAME} libsfml-graphics.so 
                                        libsfml-window.so 
                                        libsfml-audio.so 
                                        libsfml-network.so 
                                        libsfml-system.so)