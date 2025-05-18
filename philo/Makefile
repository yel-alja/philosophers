NAME = philo

SRCS = main.c philo_utils.c parsing.c routine.c  monitor.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS =  -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS) philo.h
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
