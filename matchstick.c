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

int *read_player_move(int nb, int limit, int *board_game)
{
    char *buff = malloc(sizeof(char) * 11);
    size_t size = 10;
    int line;
    int nb_matches;

    my_putstr("Line: ");
    getline(&buff, &size, stdin);
    line = my_getnbr(buff);
    free(buff);
    if ((line <= 0) || (line > nb)) {
        my_putstr("Error: this line is out of range\n");
        return (NULL);
    }
    my_putstr("Matches: ");
    buff = malloc(sizeof(char) * 11);
    getline(&buff, &size, stdin);
    nb_matches = my_getnbr(buff);
    free(buff);
    if ((nb_matches <= 0) || (nb_matches > limit)) {
        my_putstr("Error: you have to remove at least one matches\n");
        return (NULL);
    }
    else if (nb_matches > board_game[line - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return (NULL);
    }
    board_game[line - 1] = board_game[line - 1] - nb_matches;
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

int matchstick(int nb, int limit)
{
    int *board_game = set_board_game(nb);
    int lines;
    int turn = 0;

    while ((lines = nb_line(board_game, nb)) >= 0) {
        board_game = player_turn(nb, limit, board_game);
        turn++;
        print_game_board(nb, board_game);
        if (nb_line(board_game, nb) == -1)
            break;
        board_game = ai_turn(nb, limit, board_game);
        turn++;
        print_game_board(nb, board_game);
    }
    if ((turn % 2) == 1) {
        write(1, "You lost, too bad...\n", 22);
        return (2);
    }
    write(1, "I lost... snif... but I'll get you next time!!\n", 50);
    return (1);
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