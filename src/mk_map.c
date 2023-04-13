/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-17 - 11:42 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: draw the map
 */

#include "fonction.h"



static int comp(struct display *ds)
{
    int i;

    if (ds->map.height < ds->map.width) {
        i = ds->map.width;
    } else {
        i = ds->map.height;
    }
    return i;
}

static void block(struct display *ds,
                  t_bunny_pixelarray *px,
                  unsigned int color,
                  int code)
{
    t_bunny_position origin;
    int j;
    int i;

    j = 0;
    i = comp(ds);
    origin.x = 0;
    origin.y = 0;
    while (j < ds->map.width * ds->map.height) {
        if (ds->map.map[j] == code) {
            stu_set_block(px, &origin, ds->aff.win_width / i, color);
        }
        origin.x += ds->aff.win_width / i;
        if (origin.x == ds->map.width * (ds->aff.win_width / i)) {
            origin.x = 0;
            origin.y += ds->aff.win_width / i;
        }
        j += 1;
    }
}

void mk_map(struct display *ds,
            t_bunny_pixelarray *px)
{
    block(ds, px, BLACK, 0);
    block(ds, px, ds->col.col_1, 1);
    block(ds, px, ds->col.col_2, 2);
    block(ds, px, ds->col.col_3, 3);
    block(ds, px, mk_colour(255, 165, 0, 1), 4);
    block(ds, px, mk_colour(255, 165, 0, 1), 5);
    block(ds, px, mk_colour(169, 17, 1, 1), 6);
    block(ds, px, mk_colour(255, 192, 203, 1), 7);
    block(ds, px, mk_colour(255, 20, 147, 1), 8);
    block(ds, px, mk_colour(199, 21, 133, 1), 9);
    block(ds, px, mk_colour(1, 215, 88, 1), 10);
    block(ds, px, mk_colour(84, 249, 141, 1), 11);
    block(ds, px, mk_colour(247, 35, 12, 1), 12);
    block(ds, px, mk_colour(253, 70, 38, 1), 13);
    block(ds, px, mk_colour(218, 165, 32, 1), 14);
    block(ds, px, mk_colour(0, 255, 255, 1), 15);
    block(ds, px, mk_colour(0, 255, 255, 1), 16);
}
