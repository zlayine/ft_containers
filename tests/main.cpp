#include <iostream>
#include <string>

void	test_vector();
void	test_list();
void	test_queue();
void	test_stack();
void	test_map();


int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::string var = argv[1];
		if (var == "list")
			test_list();
		else if (var == "vector")
			test_vector();
		else if (var == "stack")
			test_stack();
		else if (var == "queue")
			test_queue();
		else if (var == "map")
			test_map();
	}
}