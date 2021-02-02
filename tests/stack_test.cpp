#include "../Stack.hpp"
#include <stack>

void	test_stack()
{
	std::stack<int> stack;
	ft::Stack<int> mstack;

	std::cout << "TESTING STACK FUNCTIONS:" << std::endl << std::endl;
	std::cout << "stack empty	: " << stack.empty() << std::endl;
	std::cout << "my stack empty	: " << mstack.empty() << std::endl;
	std::cout << "stack size	: " << stack.size() << std::endl;
	std::cout << "my stack size	: " << mstack.size() << std::endl;
	stack.push(1);
	mstack.push(1);
	std::cout << "stack size	: " << stack.size() << std::endl;
	std::cout << "my stack size	: " << mstack.size() << std::endl;
	std::cout << "stack empty	: " << stack.empty() << std::endl;
	std::cout << "my stack empty	: " << mstack.empty() << std::endl;
	std::cout << "stack value	: " << stack.top() << std::endl;
	std::cout << "my stack value	: " << mstack.top() << std::endl;
	stack.top() += 5;
	mstack.top() += 5;
	std::cout << "stack value	: " << stack.top() << std::endl;
	std::cout << "my stack value	: " << mstack.top() << std::endl;
	stack.pop();
	mstack.pop();
	std::cout << "stack size	: " << stack.size() << std::endl;
	std::cout << "my stack size	: " << mstack.size() << std::endl;
	std::cout << "stack empty	: " << stack.empty() << std::endl;
	std::cout << "my stack empty	: " << mstack.empty() << std::endl;
	
	std::cout << "**	OPERATORS 	**" << std::endl;
	bool a;
	ft::Stack<int> ostack;
	std::stack<int> nstack;

	mstack.push(1);
	ostack.push(1);
	a = ostack == mstack;
	std::cout << "mine:	==  	: " << a << std::endl;

	stack.push(1);
	nstack.push(1);
	a = stack == nstack;
	std::cout << "orgn:	==  	: " << a << std::endl;

	a = ostack != mstack;
	std::cout << "mine:	!=  	: " << a << std::endl;

	a = stack != nstack;
	std::cout << "orgn:	!=  	: " << a << std::endl;

	ostack.push(2);
	a = ostack >= mstack;
	std::cout << "	>=  	: " << a << std::endl;
	
	a = ostack <= mstack;
	std::cout << "	<=  	: " << a << std::endl;
	a = ostack > mstack;
	std::cout << "	>  	: " << a << std::endl;
	a = ostack < mstack;
	std::cout << "	<  	: " << a << std::endl;
}