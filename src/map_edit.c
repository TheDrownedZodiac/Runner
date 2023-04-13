/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-24 - 10:46 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: main
 */

#include "fonction.h"

static void s1(struct display *ds, int nb1, int nb2)
{
    int count;

    count = 0;
    while (count < ds->map.height * ds->map.width) {
        if (ds->map.map[count] == nb1) {
            ds->map.map[count] = nb2;
        } else if (ds->map.map[count] == nb2) {
            ds->map.map[count] = nb1;
        }
        count += 1;
    }
}

static void s2(struct display *ds, int nb1, int nb2)
{
    int count;

    count = 0;
    while (count < ds->map.height * ds->map.width) {
        if (ds->map.map[count] == nb1) {
            ds->map.map[count] = nb2;
        }
        count += 1;
    }
}

void map_edit(struct display *ds, int nb1, int nb2, int code)
{
    if (code == 0) {
        s1(ds, nb1, nb2);
    } else {
        s2(ds, nb1, nb2);
    }
}
