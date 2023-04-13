/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-15 - 09:51 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: success
 */

#include "fonction.h"

void success_end(struct display *ds)
{
    t_bunny_picture *picture;
    t_bunny_position pos;
    int round;

    round = 0;
    picture = bunny_load_picture("img/end.png");
    pos.x = ds->aff.win_width / 30;
    pos.y = ds->aff.win_height / 2.5;
    while (round < 5) {
        stu_clear_pixelarray(ds->px, BLACK);
        blit_at_origin(ds);
        usleep(3e5);
        bunny_blit(&ds->win->buffer, picture, &pos);
        bunny_display(ds->win);
        usleep(3e5);
        round += 1;
    }
    bunny_delete_clipable(picture);
    stu_draw(ds);
    ds->map.tabcase = -1;
    ds->state = 0;
    free(ds->map.map);
}
