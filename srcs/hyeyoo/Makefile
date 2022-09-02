NAME = libftprintf.a
SRCS = $(addprefix srcs/, $(shell ls ./srcs | grep '\.c'))
OBJS = $(SRCS:.c=.o)

LIBFT = libft.a
LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/$(LIBFT)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I./includes
RM = rm -f


$(NAME) : $(LIBFT_LIB) $(OBJS)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIBFT_LIB) :
	$(MAKE) -C $(LIBFT_PATH)

%.o : %.c
	$(CC) $(CFLAGS) -g -I./includes -c $< -o $@

all : $(NAME)

clean :
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
