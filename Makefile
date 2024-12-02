NAME = libftprintf.a

SRC = ft_print_c.c \
			ft_print_d.c \
			ft_print_p.c \
			ft_print_s.c \
			ft_print_u.c \
			ft_print_xX.c \
			ft_printf.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c \

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re 

all : $(NAME)
	@true

$(NAME) : 
	gcc $(FLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

dev :
	make fclean;git add .; git commit -m 'auto update';git push