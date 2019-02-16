/*
** EPITECH PROJECT, 2018
** AI_strat
** File description:
** strats for AI_matchstick
*/
#include "my.h"

int two_l(int line1, int line2, int limit)
{
    int n = 0;
    int diff = line1 - line2;

    if (limit == 1)
        return (line1 - 1);
    if (line2 == 1)
        n = 1;
    if (diff <= (limit - n))
        return (line2 - n);
    if (diff == ((limit - n) + 1))
        return (line1 - 1);
    if ((diff > ((limit - n) + 1)) && (diff < (((limit * 2) - n) + 1)))
        return (line2 + ((limit - n) + 1));
    else if (diff >= (((limit * 2) - n) + 1)) {
        if (diff == (limit * 2))
            return (line1 - (limit - 1));
        else
            return (line1 - (limit - n));
    }
    return (0);
}

int *win_in_1_line(int nb, int *board_game, int limit)
{
    int line;
    int *temp = my_arrcpy(nb, board_game);

    for (line = 0; temp[line] <= 0; line = line + 1);
    if (temp[line] == 1)
        temp[line] = 0;
    else if (temp[line] <= (limit + 1))
        temp[line] = 1;
    if (temp[line] == (limit + 2))
        temp[line] = limit + 1;
    if (temp[line] > (limit + 2)) {
        if (temp[line] > ((limit * 2) + 1))
            temp[line] = temp[line] - limit;
        else
            temp[line] = limit + 2;
    }
    return (temp);
}

int *win_in_2_lines(int nb, int *board_game, int limit)
{
    int line1;
    int line2;
    int *temp = my_arrcpy(nb, board_game);

    for (line1 = 0; temp[line1] <= 0; line1 = line1 + 1);
    for (line2 = line1 + 1; temp[line2] <= 0; line2 = line2 + 1);
    if (temp[line1] == temp[line2])
            temp[line1] = temp[line1] - 1;
    else if (temp[line1] > temp[line2])
        temp[line1] = two_l(temp[line1], temp[line2], limit);
    else
        temp[line2] = two_l(temp[line2], temp[line1], limit);
    return (temp);
}

int *win_in_2lines_and_1matches(int *board_game, int nb, int lmax2, int limit)
{
    int lmax = 0;
    int l_1 = 0;
    int diff;
    int *temp = my_arrcpy(nb, board_game);

    for (int i = 0; i < nb; i = i + 1) {
        lmax = ((temp[i] > temp[lmax]) ? (i) : (lmax));
        l_1 = ((temp[i] == 1) ? (i) : (l_1));
    }
    diff = temp[lmax] - temp[lmax2];
    if ((diff <= 1) || (diff == (limit + 2)))
        temp[l_1] = 0;
    else {
        if (diff <= (limit + 1))
            temp[lmax] = temp[lmax2] + 1;
        else if ((diff > (limit + 1)) && (diff <= ((limit * 2) + 1)))
            temp[lmax] = temp[lmax2] + (limit + 2);
        else
            temp[lmax] = temp[lmax] - limit;
    }
    return (temp);
}

int *win_in_3_lines(int *board_game, int nb, int limit)
{
    int lines_1 = 0;
    int lmax = 0;
    int lmax2 = 0;
    int *temp = my_arrcpy(nb, board_game);

    for (int i = 0; i < nb; i = i + 1) {
        lines_1 = ((temp[i] == 1) ? (lines_1 + 1) : (lines_1));
        lmax = ((temp[i] > temp[lmax]) ? (i) : (lmax));
    }
    for (int a = 0; a < nb; a = a + 1) {
        if (a != lmax)
            lmax2 = ((temp[a] > temp[lmax2]) ? (a) : (lmax2));
    }
    if (lines_1 >= 2)
        temp = too_many_1_matches_line(temp, nb, limit);
    else if (lines_1 == 1)
        temp = win_in_2lines_and_1matches(temp, nb, lmax2, limit);
    else
        temp = random_line(temp, nb, limit);
    return (temp);
}