#include <iostream>
#include "Headers/Juego.h"
#include "thread"

int main()
{
    Juego juego;

    while (juego.running())
    {
        juego.update();

        juego.render();
    }

    return 0;
}
