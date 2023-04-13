/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-17 - 11:31 +0200
 * Authors:  noah.chantin - noah.chantin
 * description: create square block of pixel
 */

#include "fonction.h"

void stu_set_block(t_bunny_pixelarray *px,
                   t_bunny_position *origin,
                   int len,
                   unsigned int color)
{
    int i;
    int n;
    int width;
    int height;
    t_bunny_position pos;

    i = 0;
    pos.y = origin->y;
    width = len;
    height = len;
    while (i < height) {
        n = 0;
        pos.x = origin->x;
        while (n < width) {
            stu_set_pixel(px, &pos, color);
            pos.x += 1;
            n += 1;
        }
        pos.y += 1;
        i += 1;
    }
}
