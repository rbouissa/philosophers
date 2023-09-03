CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar -rc
RM		= rm -f
NAME	= philo
SRC		= philo.c \
		helpers.c\
		time.c\
		print.c\
		

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)  

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME) 

re:	fclean all

b: all clean
