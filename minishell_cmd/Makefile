CMD = CMD


SRC_DIR = ./src/
INC_DIR = ./include/

CMD_SRC = echo.c env.c ft_split.c ft_strchr.c ft_strdup.c \
			ft_strlen.c ft_strndup.c ft_strcmp.c main.c \
			key_compare.c export.c

CMD_SRCS = $(addprefix $(SRC_DIR), $(CMD_SRC))

CMD_OBJS = $(CMD_SRCS:.c=.o)

LIBS	 = -L./doubly_linked_list -ldlinkedlist

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all : $(CMD)

$(CMD) : $(CMD_OBJS)
		make -C doubly_linked_list
		$(CC) -o $(CMD) $(CMD_OBJS) $(LIBS)

%.o: %.c
		gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean :
		make -C doubly_linked_list clean
		rm -f $(CMD_OBJS)

fclean : clean
		make -C doubly_linked_list fclean
		rm -f $(CMD)

re: fclean all

.PHONY : all clean fclean re
