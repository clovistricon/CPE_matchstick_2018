/*
** EPITECH PROJECT, 2018
** matchstick_player
** File description:
** read player move
*/
#include "my.h"

int *player_turn(int nb, int limit, int *board_game)
{
    int line = 0;
    int matches = 0;

    my_putstr("\nYour turn:\n");
    while ((line == 0) || (matches == 0)) {
        line = player_line(nb);
        if (line == -1)
            return (NULL);
        else if (line <= 0)
            continue;
        matches = player_matches(line, limit, board_game);
        if (matches == -1)
            return (NULL);
        else if (matches <= 0)
            continue;
    }
    board_game[line - 1] = board_game[line - 1] - matches;
    return (board_game);
}

int player_line(int nb)
{
    char *buff;
    int line;

    my_putstr("Line: ");
    buff = get_next_line(0);
    if (buff== NULL)
        return (-1);
    line = my_getnbr(buff);
    free(buff);
    if ((line <= 0) || (line > nb)) {
        my_putstr("Error: this line is out of range\n");
        return (0);
    }
    return (line);
}

int player_matches(int line, int limit, int *board_game)
{
    char *buff;
    int matches;

    my_putstr("Matches: ");
    buff = get_next_line(0);
    if (buff == NULL)
        return (-1);
    matches = my_getnbr(buff);
    free(buff);
    if ((matches <= 0) || (matches > limit)) {
        my_putstr("Error: you have to remove at least one matches\n");
        return (0);
    }
    else if (matches > board_game[line - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return (0);
    }
    return (matches);
}