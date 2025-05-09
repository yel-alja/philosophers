NAME = philo_bonus

SRCS = main.c parsing.c #routine.c  monitor.c philo_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS =  -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
