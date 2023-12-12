#Compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#Source files
SRCS = ft_printf.c ft_pchar.c ft_pstr.c ft_pint.c ft_punsign.c \
       ft_ppoint.c ft_plower.c ft_pupper.c ft_ppercent.c

#Object files
OBJS = $(SRCS:.c=.o)

#Library name
NAME = libftprintf.a

#Targets
all: $(NAME)

$(NAME): $(OBJS)
        ar rcs $(NAME) $(OBJS)

%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        rm -f $(OBJS)

fclean: clean
        rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
