# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reldahli <reldahli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 14:08:08 by reldahli          #+#    #+#              #
#    Updated: 2024/07/24 15:31:21 by reldahli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/X11/lib -lmlx -lXext -lX11
LIBFT				= ./libft/libft.a

SRCS = main.c init.c events.c free_memory.c parse_data.c project.c read_file.c render.c
OBJS = $(SRCS:.c=.o)

NAME = fdf

# Build the executable
all: libft.a $(NAME)

libft.a:
	make -C ./libft
				
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)

# Clean object files
clean:
	rm -f $(OBJS)
	make -C libft clean

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild the project from scratch
re: fclean all