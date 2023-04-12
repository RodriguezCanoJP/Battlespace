cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Juego.cpp Headers/Juego.h Jugador.cpp Headers/Jugador.h Bullet.cpp Headers/Bullet.h BulletCollector.cpp Headers/BulletCollector.h Enemigo.cpp Headers/Enemigo.h ListaEnlazada.cpp Headers/ListaEnlazada.h)

target_include_directories(untitled PUBLIC /usr/include/SFML)
target_link_libraries(untitled sfml-system sfml-window sfml-graphics)
