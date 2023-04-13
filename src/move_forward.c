/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-16 - 11:09 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: calculer un déplacement
 */

#include "fonction.h"

t_accurate_pos move_forward(const t_accurate_pos *start,
                            double angle,
                            double len)
{
    t_accurate_pos pos;

    pos.x = cos(angle) * len + start->x;
    pos.y = sin(angle) * len + start->y;
    return (pos);
}
