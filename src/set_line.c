/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-10 - 10:43 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: draw a line od pixel
 */

#include "fonction.h"

static void stu_draw_line1(t_bunny_pixelarray *px, t_bunny_position *pos_a,
                           t_bunny_position *pos_b, unsigned int color)
{
    int x;
    int y;
    t_bunny_position pos;

    x = pos_a->x;
    while (x < pos_b->x) {
        pos.x = x;
        y = get_value(pos_a->y, pos_b->y, get_ratio(pos_a->x, pos_b->x, x));
        pos.y = y;
        stu_set_pixel(px, &pos, color);
        x += 1;
    }
    return;
}

static void stu_draw_line2(t_bunny_pixelarray *px, t_bunny_position *pos_a,
                           t_bunny_position *pos_b, unsigned int color)
{
    int x;
    int y;
    t_bunny_position pos;

    y = pos_a->y;
    if (pos_a->y <= pos_b->y) {
        while (y < pos_b->y) {
            pos.y = y;
            x = get_value(pos_a->x, pos_b->x, get_ratio(pos_a->y, pos_b->y, y));
            pos.x = x;
            stu_set_pixel(px, &pos, color);
            y += 1;
        }
    } else if (pos_a->y >= pos_b->y) {
        while (y >= pos_b->y) {
            pos.y = y;
            x = get_value(pos_a->x, pos_b->x, get_ratio(pos_a->y, pos_b->y, y));
            pos.x = x;
            stu_set_pixel(px, &pos, color);
            y -= 1;
        }
    }
    return;
}

static void stu_draw_axe(t_bunny_pixelarray *px, t_bunny_position *pos_a,
                         t_bunny_position *pos_b, unsigned int color)
{
    int x;
    int y;
    t_bunny_position pos;

    if (pos_a->x != pos_b->x && pos_a->y == pos_b->y) {
        x = pos_a->x;
        while (x < pos_b->x) {
            pos.x = x;
            pos.y = pos_a->y;
            stu_set_pixel(px, &pos, color);
            x += 1;
        }
    } else if (pos_a->x == pos_b->x && pos_a->y != pos_b->y) {
        y = pos_a->y;
        while (y < pos_b->y) {
            pos.y = y;
            pos.x = pos_a->x;
            stu_set_pixel(px, &pos, color);
            y += 1;
        }
    }
    return;
}

static int order_draw(t_bunny_position *pos_a, t_bunny_position *pos_b)
{
    if (pos_a->y < pos_b->y) {
        if ((pos_b->x - pos_a->x) <= (pos_b->y - pos_a->y)) {
            return 1;
        } else if ((pos_b->x - pos_a->x) > (pos_b->y - pos_a->y)) {
            return 0;
        }
    } else if (pos_a->y > pos_b->y) {
        if ((pos_b->x - pos_a->x) <= (pos_a->y - pos_b->y)) {
            return 1;
        } else if ((pos_b->x - pos_a->x) > (pos_a->y - pos_b->y)) {
            return 0;
        }
    }
    return (-1);
}

void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color)
{
    int i;

    if (pos_a->x > pos_b->x) {
        i = pos_a->x;
        pos_a->x = pos_b->x;
        pos_b->x = i;
        i = pos_a->y;
        pos_a->y = pos_b->y;
        pos_b->y = i;
    }
    if (order_draw(pos_a, pos_b) == 0) {
        stu_draw_line1(px, pos_a, pos_b, color);
    } else if (order_draw(pos_a, pos_b) == 1) {
        stu_draw_line2(px, pos_a, pos_b, color);
    } else if (order_draw(pos_a, pos_b) == -1) {
        stu_draw_axe(px, pos_a, pos_b, color);
    }
    return;
}
