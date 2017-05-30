# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:48:09 by bsouchet          #+#    #+#              #
#    Updated: 2017/05/30 16:50:22 by bsouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang

NAME		= libcl.a

FLAGS		= -Wall -Wextra -Werror -g

DIR_S		= sources

DIR_O		= temporary

HEADER		= include ../libft/include ../libvect/include ../libgnl/include

SOURCES		= cl_init.c \
	cl_krl_build.c \
	cl_krl_exec.c \
	cl_krl_init.c \
	cl_read.c \
	cl_write.c \

SUB_FOLDERS	=

SRCS		= $(addprefix $(DIR_S)/,$(SOURCES))

OBJS		= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@[ -d $(DIR_O) ] || mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) $(addprefix -I, $(HEADER)) -o $@ -c $<

norme:
	norminette ../libcl/$(HEADER)
	@echo
	norminette ../libcl/$(DIR_S)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
