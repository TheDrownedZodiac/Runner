/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-20 - 14:23 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: control bind
 */

#include "fonction.h"

static void direction(struct display *ds, const bool *keycode)
{
    if (keycode[BKS_Z]) {
        stu_pixel(ds, 1);
    }
    if (keycode[BKS_Q]) {
        stu_pixel(ds, 2);
    }
    if (keycode[BKS_S]) {
        stu_pixel(ds, 3);
    }
    if (keycode[BKS_D]) {
        stu_pixel(ds, 4);
    }
}

void order(struct display *ds, const bool *keycode)
{
    direction(ds, keycode);
    if (keycode[BKS_RIGHT]) {
        ds->pos.angle = a_regul(ds->pos.angle += 11.25, 0);
    }
    if (keycode[BKS_LEFT]) {
        ds->pos.angle = a_regul(ds->pos.angle -= 11.25, 0);
    }
    if (keycode[BKS_UP]) {
        ds->pos.len += 1;
        if (ds->pos.len > 100) {
            ds->pos.len = 100;
        }
    }
    if (keycode[BKS_DOWN]) {
        ds->pos.len -= 1;
        if (ds->pos.len < 1) {
            ds->pos.len = 1;
        }
    }
    if (keycode[BKS_M]) {
        if (ds->map.show_map == 1) {
            ds->map.show_map = 0;
        } else {
            ds->map.show_map = 1;
        }
    }
}
