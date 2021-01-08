// #include "List.hpp"
// #include "Map.hpp"
// #include "Queue.hpp"
#include <iostream>
#include "Stack.hpp"
// #include "Vector.hpp"

#include <stack>


int main()
{
	std::stack<int> stack;
	Stack<int> mstack;

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
	Stack<int> ostack;
	bool a;
	mstack.push(1);
	ostack.push(1);
	a = ostack == mstack;
	std::cout << "	==  	: " << a << std::endl;
	a = ostack != mstack;
	std::cout << "	!=  	: " << a << std::endl;
	ostack.push(2);
	a = ostack >= mstack;
	std::cout << "	>=  	: " << a << std::endl;
	a = ostack <= mstack;
	std::cout << "	<=  	: " << a << std::endl;
	a = ostack > mstack;
	std::cout << "	>  	: " << a << std::endl;
	a = ostack < mstack;
	std::cout << "	<  	: " << a << std::endl;
	return 0;
}