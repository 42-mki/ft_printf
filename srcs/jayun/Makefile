CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c option_check.c malloc_size.c add_result.c left_right_write_dui.c type_dui.c \
	   left_right_write_perandc.c type_perandc.c left_right_write_s.c type_s.c \
	   left_right_write_p.c type_p.c left_right_write_xo.c type_xo.c \
	   bankers_rounding.c place_check.c type_n.c get_size_f.c right_write_f.c left_write_f.c \
	   ft_dtoa.c rounding_check_f.c type_f.c get_size_e.c left_right_write_e.c ft_dtoa_e.c \
	   rounding_check_e.c type_e.c get_size_gf.c right_write_gf.c left_write_gf.c \
	   left_right_write_ge.c rounding_check_gf.c rounding_check_ge.c type_g.c \
	   type_hh.c type_h.c ft_lltoa_u.c get_basenum_ll.c type_l_ll.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

LIBFT = libft.a

.c.o:	${LIBFT}
		${CC} ${CFLAGS} -c -I ./libft $< -o $(<:.c=.o)

all:	${NAME}

${LIBFT}:
			$(MAKE) -C ./libft bonus

${NAME}:	${OBJS} ${LIBFT}
			cp ./libft/libft.a ./${NAME}
			ar rc ${NAME} ${OBJS}
			
clean:
		rm -f ${OBJS}
		${MAKE} -C ./libft clean

fclean:	clean
		rm -f ${NAME}
		${MAKE} -C ./libft fclean

re:		fclean ${NAME}

bonus:	all

.PHONY:	all clean fclean re
