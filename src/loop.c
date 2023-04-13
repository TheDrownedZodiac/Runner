/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-15 - 09:34 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: loop
 */

#include "fonction.h"

static int state(struct display *ds, const bool *keys)
{
    if (ds->state == 0) {
        getpath(ds, keys);
        if (ds->path == NULL) {
            return EXIT_ON_SUCCESS;
        }
    } else {
        order(ds, keys);
        fov(ds);
        if (ds->map.show_map == 0) {
            mk_map(ds, ds->px);
        }
        blit_at_origin(ds);
        if (ds->map.map[ds->map.tabcase] == 3) {
            success_end(ds);
        }
    }
    return 0;
}

t_bunny_response loop(void *data)
{
    struct display *ds;
    const bool *keys;

    ds = data;
    keys = bunny_get_keyboard();
    if (keys[BKS_ESCAPE]) {
        if (ds->state == 1) {
            free(ds->map.map);
        }
        ds->state = 0;
        stu_draw(ds);
    }
    if (state(ds, keys) == EXIT_ON_SUCCESS) {
        return EXIT_ON_SUCCESS;
    }
    return (GO_ON);
}
