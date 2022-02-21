SRC	:=	main.c

OBJ	:=	$(SRC:.c=.o)

CC		:=	cc

CFLAGS	+=	-Wall -Wextra -Werror -pthread

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
