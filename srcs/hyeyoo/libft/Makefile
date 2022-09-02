NAME = libft.a
SRCS = ${shell ls . | grep '\.c'}
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

%.o : %.c
	${CC} ${CFLAGS} -g -I . -c $< -o $@

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
