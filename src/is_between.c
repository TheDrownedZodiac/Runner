/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-23 - 10:00 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: interval
 */

#include "fonction.h"

float isbtw(float low, float high, float nb)
{
    if (nb < high && nb > low) {
        return 1;
    } else {
        return 0;
    }
}
