/*
 * E89 Pedagogical & Technical Lab
 * project:     Runner
 * created on:  2023-02-14 - 09:04 +0100
 * 1st author:  noah.chantin - noah.chantin
 * description: Read map file
 */

#include "fonction.h"

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

static void put_in_tab(struct display *ds, char *buffer)
{
    int count;
    int len;
    char *ref;

    ref = "0123456789:;<=>?@";
    count = 0;
    len = 0;
    while (buffer[count] != '\0') {
        if (stu_strchr(ref, buffer[count]) == 1) {
            ds->map.map[len] = buffer[count] - '0';
            len += 1;
        }
        count += 1;
    }
}

void read_map(struct display *ds, const char *file)
{
    int fd;
    char *buffer;
    struct stat sfile;

    fd = open(file, O_RDONLY);
    stat(file, &sfile);
    buffer = malloc(sizeof(char) * sfile.st_size + 1);
    read(fd, buffer, sfile.st_size);
    buffer[sfile.st_size] = '\0';
    count_border(ds, buffer);
    ds->map.map = malloc(sizeof(int) * ds->map.height * ds->map.width);
    put_in_tab(ds, buffer);
    close(fd);
    free(buffer);
}
