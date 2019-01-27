/*
** EPITECH PROJECT, 2018
** AI_strat
** File description:
** strats for AI_matchstick
*/
#include "my.h"

int two_l(int line1, int line2, int limit)
{
    int n = 1;
    int diff = line1 - line2;

    if (line2 == 1)
        n = 0;
    if (diff <= (limit - n))
        return ((line2 - 1) + n);
    if (diff == ((limit - n) + 1))
        return (line1 - 1);
    if ((diff > ((limit - n) + 1)) && (diff < ((limit * 2) - n)))
        return (line2 + ((limit - n) + 1));
    else if (diff >= ((limit * 2) - n))
        return (line1 - (limit - n));
    return (0);
}

int *win_in_1_line(int *board_game, int limit)
{
    int line;

    for (line = 0; board_game[line] <= 0; line = line + 1);
    if (board_game[line] == 1)
        board_game[line] = 0;
    else if (board_game[line] <= (limit + 1))
        board_game[line] = 1;
    if (board_game[line] == (limit + 2))
        board_game[line] = limit + 1;
    if (board_game[line] > (limit + 2)) {
        if (board_game[line] > ((limit * 2) + 1))
            board_game[line] = board_game[line] - limit;
        else
            board_game[line] = limit + 2;
    }
    return (board_game);
}

int *win_in_2_lines(int *board_game, int limit)
{
    int line1;
    int line2;

    for (line1 = 0; board_game[line1] <= 0; line1 = line1 + 1);
    for (line2 = line1 + 1; board_game[line2] <= 0; line2 = line2 + 1);
    if (board_game[line1] == board_game[line2])
            board_game[line1] = board_game[line1] - 1;
    else if (board_game[line1] > board_game[line2])
        board_game[line1] = two_l(board_game[line1], board_game[line2], limit);
    else
        board_game[line1] = two_l(board_game[line1], board_game[line2], limit);
    return (board_game);
}

int *win_in_3_lines(int *board_game, int nb, int limit)
{
    int lines_1 = 0;
    int l_1 = 0;
    int lmax = 0;
    int lmax2 = 0;
    int diff;

    for (int i = 0; i < nb; i = i + 1) {
        lines_1 = ((board_game[i] == 1) ? (lines_1 + 1) : (lines_1));
        lmax = ((board_game[i] > board_game[lmax]) ? (i) : (lmax));
        l_1 = ((board_game[i] == 1) ? (board_game[i]) : (l_1));
    }
    for (int a = 0; a < nb; a = a + 1) {
        if (a != lmax)
            lmax2 = ((board_game[a] > board_game[lmax2]) ? (a) : (lmax2));
    }
    if (lines_1 >= 2)
        too_many_1_matches_line(board_game, nb, limit);
    else if (lines_1 == 1) {
        diff = board_game[lmax] - board_game[lmax2];
        if ((diff == 0) || (diff == limit))
            board_game[l_1] = 0;
        else if (diff == 1)
            board_game[lmax] = board_game[lmax] - 1;
        else if ((diff > 1) && (diff <= limit))
            board_game[lmax] = board_game[lmax] - (diff - 1);
        else
            board_game[lmax] = board_game[lmax] - limit;
    }
    else
        random_line(board_game, nb, limit);
    return (board_game);
}