/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-21 - 10:35 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: count border
 */

#include "fonction.h"

static void var_init(int *count, int *longer)
{
    *count = 0;
    *longer = 0;
}

static int stu_strchr(const char *str, char search)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        if (str[i] == search) {
            return 1;
        }
        i += 1;
    }
    return 0;
}

void count_border(struct display *ds, char *src)
{
    int count;
    int longer;
    char *ref;

    ref = "0123456789:;<=>?@";
    var_init(&count, &longer);
    while (src[count] != '\n') {
        if (stu_strchr(ref, src[count]) == 1) {
            longer += 1;
        }
        count += 1;
    }
    ds->map.width = longer;
    count += 1;
    longer = 1;
    while (src[count] != '\0') {
        if (src[count] == '\n') {
            longer += 1;
        }
        count += 1;
    }
    if (src[count - 1] != '\n') {
        longer += 1;
    }
    ds->map.height = longer;
}
