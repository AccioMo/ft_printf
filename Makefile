CC = cc
NAME = libftprintf.a
HEADER = ft_printf.h
FLAGS = -Werror -Wextra -Wall
SRC = ft_printf.c ft_printf_multiverse.c ft_duphex.c ft_dupstr.c ft_dupchr.c ft_putchar.c ft_dupnbr.c ft_dupunbr.c ft_strchr.c ft_strlcpy.c ft_putnstr.c ft_putflag.c ft_substr.c ft_saveflags.c ft_useflags.c ft_strlen.c ft_isdigit.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re