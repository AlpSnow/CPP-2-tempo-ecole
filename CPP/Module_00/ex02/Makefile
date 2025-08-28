NAME = account


SRC_FILES = tests.cpp \
Account.cpp


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


OBJFILES = $(SRC_FILES:.cpp=.o)



all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(NAME)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)



.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: all clean fclean re run