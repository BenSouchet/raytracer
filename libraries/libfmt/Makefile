# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:48:09 by bsouchet          #+#    #+#              #
#    Updated: 2017/05/30 16:50:24 by bsouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang

NAME		= libfmt.a

FLAGS		= -Wall -Wextra -Werror -g

DIR_S		= sources

DIR_O		= temporary

HEADER		= include ../libft/include ../libvect/include

SOURCES		= fmt_int.c \
	fmt_int_sign_32.c \
	fmt_int_sign_64.c \
	fmt_int_unsign.c \
	fmt_print.c \
	fmt_vect.c \
	fmt_fmt.c \
	fmt_atoi.c

SUB_FOLDERS	=

SRCS		= $(addprefix $(DIR_S)/,$(SOURCES))

OBJS		= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

opti:
	@$(MAKE) all -j

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@[ -d $(DIR_O) ] || mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) $(addprefix -I, $(HEADER)) -o $@ -c $<

norme:
	norminette ../fsdl/$(HEADER)
	@echo
	norminette ../fsdl/$(DIR_S)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
