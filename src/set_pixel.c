/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-19 - 14:14 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: set pixel
 */

#include "fonction.h"

void stu_set_pixel(t_bunny_pixelarray *px,
                   t_bunny_position *pos,
                   unsigned int color)
{
    unsigned int *tableau;
    int xpos;
    int width;
    int height;

    width = px->clipable.clip_width;
    height = px->clipable.clip_height;
    tableau = (unsigned int *) px->pixels;
    xpos = (pos->y * width) + pos->x;
    if ((pos->y < height && pos->y >= 0)
        && (pos->x < width && pos->x >= 0)) {
        tableau[xpos] = color;
    }
}
