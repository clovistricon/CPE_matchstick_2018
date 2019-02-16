/*
** EPITECH PROJECT, 2018
** matchstick_player
** File description:
** read player move
*/
#include "my.h"

void give_move(int player, int line, int matches)
{
    if (player == 0)
        my_putstr("Player removed ");
    else
        my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

void cmp_boards(int nb, int *memo, int *temp)
{
    int line = 0;
    int matches;

    for (; line < nb; line = line + 1) {
        if (memo[line] != temp[line])
            break;
    }
    matches = memo[line] - temp[line];
    give_move(1, line + 1, matches);
}

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
    give_move(0, line, matches);
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
    if (line < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (0);
    }
    else if ((line == 0) || (line > nb)) {
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
    if (my_put_error(board_game[line - 1], matches, limit) == 0)
        return (0);
    return (matches);
}