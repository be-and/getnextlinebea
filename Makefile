# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bandrade <bandrade@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/05/15 14:23:56 by bandrade      #+#    #+#                  #
#    Updated: 2026/05/15 15:03:42 by bandrade      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = gnl
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c \
		get_next_line_utils.c \
		main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re