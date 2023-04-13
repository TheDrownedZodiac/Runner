/*
 * E89 Pedagogical & Technical Lab
 * project:     Runner
 * created on:  2023-02-14 - 11:15 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: get a random map file
 */

#include "fonction.h"

const char *lk[13] = {"map/map1.txt", "map/map2.txt", "map/map3.txt",
                      "map/map4.txt", "map/map5.txt", "map/map6.txt",
                      "map/map7.txt", "map/map8.txt", "map/map9.txt",
                      "map/map10.txt", "map/map11.txt", "map/map12.txt",
                      "map/map13.txt"};

static void move(struct display *ds, int choix, int x, int y)
{
    ds->choix += choix;
    ds->mapos.x += x;
    ds->mapos.y += y;
    stu_draw(ds);
    usleep(2e4);
}

static void fleche(struct display *ds,
                   const bool *keycode)
{
    if (keycode[BKS_UP] || keycode[BKS_Z]) {
        if (ds->choix != 1 && ds->choix != 8) {
            move(ds, -1, 0, -2 * 50);
        }
    } else if (keycode[BKS_DOWN] || keycode[BKS_S]) {
        if (ds->choix != 14 && ds->choix != 7) {
            move(ds, 1, 0, 2 * 50);
        }
    } else if (keycode[BKS_LEFT] || keycode[BKS_Q]) {
        if (ds->choix > 7) {
            move(ds, -7, -11 * 50, 0);
        }
    } else if (keycode[BKS_RIGHT] || keycode[BKS_D]) {
        if (ds->choix < 8) {
            move(ds, 7, 11 * 50, 0);
        }
    }
}

void getpath(struct display *ds, const bool *keycode)
{
    fleche(ds, keycode);
    if (keycode[BKS_SPACE] || keycode[BKS_RETURN]) {
        if (ds->choix == 14) {
            ds->path = NULL;
        } else {
            ds->path = (char *) lk[ds->choix - 1];
            read_map(ds, ds->path);
            pos_start(ds, 2);
            ds->state = 1;
        }
    }
}
