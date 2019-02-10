/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** game against ai
*/
#include "my.h"

int *set_board_game(int nb)
{
    int *board_game = malloc(sizeof(int) * (nb + 1));

    for (int i = 1; i <= nb; i = i + 1)
        board_game[i - 1] = (i * 2) - 1;
    return (board_game);
}

void print_game_board(int nb, int const *board_game)
{
    for (int a = 0; a <= (nb * 2); a = a + 1)
        my_putchar('*');
    my_putchar('\n');
    for (int y = 0; y < nb; y = y + 1) {
        my_putchar('*');
        for (int x1 = 0; x1 < ((nb - y) - 1); x1 = x1 + 1)
            my_putchar(' ');
        for (int n = 0; n < board_game[y]; n = n + 1)
            my_putchar('|');
        for (int x2 = (nb - y) + board_game[y]; x2 < (nb * 2); x2 = x2 + 1)
            my_putchar(' ');
        my_putchar('*');
        my_putchar('\n');
    }
    for (int b = 0; b <= (nb * 2); b = b + 1)
        my_putchar('*');
    my_putchar('\n');
}

int give_result(int turn)
{
    if ((turn % 2) == 1) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    my_putstr("I lost... snif... but I'll get you next time!!\n");
    return (1);
}

int matchstick(int nb, int limit)
{
    int *board_game = set_board_game(nb);
    int lines;
    int turn = 0;
    int result;

    print_game_board(nb, board_game);
    while ((lines = nb_line(board_game, nb)) >= 0) {
        board_game = player_turn(nb, limit, board_game);
        if (board_game == NULL)
            return (0);
        turn = turn + 1;
        print_game_board(nb, board_game);
        if (nb_line(board_game, nb) == -1)
            break;
        board_game = ai_turn(nb, limit, board_game);
        turn = turn + 1;
        print_game_board(nb, board_game);
    }
    result = give_result(turn);
    return (result);
}

int main(int ac, char **av)
{
    int nb;
    int limit;
    int result;

    if (ac == 3) {
        nb = my_getnbr(av[1]);
        limit = my_getnbr(av[2]);
        if (((nb <= 1) || (nb > 99)) || (limit <= 0)) {
            write(2, "Error: Bad arguments\n", 22);
            return (84);
        }
        result = matchstick(nb, limit);
    }
    else
        return (84);
    return (result);
}