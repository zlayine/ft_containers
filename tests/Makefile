NAME = containers

MAIN = main.cpp

SRCS = list_test.cpp \
	queue_test.cpp \
	stack_test.cpp \
	map_test.cpp \
	vector_test.cpp

CONTAINERS = ../List.hpp \
	../Map.hpp \
	../Stack.hpp \
	../Queue.hpp \
	../Tree.hpp \
	../Tools.hpp \
	../Vector.hpp \
	../ReverseIterator.hpp \
	../Node.hpp  


all: $(NAME)

$(NAME): $(MAIN) $(SRCS) $(CONTAINERS)
	@g++ -Wall -Wextra -Werror $(MAIN) $(SRCS) -o $(NAME)
	@echo "CONTAINERS ARE READY"

clean:
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all

