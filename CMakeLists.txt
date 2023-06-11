cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

# Recherche de la bibliothèque lib
set(SFML_DIR "lib/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(untitled main.cpp Bee.cpp Bee.h Hive.h Hive.cpp Garden.h Garden.cpp)

# Ajout des fichiers de bibliothèque lib à l'exécutable
target_link_libraries(untitled sfml-graphics sfml-system sfml-window)
