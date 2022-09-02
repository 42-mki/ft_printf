# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/07 01:58:23 by seoh              #+#    #+#              #
#    Updated: 2020/09/25 02:27:31 by seoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
LIBFT			=	libft.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -O2
RM				=	rm -f
SRC				=	ft_printf.c \
					ft_printf_parser.c \
					ft_printf_diuxp.c \
					ft_printf_sc.c \
					ft_printf_utils.c \

SRC_PATH		=	./
INCLUDE_PATH	=	./includes/
LIBFT_PATH		=	./libft/
OBJS			=	${SRC:.c=.o}
.c.o:
				${CC} ${CFLAGS} -c $< -o $(<:.c=.o) -I${SRC_PATH}
$(NAME):
				gcc $(FLAGS) -c $(SRC) -I ./
				ar rc $(NAME) $(OBJS)
				
all:			${NAME}
clean:
				${RM} ${OBJS}
fclean:			clean
				${RM} ${NAME}
re:				fclean all