#include <iostream>
#include "Headers/Juego.h"

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
