/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-17 - 10:17 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: Lancer un rayon
 */

#include "fonction.h"

static void state2(struct display *ds, int tabcase)
{
    if (tabcase == 6) {
        ds->pos.block_state = 6;
    } else if (tabcase == 7) {
        ds->pos.block_state = 7;
    } else if (tabcase == 8) {
        ds->pos.block_state = 8;
    } else if (tabcase == 9) {
        ds->pos.block_state = 9;
    }
    if (tabcase == 10) {
        ds->pos.block_state = 10;
    } else if (tabcase == 11) {
        ds->pos.block_state = 11;
    } else if (tabcase == 12) {
        ds->pos.block_state = 12;
    } else if (tabcase == 13) {
        ds->pos.block_state = 13;
    }
    if (tabcase == 14) {
        ds->pos.block_state = 14;
    } else if (tabcase == 15) {
        ds->pos.block_state = 15;
    } else if (tabcase == 16) {
        ds->pos.block_state = 16;
    }
}

static int state(struct display *ds, t_bunny_position temp)
{
    int tabcase;

    tabcase = ds->map.map[(temp.y / ds->map.tile_size) * (ds->map.width)
                          + (temp.x / ds->map.tile_size)];
    if (tabcase == 2) {
        ds->pos.block_state = 2;
    } else if (tabcase == 3) {
        ds->pos.block_state = 3;
    } else if (tabcase == 4) {
        ds->pos.block_state = 4;
    } else if (tabcase == 5) {
        ds->pos.block_state = 5;
    }
    state2(ds, tabcase);
    if (ds->pos.counter < 1) {
        ds->pos.block_state = 0;
    }
    if (tabcase < 1) {
        ds->pos.counter = 1;
    }
    return tabcase;
}

t_accurate_pos send_ray(struct display *ds,
                        const t_accurate_pos *start,
                        double angle)
{
    t_accurate_pos laser;
    t_bunny_position temp;
    int tabcase;

    ds->pos.d = 0;
    ds->pos.counter = 0;
    ds->pos.block_state = 0;
    laser.x = start->x;
    laser.y = start->y;
    temp = pos_from_accurate(&laser);
    while (ds->vf.wall_state != 1) {
        laser = move_forward(&laser, angle, 10);
        farlands(ds, &laser);
        inception(ds);
        temp = pos_from_pos(&laser);
        ds->pos.d += 10;
        ds->pos.counter -= 1;
        tabcase = state(ds, temp);
        if (tabcase == 1 || tabcase == 9 || tabcase == 12) {
            rev_ray(ds, &laser, &temp, angle);
            return laser;
        }
    }
    return laser;
}
