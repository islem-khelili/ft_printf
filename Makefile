SRCS = ft_printf.c ft_printf_hex.c \
       ft_printf_ptr.c ft_printf_u.c \
       ft_printf_nbr.c ft_printf_char.c \
       ft_itoa.c\

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
