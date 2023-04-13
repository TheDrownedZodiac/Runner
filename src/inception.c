/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-22 - 09:24 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: inception
 */

#include "fonction.h"

void inception(struct display *ds)
{
    if (ds->map.height < ds->map.width) {
        if (ds->pos.d > 2 * ds->map.tile_size * ds->map.width) {
            ds->vf.wall_state = 1;
        }
    } else {
        if (ds->pos.d > 2 * ds->map.tile_size * ds->map.height) {
            ds->vf.wall_state = 1;
        }
    }
}

