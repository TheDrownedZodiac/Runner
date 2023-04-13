/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-20 - 09:14 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: fov
 */

#include "fonction.h"

void fov(struct display *ds)
{
    t_bunny_accurate_position ba_ppos;

    background(ds->px, ds->col.col1, ds->col.col2);
    ds->vf.angle = deg_to_rad(a_regul(ds->pos.angle + (ds->pos.fov / 2), 0));
    ba_ppos.x = ds->pos.origin.x;
    ba_ppos.y = ds->pos.origin.y;
    ds->vf.count = ds->aff.win_width;
    while (ds->vf.count >= 0) {
        ds->vf.angle = a_regul(ds->vf.angle, 1);
        send_ray(ds, &ba_ppos, ds->vf.angle);
        wall(ds);
        ds->vf.wall_state = 0;
        ds->vf.angle -= ds->pos.a_path;
        ds->vf.count -= 1;
    }
}
