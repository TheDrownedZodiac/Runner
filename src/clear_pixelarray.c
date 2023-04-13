/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-17 - 11:31 +0200
 * Authors:  victor.vandeputte - victor.vandeputte
 * description: Change window colour
 */

#include "fonction.h"

void stu_clear_pixelarray(t_bunny_pixelarray *px, unsigned int color)
{
    int i;
    int width;
    int height;
    unsigned int *tableau;

    tableau = (unsigned int *)px->pixels;
    width = px->clipable.clip_width;
    height = px->clipable.clip_height;
    i = 0;
    while (i < (width * height)) {
        tableau[i] = color;
        i += 1;
    }
}
