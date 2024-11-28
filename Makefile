NAME = printf.a

SRC = ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c \
			ft_vdputchar.c \
			ft_vdputnbr.c \
			ft_vdputstr.c \

OBJ_DIR = objects
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re 

all : $(NAME)
	@true

$(NAME) : $(OBJ_DIR)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

dev :
	make fclean;git add .; git commit -m 'auto update';git push;cd ../test;make;make f;cd ../libft;make fclean