/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-27 - 10:55 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: regule les angles
 */

#include "fonction.h"

double a_regul(double angle, int code)
{
    if (code == 0) {
        if (angle < 0) {
            angle += 360;
        } else if (angle > 360) {
            angle -= 360;
        }
    } else if (code == 1) {
        if (angle < 0) {
            angle += (2 * M_PI);
        } else if (angle > (2 * M_PI)) {
            angle -= (2 * M_PI);
        }
    }
    return (angle);
}
