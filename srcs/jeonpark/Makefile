NAME		= libftprintf.a

LIBFT		= libft/libft.a

SRCS		= ft_printf.c \
			  t_spec/t_spec.c \
			  t_spec/read_spec.c \
			  t_utf8/wctoutf8.c \
			  t_utf8/cpyutf8tos.c \
			  t_utf8/wstoutf8s.c \
			  utils/utils.c \
			  convert/convert_dioux.c \
			  convert/apply_option_dioux.c \
			  convert/convert_c.c \
			  convert/convert_s.c \
			  convert/convert_p.c \
			  convert/convert_n.c \
			  convert/convert_percent.c

OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I libft -I t_spec -I t_utf8 -I convert -I utils
COMPILE		= $(CC) $(CFLAGS) $(INCLUDE)

RM			= rm -f



.PHONY:		all debug setdebug
all:		$(NAME)
debug:		setdebug $(NAME)
setdebug:
			$(eval OPTION = -g)

%.o:		%.c
			$(COMPILE) $(OPTION) -c $< -o $@

$(NAME):	$(LIBFT) $(OBJS)
			cp $(LIBFT) $(NAME)
			ar rc $(NAME) $(OBJS)

.PHONY:		bonus
bonus:		$(NAME)

$(LIBFT):
			make -C libft bonus

.PHONY:		clean fclean re bonus
clean:
			make -C libft fclean
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean all
