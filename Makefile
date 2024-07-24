CC = gcc
CFLAGS = -g
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
