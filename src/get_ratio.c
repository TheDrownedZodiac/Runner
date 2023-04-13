/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-10 - 10:25 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: renvoie le ratio pour x entre a et b
 */

#include "fonction.h"

float get_ratio(int a, int b, int x)
{
    float ratio;

    ratio = ((float)x - (float)a) / ((float)b - (float)a);
    return (ratio);
}
