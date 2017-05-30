NAME = rt_client
SRC = $(filter %.c, $(shell ls))
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a libvect/libvect.a libfmt/libfmt.a libgnl/libgnl.a libcl/libcl.a

INCS +=
CFLAGS += -g -Wall -Wextra -Werror $(INCS)
LDLIBS +=  -framework OpenCL -lcl -lgnl -lfmt -lfmt -lvect -lft
LOADLIBES += -Llibft -Llibvect -Llibgnl -Llibcl -Llibfmt
LDFLAGS += -g

all: $(LIB) $(NAME)

$(NAME): $(OBJ)

%.a:
	make -C $(shell echo $*.a | sed 's/\// /')

clean:
	@rm $(OBJ) 2> /dev/null || true

fclean: clean
	@rm $(NAME) 2> /dev/null || true

re: fclean all

.PHONY: all clean fclean re
