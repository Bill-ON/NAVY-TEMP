/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "proto.h"

void create_boat(char **tab)
{
    int x = 0;
    if (x == 1)
    return ;
}

void print_and_free(char **grid)
{
    for (int i = 0; i < 10; i++)
        my_printf("%s\n", grid[i]);
    for (int i = 0; i < 10; i++)
        free(grid[i]);
}

char *check_init(char *str)
{
    struct stat sts;
    int fd = open(str, O_RDONLY);
    char *tmp;

    if (fd < 0)
        exit(84);
    if (lstat(str, &sts) == -1)
        exit(84);
    tmp = malloc(sizeof(char) * (sts.st_size));
    if (read(fd, tmp, sts.st_size) < 0)
        exit(84);
    return(tmp);
}

char **init_file(char *str)
{
    char **tab;
    char *tmp = check_init(str);
    int col = 0;
    int ln = 0;
    int k = 0;
    
    for (; tmp[col] != '\n'; col++);
    for (int i = 0; tmp[i]; i++) {
        if (tmp[i] == '\n')
            ln++;
    }
    ln += 1;
    col += 1;
    tab = malloc(sizeof(char *) * (ln+1));
    for (int i = 0; i < (ln); i++) {
        tab[i] = malloc(sizeof(char) * (col+1));
        for (int j = 0; j < col; j++) {
            tab[i][j] = tmp[k];
            k++;
        }
    }
    return(tab);
}

int main(int ac, char **av)
{
    char **grid = malloc(sizeof(char *) * 11);
    char **instruct;

    for (int i = 0; i < 11; i++)
        grid[i] = malloc(sizeof(char) * 18);
    for (int i = 0; i < 3; i++) {
        if (i == 0)
            grid[0] = disp_grid(grid[0]);
        else if (i == 1)
            grid[1] = disp_line(grid[1]);
        else 
            generic(grid);
    }
    instruct = init_file(av[1]);
    //create_boat(grid);
    print_and_free(grid);
    return(0);
}