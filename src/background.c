/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-17 - 11:31 +0200
 * Authors:  noah.chantin - noah.chantin
 * description: Change window colour
 */

#include "fonction.h"

void background(t_bunny_pixelarray *px,
                          unsigned int color1,
                          unsigned int color2)
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
        if (i > (width * height) / 2) {
            tableau[i] = color1;
            i += 1;
        } else {
            tableau[i] = color2;
            i += 1;
        }
    }
}
