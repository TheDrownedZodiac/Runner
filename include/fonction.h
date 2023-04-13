/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-24 - 10:40 +0100
 * 1st author:  noah.chantin - victor.vandeputte
 * description: fichier en-tête
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/stat.h>
#include <lapin.h>
#include "struct.h"

#ifndef FONCTION_H

#define FONCTION_H

typedef t_bunny_accurate_position t_accurate_pos;

void inception(struct display *ds);
t_accurate_pos farlands(struct display *ds, t_accurate_pos *laser);
t_accurate_pos rev_ray(struct display *ds, t_accurate_pos *laser,
                       t_bunny_position *temp, double angle);
void success_end(struct display *ds);
void pos_start(struct display *ds, int code);
void map_edit(struct display *ds, int nb1, int nb2, int code);
void start_map(struct display *ds);
t_bunny_response loop(void *data);
float isbtw(float low, float high, float nb);
unsigned int mk_colour(unsigned char r,
                       unsigned char g,
                       unsigned char b,
                       unsigned char a);
double deg_to_rad(int degrees);
void order(struct display *ds, const bool *keycode);
void blit_at_origin(struct display *ds);
void stu_pixel(struct display *ds,
               int direction);
t_accurate_pos move_forward(const t_accurate_pos *start,
                            double angle,
                            double len);
double a_regul(double angle, int code);
float get_ratio(int a, int b, int x);
int get_value(int a, int b, float ratio);
t_bunny_position pos_from_accurate(const t_accurate_pos *apos);
t_bunny_position pos_from_pos(const t_accurate_pos *apos);
void stu_clear_pixelarray(t_bunny_pixelarray *px, unsigned int color);
void background(t_bunny_pixelarray *px,
                unsigned int color1,
                unsigned int color2);
void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color);
void stu_set_pixel(t_bunny_pixelarray *px,
                   t_bunny_position *pos,
                   unsigned int color);
void stu_set_block(t_bunny_pixelarray *px,
                   t_bunny_position *origin,
                   int len,
                   unsigned int color);
void mk_map(struct display *ds,
            t_bunny_pixelarray *px);
t_accurate_pos send_ray(struct display *ds,
                        const t_accurate_pos *start,
                        double angle);
void fov(struct display *ds);
void wall(struct display *ds);
void success_end(struct display *ds);
void mk_mes(struct display *ds,
            t_bunny_pixelarray *px,
            unsigned int color);
void read_map(struct display *ds, const char *file);
void getpath(struct display *ds, const bool *keycode);
void count_border(struct display *ds, char *src);
void selector_map(struct display *ds, const int *tab);
void stu_draw(struct display *ds);

#endif
