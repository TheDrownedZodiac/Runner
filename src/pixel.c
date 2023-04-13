/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_event
 * created on:  2023-01-18 - 10:35 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: put a pixel
 */

#include "fonction.h"

void tp2(struct display *ds)
{
    if (ds->map.map[ds->map.tabcase] == 7 && ds->map.code == 0) {
        map_edit(ds, 8, 9, 0);
        ds->map.code = 1;
    } else if (ds->map.map[ds->map.tabcase] == 11 && ds->map.code == 0) {
        map_edit(ds, 12, 10, 1);
    } else if (ds->map.map[ds->map.tabcase] == 13 && ds->map.code == 0) {
        map_edit(ds, 10, 12, 1);
    } else if (ds->map.map[ds->map.tabcase] == 0) {
        ds->map.code = 0;
    }
    if (ds->map.map[ds->map.tabcase] == 15 && ds->map.code == 0) {
        pos_start(ds, 16);
        ds->map.code = 1;
    } else if (ds->map.map[ds->map.tabcase] == 16 && ds->map.code == 0) {
        pos_start(ds, 15);
        ds->map.code = 1;
    }
}

static void tp(struct display *ds)
{
    if (ds->map.map[ds->map.tabcase] == 4 && ds->map.code == 0) {
        pos_start(ds, 5);
        ds->map.code = 1;
    } else if (ds->map.map[ds->map.tabcase] == 5 && ds->map.code == 0) {
        pos_start(ds, 4);
        ds->map.code = 1;
    } else if (ds->map.map[ds->map.tabcase] == 6) {
        pos_start(ds, 2);
    } else if (ds->map.map[ds->map.tabcase] == 14 && ds->map.code == 0) {
        map_edit(ds, 1, 0, 0);
        ds->map.code = 1;
    }
    tp2(ds);
}

static void border(struct display *ds)
{
    if (ds->pos.pos.x >= ds->map.tile_size * ds->map.width) {
        ds->pos.pos.x -= ds->map.tile_size * ds->map.width;
    }
    if (ds->pos.pos.x < 0) {
        ds->pos.pos.x += ds->map.tile_size * ds->map.width;
    }
    if (ds->pos.pos.y > ds->map.tile_size * ds->map.height) {
        ds->pos.pos.y -= ds->map.tile_size * ds->map.height;
    }
    if (ds->pos.pos.y < 0) {
        ds->pos.pos.y += ds->map.tile_size * ds->map.height;
    }
}

static void go(struct display *ds, int a)
{
    int round;

    round = 0;
    ds->map.tabcase = (ds->pos.origin.y / ds->map.tile_size) * (ds->map.width)
        + (ds->pos.origin.x / ds->map.tile_size);
    while (round != ds->pos.len) {
        if (ds->map.map[ds->map.tabcase] != 1 &&
            ds->map.map[ds->map.tabcase] != 9 &&
            ds->map.map[ds->map.tabcase] != 12) {
            ds->pos.pos = move_forward(&ds->pos.pos,
                                       deg_to_rad(ds->pos.angle + a), 1);
            border(ds);
        }
        ds->map.tabcase = ((int) ds->pos.pos.y / ds->map.tile_size) *
            (ds->map.width) + ((int) ds->pos.pos.x / ds->map.tile_size);
        if (ds->map.map[ds->map.tabcase] != 1 &&
            ds->map.map[ds->map.tabcase] != 9 &&
            ds->map.map[ds->map.tabcase] != 12) {
            ds->pos.origin = pos_from_pos(&ds->pos.pos);
        }
        round += 1;
    }
    tp(ds);
}

void stu_pixel(struct display *ds,
               int direction)
{
    ds->pos.pos.x = ds->pos.origin.x;
    ds->pos.pos.y = ds->pos.origin.y;
    if (direction == 1) {
        go(ds, 0);
    } else if (direction == 2) {
        go(ds, 270);
    } else if (direction == 3) {
        go(ds, 180);
    } else if (direction == 4) {
        go(ds, 90);
    }
}
