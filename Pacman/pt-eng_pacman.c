// C_Cpp.clang_format_fallbackStyle

#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m;
POSICAO player;

int acabou()
{
    return 0;
}

void move(char direcao)
{
    int x;
    int y;

    m.matriz[player.x][player.y] = '.';

    switch (direcao)
    {
    case 'a':
        m.matriz[player.x][player.y - 1] = '@';
        player.y--;
        break;

    case 'w':
        m.matriz[player.x - 1][player.y] = '@';
        player.x--;
        break;

    case 's':
        m.matriz[player.x + 1][player.y] = '@';
        player.x++;
        break;

    case 'd':
        m.matriz[player.x][player.y + 1] = '@';
        player.y++;
        break;
    }
}

int main()
{
    leMapa(&m);
    encontraPlayer(&m, &player, '@');

    do
    {
        imprimeMapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());

    liberaMapa(&m);
}