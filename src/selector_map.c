/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-15 - 09:33 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: select the map
 */

#include "fonction.h"

const char *stk[14] = {"img/1.png", "img/8.png", "img/2.png", "img/9.png",
                       "img/3.png", "img/10.png", "img/4.png", "img/11.png",
                       "img/5.png", "img/12.png", "img/6.png", "img/13.png",
                       "img/7.png", "img/0exit.png"};

static void stu_print(struct display *ds,
                      int code,
                      const char *path,
                      t_bunny_position *pos)
{
    t_bunny_picture *pts;

    pos->x += 15;
    pos->y += 15;
    if (code == 4) {
        pts = bunny_load_picture("img/0:.png");
    } else if (code == 5){
        pts = bunny_load_picture(path);
    }
    bunny_blit(&ds->win->buffer, pts, pos);
    pos->x -= 15;
    pos->y -= 15;
}

static void bblock(struct display *ds,
                   int code,
                   const int *tab)
{
    t_bunny_position pos;
    int tabcase;
    int path;

    tabcase = 0;
    path = 0;
    pos.x = 0;
    pos.y = 0;
    while (tabcase < 21 * 21) {
        if (tab[tabcase] == code) {
            stu_print(ds, code, stk[path], &pos);
            if (code == 5) {
                path += 1;
            }
        }
        pos.x += 50;
        if (pos.x == 21 * 50) {
            pos.x = 0;
            pos.y += 50;
        }
        tabcase += 1;
    }
}

static void runner(struct display *ds)
{
    t_bunny_picture *picture;
    t_bunny_position pos;

    picture = bunny_load_picture("img/runner.png");
    pos.x = 198;
    pos.y = 50;
    picture->scale.x = 0.5;
    picture->scale.y = 0.5;
    bunny_blit(&ds->win->buffer, picture, &pos);
}

void selector_map(struct display *ds, const int *tab)
{
    runner(ds);
    bblock(ds, 4, tab);
    bblock(ds, 5, tab);
}
