#include <stdio.h>
#include "stos.h"

void InicjujStos(Stos * ws)
{
    ws->gora = 0;
}

bool PelnyStos(const Stos * ws)
{
    return ws->gora == MAXSTOS;
}


bool PustyStos(const Stos * ws)
{
    return ws->gora == 0;
}

bool Poloz(Pozycja pozycja, Stos * ws)
{
    if (ws->gora == MAXSTOS)
        return false;
    else
    {
        ws->pozycje[ws->gora++] = pozycja;
        return true;
    }

}

bool Zdejmij(Pozycja *wpozycja, Stos * ws)
{
    if (ws->gora == 0)
        return false;
    else
    {
        ws->gora--;
        *wpozycja = ws->pozycje[ws->gora];
        return true;
    }

}
