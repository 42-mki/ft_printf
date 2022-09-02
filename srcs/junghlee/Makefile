# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 11:15:31 by junghlee          #+#    #+#              #
#    Updated: 2020/11/18 14:07:41 by junghlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST_EXEC = ft_printf_test.out

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES =	main \
		parse \
		puttype_c \
		puttype_di \
		puttype_n \
		puttype_p \
		puttype_percent \
		puttype_s \
		puttype_uox \
		utils_char_string \
		utils_type \
		utils_number \
		utils_parse

FILES_T =	main \
			parse \
			puttype_c \
			puttype_di \
			puttype_n \
			puttype_p \
			puttype_percent \
			puttype_s \
			puttype_uox \
			utils_char_string \
			utils_type \
			utils_number \
			utils_parse \
			test_bonus

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_T = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_T)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_T = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_T)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: all

all: $(NAME)

run-test: test fclean

test:
	$(CC) $(CFLAGS) $(SRCS_T) -o $(TEST_EXEC)
	./$(TEST_EXEC) | cat -e

clean:
	$(RM) $(OBJS) $(OBJS_T) $(TEST_EXEC)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re

norm:
	norminette $(SRCS)
