/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "proto.h"

char *disp_grid(char *str)
{
    char k = 'A';

    for (int j = 0; j < 17; j++) {
        if (j == 0)
            str[0] = ' ';
        else if (j == 1)
            str[1] = '|';
        else {
            if (j % 2 == 0) {
                str[j] = k;
                k++;
            }
            else
                str[j] = ' ';
        }
    }
    str[17] = '\0';
    return(str);
}

char *disp_line(char *str)
{
    for (int i = 0; i < 17; i++) {
        if (i != 1)
            str[i] = '-';
        else
            str[i] = '+'; 
    }
    str[17] = '\0';
    return(str);
}

void generic(char **tab)
{
    char nb = '1';

    for (int i = 2; i < 10; i++) {
        for (int j = 0; j < 17; j++) {
            if (j == 0) {
                tab[i][0] = nb;
                nb++;
            }
            else if (j == 1)
                tab[i][1] = '|';
            else {
                if ((j % 2) == 0)
                tab[i][j] = '.';
                else
                tab[i][j] = ' ';
            }
        }
        tab[i][17] = '\0';
    }
}

/*for each received signal, displays its name and the PID of the emitter process.
The program takes the list of signals to be rerouted as parameter. 
If a signal’s rerouting fails, an error mes-sage is displayed.*/

/*int main(int ac, char **av)
{
    int peed = 0;
    pid_t pid = 0;

    for (int i = 0; i < ac; i++) {
        peed = 0;
        pid = 0;
        for (int j = 0; av[i][j] j++)
        peed = 10*peed + (av[1][i] - '0');
        pid = (pid_t)(peed);
    }
}

int main(int ac, char **av)
{
    int peed = 0;
    for (int i =0; av[1][i]; i++)
        peed = 10*peed + (av[1][i] - '0');
    pid_t pid = (pid_t)(peed);
    int sig = kill(pid, SIGTERM);
    my_printf("pid = %d\n", pid);
    if (sig == 0)
    my_printf("pid = %d\n", pid);
    else {
        my_printf("sig = %d\n", sig);
        my_printf("kill failed\n");
    }
    return (0);
}*/