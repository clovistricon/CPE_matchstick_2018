/*
** EPITECH PROJECT, 2018
** my
** File description:
** for matchstick
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

#ifndef MY_H_
#define MY_H_
int my_pow(int p);
int my_getnbr(char const *str);
int *my_arrcpy(int nb, int *src);
char *my_strcpy(char const *src);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *sbuff);
int my_end(char const *sbuff);
char *get_current_line(int fd, char *line, int *sizemax);
char *get_next_line(int fd);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_error(int line, int matches, int limit);
int *set_board_game(int nb);
int nb_line(int *board_game, int nb);
int player_line(int nb);
int player_matches(int line, int limit, int *board_game);
void give_move(int player, int line, int matches);
int *player_turn(int nb, int limit, int *board_game);
void print_game_board(int nb, int const *board_game);
int nmatches_in_too_many_line(int lmax, int lines, int limit, int lines_1);
int *too_many_1_matches_line(int *board_game, int nb, int limit);
int *random_line(int *board_game, int nb, int limit);
int *win_in_1_line(int nb, int *board_game, int limit);
int two_l(int line1, int line2, int limit);
int *win_in_2_lines(int nb, int *board_game, int limit);
int *win_in_2lines_and_1matches(int *board_game, int nb, int lmax2, int limit);
int *win_in_3_lines(int *board_game, int nb, int limit);
void cmp_boards(int nb, int *memo, int *temp);
int *ai_turn(int nb, int limit, int *board_game);
int give_result(int turn);
int matchstick(int nb, int limit);
#endif