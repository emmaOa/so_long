MANDATORY= so_long.c check_map.c get_next_line.c ft_strlen.c\
			ft_strchr.c ft_substr.c ft_calloc.c\
			ft_bzero.c ft_memset.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstnew_bonus.c\
			ft_lstsize_bonus.c
MANDATORY:=$(addprefix src/,$(MANDATORY))
CC=cc
FLAGS=-Wall -Werror -Wextra -lmlx -framework OpenGl -framework AppKit
DEBUG=-fsanitize=address -g
NAME=so_long
O_MANDATORY=$(MANDATORY:%.c=%.o)

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) $(MANDATORY) -Iheaders -o $(NAME)

debug:
	gcc $(FLAGS) $(DEBUG) $(MANDATORY) -Iheaders -o $(NAME)

clean:
	rm -rf *.o

fclean:
	rm -rf *.o $(NAME)

re: fclean all