/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-24 - 10:43 +0100
 * 1st author:  noah.chantin - victor.vandeputte
 * description: structure
 */

#include <stddef.h>

#ifndef STRUCT_H

#define STRUCT_H

typedef t_bunny_accurate_position t_accurate_pos;

struct map {
    int tile_size;
    int width;
    int height;
    int *map;
    int tabcase;
    int code;
    int show_map;
};

struct affichage {
    t_bunny_position temp;
    int win_width;
    int win_height;
};

struct position {
    t_bunny_position origin;
    t_accurate_pos pos;
    double d;
    int len;
    double angle;
    int fov;
    double a_path;
    int block_state;
    unsigned int counter;
};

struct color {
    unsigned int col1;
    unsigned int col2;
    unsigned int col_1;
    unsigned int col_2;
    unsigned int col_3;
};

struct varfov {
    int count;
    double angle;
    double delta_a;
    int wall_state;
};

struct display {
    t_bunny_window *win;
    t_bunny_pixelarray *px;
    t_bunny_position mapos;
    char *path;
    int choix;
    int state;
    struct position pos;
    struct map map;
    struct affichage aff;
    struct color col;
    struct varfov vf;
};

#endif /* Structure de Noah Chantin et Victor Vandeputte */
