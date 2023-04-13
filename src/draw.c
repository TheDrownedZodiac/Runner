/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-16 - 18:28 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: draw the selection menu
 */

#include "fonction.h"

const int tab[21 * 21] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 3, 1, 1, 4, 1, 5, 1, 1, 1, 1, 1, 3, 1, 1, 4, 1,
                          5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 4, 1, 5, 1, 1,
                          1, 1, 1, 3, 1, 1, 4, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          3, 1, 1, 4, 1, 5, 1, 1, 1, 1, 1, 3, 1, 1, 4, 1, 5,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 4, 1, 5, 1, 1, 1,
                          1, 1, 3, 1, 1, 4, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
                          1, 1, 4, 1, 5, 1, 1, 1, 1, 1, 3, 1, 1, 4, 1, 5, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 4, 1, 5, 1, 1, 1, 1,
                          1, 3, 1, 1, 4, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1,
                          1, 4, 1, 5, 1, 1, 1, 1, 1, 3, 1, 1, 4, 1, 5, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

static void block(t_bunny_pixelarray *px,
                  unsigned int color,
                  int code)
{
    t_bunny_position pos;
    int tabcase;

    tabcase = 0;
    pos.x = 0;
    pos.y = 0;
    while (tabcase < 21 * 21) {
        if (tab[tabcase] == code) {
            stu_set_block(px, &pos, 50, color);
        }
        pos.x += 50;
        if (pos.x == 21 * 50) {
            pos.x = 0;
            pos.y += 50;
        }
        tabcase += 1;
    }
}

void stu_draw(struct display *ds)
{
    stu_clear_pixelarray(ds->px, WHITE);
    block(ds->px, BLACK, 3);
    stu_set_block(ds->px, &ds->mapos, 50, BLUE);
    bunny_blit(&ds->win->buffer, &ds->px->clipable, NULL);
    selector_map(ds, tab);
    bunny_display(ds->win);
}
