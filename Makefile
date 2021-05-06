NAME = minishell

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIBFT_DIR = ./libft/

SRC = main.c create_var_array.c env.c free_var.c search_var.c \
	work_to_list.c set_env.c ft_insert_node_fin.c ft_lst_new_lst.c \
	add_node_before_last.c find_history.c find_node.c ft_delete_node.c \
	lst_iter_lst.c ft_lst_size_lst.c ft_insert_node_ini.c \
	command_line.c next_line_key.c ft_putchar.c create_node.c \
	cap_key_up.c cap_key_right.c cap_key_printable.c cap_key_left.c \
	cap_key_down.c ft_strjoin_free.c cap_delete_char.c \
	imprimir_lst.c

OBJ = $(SRC:.c=.o)
INC = -I. -I$(LIBFT_DIR) -ltermcap
LIBFT = -L $(LIBFT_DIR) -lft

CC = gcc
WFLAGS = -Wall -Wextra -g3 -fsanitize=address
MAKE = make
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(OBJ) $(WFLAGS) $(INC) -o $(NAME)  $(LIBFT)

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
