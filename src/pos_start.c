/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-24 - 10:46 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: main
 */

#include "fonction.h"

static void angle(struct display *ds, int coord)
{
    if (ds->map.map[coord + 1] != 1) {
        ds->pos.angle = 0;
    } else if (ds->map.map[coord - 1] != 1) {
        ds->pos.angle = 180;
    } else if (ds->map.map[coord + ds->map.width] != 1) {
        ds->pos.angle = 90;
    } else if (ds->map.map[coord - ds->map.width] != 1) {
        ds->pos.angle = 270;
    }
}

void pos_start(struct display *ds, int code)
{
    int x;
    int y;

    y = 0;
    while (y < ds->map.height) {
        x = 0;
        while (x < ds->map.width) {
            if (ds->map.map[(y * ds->map.width) + x] == code) {
                ds->pos.origin.x = (x + 0.5) * ds->map.tile_size;
                ds->pos.origin.y = (y + 0.5) * ds->map.tile_size;
                angle(ds, (y * ds->map.width) + x);
            }
            x += 1;
        }
        y += 1;
    }
}