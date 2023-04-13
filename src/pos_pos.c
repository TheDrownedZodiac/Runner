/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-16 - 11:46 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: convert accurate pos to normal pos
 */

#include "fonction.h"

t_bunny_position pos_from_pos(const t_accurate_pos *apos)
{
    t_bunny_position pos;

    pos.x = (int) apos->x;
    pos.y = (int) apos->y;
    return (pos);
}
