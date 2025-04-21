NAME = philo

SRCS = main.c philo_utils.c parsing.c routine.c  monitor.c  #remove remove.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

# bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

# $(BONUS_NAME): $(BONUS_OBJS)
# 	$(CC) $(BONUS_OBJS) $(CFLAGS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re #bonus
