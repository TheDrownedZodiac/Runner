/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-24 - 10:46 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: main
 */

#include "fonction.h"

static t_bunny_response my_key_event_def(t_bunny_event_state state,
                                         t_bunny_keysym keycode,
                                         void *my_data)
{
    keycode = keycode;
    state = state;
    my_data = my_data;
    return GO_ON;
}

static void map_init(struct display *ds)
{
    ds->col.col1 = mk_colour(50, 50, 50, 1);
    ds->col.col2 = mk_colour(0, 0, 0, 1);
    ds->col.col_1 = mk_colour(255, 255, 255, 1);
    ds->col.col_2 = mk_colour(0, 0, 255, 1);
    ds->col.col_3 = mk_colour(0, 255, 0, 1);
    ds->map.tile_size = 100;
    ds->pos.len = 15;
    ds->pos.fov = 70;
    ds->choix = 1;
    ds->map.show_map = 1;
    ds->mapos.x = 2 * 50;
    ds->mapos.y = 4 * 50;
    ds->path = "0";
    ds->pos.a_path = (M_PI * ((double) ds->pos.fov / ds->aff.win_width)) / 180;
}

int main(void)
{
    struct display ds;

    ds.state = 0;
    ds.map.tabcase = 0;
    ds.aff.win_width = 1050;
    ds.aff.win_height = 1050;
    ds.win = bunny_start(ds.aff.win_width,
                         ds.aff.win_height, false, "fl: Runner_Map");
    ds.px = bunny_new_pixelarray(ds.win->buffer.width,
                                 ds.win->buffer.height);
    map_init(&ds);
    stu_draw(&ds);
    bunny_set_key_response(my_key_event_def);
    bunny_set_loop_main_function(loop);
    bunny_loop(ds.win, 60, &ds);
    bunny_delete_clipable(&ds.px->clipable);
    bunny_stop(ds.win);
    return (EXIT_ON_SUCCESS);
}
