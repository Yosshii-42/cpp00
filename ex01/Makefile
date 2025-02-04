NAME	= phonebook
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
# FLAGS	+= -fsanitize=thread -g
SRCS	= main.cpp \
		  Contact.cpp \
		  PhoneBook.cpp 
OBJS	= $(SRCS:.cpp=.o)

%.o: %.cpp
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
