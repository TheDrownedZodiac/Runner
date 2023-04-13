/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-18 - 10:10 +0200
 * 1st author:  noah.chantin - noah.chantin
 * description: Les composantes de couleur
 */

#include "fonction.h"

union colour {
    unsigned int full;
    unsigned char rgba[4];
};

unsigned int mk_colour(unsigned char r,
                       unsigned char g,
                       unsigned char b,
                       unsigned char a)
{
    union colour col;

    col.full = 0;
    col.rgba[0] = r;
    col.rgba[1] = g;
    col.rgba[2] = b;
    col.rgba[3] = a;
    return (col.full);
}
