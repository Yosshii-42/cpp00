NAME	= megaphone
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
# FLAGS	+= -fsanitize=thread -g
SRCS	= megaphone.cpp
OBJS	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
