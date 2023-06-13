cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

include_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/include)
link_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/lib)

add_executable(untitled main.cpp Bee.cpp Bee.h Hive.h Hive.cpp Garden.h Garden.cpp Flower.cpp Flower.h BeeTarget.cpp BeeTarget.h)

target_link_libraries(untitled sfml-graphics sfml-system sfml-window)
