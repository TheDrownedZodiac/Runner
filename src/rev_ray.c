/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-22 - 09:22 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: rev ray
 */

#include "fonction.h"

t_accurate_pos rev_ray(struct display *ds, t_accurate_pos *laser,
                       t_bunny_position *temp, double angle)
{
    int tabcase;

    tabcase = ds->map.map[(temp->y / ds->map.tile_size) * (ds->map.width)
                          + (temp->x / ds->map.tile_size)];
    while (tabcase == 1 || tabcase == 9 || tabcase == 12) {
        if (ds->pos.d < 110) {
            *laser = move_forward(laser, angle + M_PI, 0.11);
            ds->pos.d -= 0.11;
        } else {
            *laser = move_forward(laser, angle + M_PI, 0.35);
            ds->pos.d -= 0.35;
        }
        if (ds->pos.d < 0) {
            ds->pos.d = 0;
            return *laser;
        }
        farlands(ds, laser);
        *temp = pos_from_pos(laser);
        tabcase = ds->map.map[(temp->y / ds->map.tile_size) * (ds->map.width)
                              + (temp->x / ds->map.tile_size)];
    }
    return *laser;
}
