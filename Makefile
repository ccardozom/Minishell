NAME = minishell

INCLUDE = -I include/

GCC = gcc -g

SRCS = env main lista

SRC = $(addsuffix .c, $(addprefix srcs/, $(SRCS))) \

%.o : %.c
	@$(GCC) $(INCLUDE) -c $< -o $@

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;34m===> Compilando...\033[1;33m"
	@make -C libft/
	@$(GCC) ./libft/libft.a -o $(NAME) $(OBJ)

fclean:
	@echo  "\033[1;34m===> Borrando...\033[0;31m "
	@make fclean -C ./libft
	rm $(OBJ) $(NAME)

run:
	@echo "\033[1;34m===> Ejecutando...\033[00m"
	@./minishell

re:
	@make fclean
	@make
	@make run

.PHONY: all fclean run