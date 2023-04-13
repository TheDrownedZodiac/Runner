/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-12 - 09:56 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: deg to rad
 */

#include <math.h>

double deg_to_rad(int degrees)
{
    double rad;

    rad = (M_PI * degrees) / 180;
    return rad;
}
