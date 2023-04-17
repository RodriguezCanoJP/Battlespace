cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(serial_SRCS third-party/include/serial/serial.h third-party/include/serial/v8stdint.h third-party/src/impl/list_ports/list_ports_linux.cc third-party/src/serial.cc)
list(APPEND serial_SRCS third-party/src/impl/unix.cc)

add_library(serial ${serial_SRCS})
target_link_libraries(serial rt)

add_executable(untitled main.cpp Juego.cpp Headers/Juego.h Jugador.cpp Headers/Jugador.h Bullet.cpp Headers/Bullet.h BulletCollector.cpp Headers/BulletCollector.h Enemigo.cpp Headers/Enemigo.h ListaEnlazada.cpp Headers/ListaEnlazada.h Button.cpp Headers/Button.h)
include_directories(third-party/include)

target_include_directories(untitled PUBLIC /usr/include/SFML )
target_link_libraries(untitled sfml-system sfml-window sfml-graphics)
target_link_libraries(untitled serial)
