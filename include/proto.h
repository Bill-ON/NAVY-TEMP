/*
** EPITECH PROJECT, 2021
** proto.c
** File description:
** proto
*/

#ifndef PROTO_H
#define PROTO_H

struct coords {
    int size;
    int x;
    int y;
};
typedef struct coords boat;

struct fleet {
    boat smol;
    boat submarine;
    boat cruiser;
    boat aircraft_carrier;
};
typedef struct fleet player;

char *disp_grid(char *str);
char *disp_line(char *str);
void generic(char **tab);

#endif