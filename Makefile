NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	= ./AI_matchstick.c \
	  ./AI_strat.c \
	  ./get_next_line.c \
	  ./matchstick.c \
	  ./matchstick_player.c \
	  ./my_getnbr.c \
	  ./my_put_functions.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
