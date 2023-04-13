/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-16 - 11:46 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: convert accurate pos to normal pos
 */

#include "fonction.h"



t_bunny_position pos_from_accurate(const t_accurate_pos *apos)
{
    t_bunny_position pos;

    if ((int) (apos->x * 10) % 10 < 10 && (int) (apos->x * 10) % 10 > 4) {
        pos.x = (int) apos->x + 1;
    } else {
        pos.x = (int) apos->x;
    }
    if ((int) (apos->y * 10) % 10 < 10 && (int) (apos->y * 10) % 10 > 4) {
        pos.y = (int) apos->y + 1;
    } else {
        pos.y = (int) apos->y;
    }
    return (pos);
}
