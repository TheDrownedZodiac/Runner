/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-10 - 10:42 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: actualise la fenêtre
 */

#include "fonction.h"

void blit_at_origin(struct display *ds)
{
    bunny_blit(&ds->win->buffer, &ds->px->clipable, NULL);
    bunny_display(ds->win);
}
