SRC	:=	main.c check.c utils.c print.c simulation.c time.c constructors.c action.c watcher.c

OBJ	:=	$(SRC:.c=.o)

CC		:=	gcc

CFLAGS	+=	-Wall -Wextra -Werror -lpthread

RM		:=	rm -rf

NAME	:=	philo

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

run:		all
			./philo

rerun:		re
			./philo

.PHONY: 	all clean fclean re
