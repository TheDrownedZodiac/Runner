/*
 * E89 Pedagogical & Technical Lab
 * project:     tp cercle
 * created on:  2023-01-12 - 10:21 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: circle
 */

#include <math.h>
#include "fonction.h"

void stu_set_circle(t_bunny_pixelarray *pxa,
                    int x,
                    int y,
                    int radius)
{
    t_bunny_position pos;
    int deg;

    deg = 0;
    while (deg < 360) {
        pos.x = (cos(deg_to_rads(deg)) * radius) + x;
        pos.y = (sin(deg_to_rads(deg)) * radius * -1) +y;
        stu_set_pixel(pxa, &pos, WHITE);
        deg += 1;
    }
}
