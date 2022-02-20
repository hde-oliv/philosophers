SRC		:=	main.c

OBJ		:=	$(SRC:.c=.o)

CC		:=	cc

CFLAGS	+=	-Wall -Wextra -Werror -pthreads

RM		:=	rm -rf

NAME	:=	philo

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
