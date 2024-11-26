NAME = printf.a

SRC = ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c \
			ft_vdputchar.c \
			ft_vdputnbr.c \
			ft_vdputstr.c \

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re 

all : $(NAME)
	@true

$(NAME) :
	gcc -I $(FLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean : fclean
	rm -f $(NAME)

fclean : clean
	rm -rf $(OBJ)

re : fclean all

dev :
	make fclean;git add .; git commit -m 'auto update';git push;cd ../test;make;make f;cd ../libft;make fclean