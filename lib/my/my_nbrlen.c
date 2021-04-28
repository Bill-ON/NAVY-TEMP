/*
** EPITECH PROJECT, 2021
** my_nbrlen.c
** File description:
** return the number of digit of a number
*/

int my_nbrlen(int nb)
{
    int len = 0;

    for (; nb != 0; len++)
        nb /= 10;
    return (len);
}
