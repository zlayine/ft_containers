NAME = containers

MAIN = main.cpp

SRCS = list_test.cpp \
	queue_test.cpp \
	stack_test.cpp \
	vector_test.cpp

all: $(NAME)

$(NAME): $(MEGAPHONE)
	@g++  $(MAIN) $(SRCS) -o $(NAME)
	@echo "CONTAINERS ARE READY! NO FLAGS"

clean:
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all

