/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-22 - 09:22 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: farlands
 */

#include "fonction.h"

t_accurate_pos farlands(struct display *ds, t_accurate_pos *laser)
{
    if (laser->x > ds->map.tile_size * ds->map.width) {
        laser->x -= ds->map.tile_size * ds->map.width;
    }
    if (laser->x < 0) {
        laser->x += ds->map.tile_size * ds->map.width;
    }
    if (laser->y > ds->map.tile_size * ds->map.height) {
        laser->y -= ds->map.tile_size * ds->map.height;
    }
    if (laser->y < 0) {
        laser->y += ds->map.tile_size * ds->map.height;
    }
    return *laser;
}
