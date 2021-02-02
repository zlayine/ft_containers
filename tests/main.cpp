#include <iostream>
#include <string>

void	test_vector();
void	test_list();
void	test_queue();
void	test_stack();


int main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (argv[1] == "list")
			test_list();
		else if (argv[1] == "vector")
			test_vector();
		else if (argv[1] == "stack")
			test_stack();
		else if (argv[1] == "queue")
			test_queue();
	}
}