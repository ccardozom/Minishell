NAME = minishell

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIBFT_DIR = ./libft/

SRC = main.c create_var_array.c env.c free_var.c search_var.c \
	work_to_list.c find_nodo.c ft_insert_nodo_fin.c ft_lst_new_lst.c \
	lst_iter_lst.c ft_lst_size_lst.c ft_insert_nodo_ini.c\
	command_line.c \
		imprimir_lst.c

OBJ = $(SRC:.c=.o)
INC = -I. -I$(LIBFT_DIR) -ltermcap
LIBFT = -L $(LIBFT_DIR) -lft

CC = gcc
WFLAGS = -Wall -Wextra -Werror
MAKE = make
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(WFLAGS) $(INC) $(LIBFT) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(WFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re