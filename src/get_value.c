/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-10 - 10:26 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: depuis un ratio retrouve une valeur
 */

#include "fonction.h"

int get_value(int a, int b, float ratio)
{
    int x;

    x = (ratio * (b - a)) + a;
    return (x);
}
