NAME = minishell

INCLUDE = -I include/

GCC = gcc -g

SRCS = env main

SRC = $(addsuffix .c, $(addprefix srcs/, $(SRCS))) \

%.o : %.c
	$(GCC) $(INCLUDE) -c $< -o $@

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):  $(OBJ)
	@make -C libft/
	@$(GCC) ./libft/libft.a -o $(NAME) $(OBJ)

fclean:
	@make fclean -C ./libft
	rm $(OBJ) $(NAME)

run:
	@./minishell

.PHONY: all fclean run