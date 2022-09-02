# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 12:49:46 by mki               #+#    #+#              #
#    Updated: 2020/11/11 14:05:43 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf
.SUFFIXES = .c.o

FILE_LIBFT	=	ft_atoi\
				ft_isdigit\
				ft_istype\
				ft_iswidth\
				ft_memchr\
				ft_memcmp\
				ft_memmove\
				ft_memset\
				ft_numlen\
				ft_putchar\
				ft_putnbr_fd\
				ft_putstr_fd\
				ft_strchr\
				ft_strlen\
				ft_strncmp\
				ft_strnstr\
				ft_substr\

FILE		=	ft_parsing_1\
				ft_parsing_2\
				ft_printf\
				ft_stdout_1\
				ft_stdout_2\
				ft_stdout_3\
				ft_svar_init\

SRCS_DIR = ./srcs/
OBJS_DIR = ./srcs/
LIBFT_DIR = ./libft/

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILE)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE)))

SRCS_LIBFT = $(addprefix $(LIBFT_DIR), $(addsuffix .c, $(FILE_LIBFT)))
OBJS_LIBFT = $(addprefix $(LIBFT_DIR), $(addsuffix .o, $(FILE_LIBFT)))

LIB_DIR = ./includes/

.c.o: $(SRCS) $(SRCS_BONUS) $(SRCS_LIBFT)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(LIB_DIR)

all: $(NAME)

bonus: $(SRCS_BONUS)
	$(AR) $(NAME) $^

$(NAME): $(OBJS) $(OBJS_BONUS) $(OBJS_LIBFT)
	$(AR) $@ $^

clean: 
	$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_LIBFT)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
