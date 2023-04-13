/*
 * E89 Pedagogical & Technical Lab
 * project:     tp cercle
 * created on:  2023-01-12 - 10:21 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: circle
 */

#include <math.h>
#include "fonction.h"

void stu_set_spiral(t_bunny_pixelarray *pxa,
                    int x,
                    int y,
                    int radius,
                    int loops)
{
    t_bunny_position pos;
    int deg;
    int nbr_loops;
    float r;

    deg = 0;
    nbr_loops = 0;
    r = radius;
    while (nbr_loops < loops) {
        while (deg < 360) {
            pos.x = (cos(deg_to_rads(deg)) * r) + x;
            pos.y = (sin(deg_to_rads(deg)) * r * -1) +y;
            stu_set_pixel(pxa, &pos, WHITE);
            deg += 1;
            r += (float)radius / 360;
        }
        nbr_loops += 1;
        deg = 0;
    }
}
