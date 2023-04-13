/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-20 - 14:32 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: wall
 */

#include "fonction.h"

static void stu_set_line(t_bunny_pixelarray *px,
                         t_bunny_position *pos_a,
                         t_bunny_position *pos_b,
                         unsigned int color)
{
    t_bunny_position pos;
    int y;

    y = pos_a->y;
    while (y < pos_b->y) {
        pos.y = y;
        pos.x = pos_a->x;
        stu_set_pixel(px, &pos, color);
        y += 1;
    }
}

static void order1(struct display *ds,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b)
{
    if (ds->pos.block_state == 5) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(255, 165, 0, 1));
    } else if (ds->pos.block_state == 6) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(169, 17, 1, 1));
    } else if (ds->pos.block_state == 7) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(255, 192, 203, 1));
    } else if (ds->pos.block_state == 8) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(255, 20, 147, 1));
    }
    if (ds->pos.block_state == 9) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(199, 21, 133, 1));
    } else if (ds->pos.block_state == 10) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(1, 215, 88, 1));
    } else if (ds->pos.block_state == 11) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(84, 249, 141, 1));
    } else if (ds->pos.block_state == 12) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(247, 35, 12, 1));
    }
}

static void order2(struct display *ds,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b)
{
    if (ds->pos.block_state == 13) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(253, 70, 38, 1));
    } else if (ds->pos.block_state == 14) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(218, 165, 32, 1));
    } else if (ds->pos.block_state == 15) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(0, 255, 255, 1));
    } else if (ds->pos.block_state == 16) {
        stu_set_line(ds->px, pos_a, pos_b, mk_colour(0, 255, 255, 1));
    }
}

static void make_line(struct display *ds, double hgh, unsigned int col)
{
    t_bunny_position pos_a;
    t_bunny_position pos_b;

    pos_a.y = (ds->aff.win_height - hgh) / 2;
    pos_b.y = ds->aff.win_height - pos_a.y;
    pos_a.x = ds->vf.count;
    pos_b.x = ds->vf.count;
    if (ds->pos.block_state < 2) {
        stu_set_line(ds->px, &pos_a, &pos_b, mk_colour(col, col, col, 1));
    } else if (ds->pos.block_state == 2) {
        stu_set_line(ds->px, &pos_a, &pos_b, mk_colour(0, 0, 255, 1));
    } else if (ds->pos.block_state == 3) {
        stu_set_line(ds->px, &pos_a, &pos_b, mk_colour(0, 255, 0, 1));
    } else if (ds->pos.block_state == 4) {
        stu_set_line(ds->px, &pos_a, &pos_b, mk_colour(255, 165, 0, 1));
    }
    order1(ds, &pos_a, &pos_b);
    order2(ds, &pos_a, &pos_b);
}

void wall(struct display *ds)
{
    double hgh;
    double coef;
    unsigned int col;

    if (ds->pos.d < 1) {
        ds->pos.d = 1;
    }
    col = 255 - ds->pos.d * 0.16;
    if (col > 255) {
        col = 0;
    }
    coef = cos(deg_to_rad(ds->pos.angle) - ds->vf.angle);
    if (coef < 0) {
        coef *= -1;
    }
    hgh = ((ds->aff.win_height * ds->map.tile_size)
           / (coef * ds->pos.d) * 0.75);
    if (hgh < ds->aff.win_height / 24) {
        hgh = ds->aff.win_height / 24;
    } else if (hgh > ds->aff.win_height) {
        hgh = ds->aff.win_height;
    }
    make_line(ds, hgh, col);
}
