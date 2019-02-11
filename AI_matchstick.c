/*
** EPITECH PROJECT, 2018
** AI_matchstick
** File description:
** ai for matchstick
*/
#include "my.h"

int nb_line(int *board_game, int nb)
{
    int lines = 0;
    int lines_1 = 0;

    for (int i = 0; i < nb; i = i + 1) {
        if (board_game[i] > 0)
            lines = lines + 1;
        if (board_game[i] == 1)
            lines_1 = lines_1 + 1;
    }
    if (lines == 0)
        return (-1);
    if (lines <= 3)
        return (lines);
    else if (lines_1 > (lines / 2))
        return (4);
    return (0);
}

int nmatches_in_too_many_line(int lmax, int lines, int limit, int lines_1)
{
    if (((lines - lines_1) == 1) && ((lines % 2) == 0)) {
        my_putchar('b');
        if (lmax <= (limit + 2))
            return (((lmax == (limit + 2)) ? (lmax) : (1)));
        //if (lmax == (limit + 2))
        //    return (lmax);
        else if (lmax > ((limit * 2) + 1))
            return (lmax - limit);
        else
            return (limit + 2);
    }
    else if ((lines - lines_1) == 1) {
        my_putchar('a');
        if (lmax <= (limit + 1))
            return (((lmax == (limit + 1)) ? (lmax) : (0)));
        //if (lmax == (limit + 1))
        //    return (lmax);
        else if (lmax > (limit * 2))
            return (lmax - limit);
        else
            return (limit + 1);
    }
    return (lmax);
}

int *too_many_1_matches_line(int *board_game, int nb, int limit)
{
    int lines = 0;
    int lines_1 = 0;
    int l_of_1 = 0;
    int lmax = 0;
    int memo;

    for (int i = 0; i < nb; i = i + 1) {
        lines = ((board_game[i] > 0) ? (lines + 1) : (lines));
        lines_1 = ((board_game[i] == 1) ? (lines_1 + 1) : (lines_1));
        l_of_1 = ((board_game[i] == 1) ? (i) : (l_of_1));
        lmax = ((board_game[i] > board_game[lmax]) ? (i) : (lmax));
    }
    my_putchar('c');
    memo = nmatches_in_too_many_line(board_game[lmax], lines, limit, lines_1);
    if (memo == board_game[lmax])
        board_game[l_of_1] = 0;
    else
        board_game[lmax] = memo;
    return (board_game);
}

int *random_line(int *board_game, int nb, int limit)
{
    int lmax = 0;

    for (int i = 0; i < nb; i = i + 1) {
        if (board_game[i] > board_game[lmax])
            lmax = i;
        if (board_game[i] >= limit) {
            board_game[i] = board_game[i] - limit;
            return (board_game);
        }
    }
    board_game[lmax] = 0;
    return (board_game);
}

int *ai_turn(int nb, int limit, int *board_game)
{
    int *temp;

    my_putstr("\nAI's turn...\n");
    switch(nb_line(board_game, nb)) {
        case 1 : temp = win_in_1_line(board_game, limit);
            break;
        case 2 : temp = win_in_2_lines(board_game, limit);
            break;
        case 3 : temp = win_in_3_lines(board_game, nb, limit);
            break;
        case 4 : temp = too_many_1_matches_line(board_game, nb, limit);
            break;
        default: temp = random_line(board_game, nb, limit);
    }
    return (temp);
}
