// #include "List.hpp"
// #include "Map.hpp"
// #include "Queue.hpp"
// #include "Stack.hpp"
// #include "Queue.hpp"
#include "List.hpp"
// #include "Vector.hpp"

#include <stack>
#include <queue>
#include <list>
#include <string>

// void	test_stack()
// {
// 	std::stack<int> stack;
// 	Stack<int> mstack;

// 	std::cout << "TESTING STACK FUNCTIONS:" << std::endl << std::endl;
// 	std::cout << "stack empty	: " << stack.empty() << std::endl;
// 	std::cout << "my stack empty	: " << mstack.empty() << std::endl;
// 	std::cout << "stack size	: " << stack.size() << std::endl;
// 	std::cout << "my stack size	: " << mstack.size() << std::endl;
// 	stack.push(1);
// 	mstack.push(1);
// 	std::cout << "stack size	: " << stack.size() << std::endl;
// 	std::cout << "my stack size	: " << mstack.size() << std::endl;
// 	std::cout << "stack empty	: " << stack.empty() << std::endl;
// 	std::cout << "my stack empty	: " << mstack.empty() << std::endl;
// 	std::cout << "stack value	: " << stack.top() << std::endl;
// 	std::cout << "my stack value	: " << mstack.top() << std::endl;
// 	stack.top() += 5;
// 	mstack.top() += 5;
// 	std::cout << "stack value	: " << stack.top() << std::endl;
// 	std::cout << "my stack value	: " << mstack.top() << std::endl;
// 	stack.pop();
// 	mstack.pop();
// 	std::cout << "stack size	: " << stack.size() << std::endl;
// 	std::cout << "my stack size	: " << mstack.size() << std::endl;
// 	std::cout << "stack empty	: " << stack.empty() << std::endl;
// 	std::cout << "my stack empty	: " << mstack.empty() << std::endl;

	
// 	std::cout << "**	OPERATORS 	**" << std::endl;
// 	Stack<int> ostack;
// 	bool a;
// 	mstack.push(1);
// 	ostack.push(1);
// 	a = ostack == mstack;
// 	std::cout << "	==  	: " << a << std::endl;
// 	a = ostack != mstack;
// 	std::cout << "	!=  	: " << a << std::endl;
// 	ostack.push(2);
// 	a = ostack >= mstack;
// 	std::cout << "	>=  	: " << a << std::endl;
// 	a = ostack <= mstack;
// 	std::cout << "	<=  	: " << a << std::endl;
// 	a = ostack > mstack;
// 	std::cout << "	>  	: " << a << std::endl;
// 	a = ostack < mstack;
// 	std::cout << "	<  	: " << a << std::endl;
// }

// void	test_queue()
// {
// 	std::queue<int> queue;
// 	Queue<int> mqueue;

// 	std::cout << "TESTING QUEUE FUNCTIONS:" << std::endl << std::endl;
// 	std::cout << "queue empty	: " << queue.empty() << std::endl;
// 	std::cout << "my queue empty	: " << mqueue.empty() << std::endl;
// 	std::cout << "queue size	: " << queue.size() << std::endl;
// 	std::cout << "my queue size	: " << mqueue.size() << std::endl;
// 	queue.push(1);
// 	mqueue.push(1);
// 	queue.push(10);
// 	mqueue.push(10);
// 	std::cout << "queue size	: " << queue.size() << std::endl;
// 	std::cout << "my queue size	: " << mqueue.size() << std::endl;
// 	std::cout << "queue empty	: " << queue.empty() << std::endl;
// 	std::cout << "my queue empty	: " << mqueue.empty() << std::endl;
// 	std::cout << "fqueue value	: " << queue.front() << std::endl;
// 	std::cout << "my fqueue value	: " << mqueue.front() << std::endl;
// 	queue.front() += 5;
// 	mqueue.front() += 5;
// 	std::cout << "fqueue value	: " << queue.front() << std::endl;
// 	std::cout << "my fqueue value	: " << mqueue.front() << std::endl;
// 	queue.back() += 5;
// 	mqueue.back() += 5;
// 	std::cout << "bqueue value	: " << queue.back() << std::endl;
// 	std::cout << "my bqueue value	: " << mqueue.back() << std::endl;
// 	queue.pop();
// 	mqueue.pop();
// 	std::cout << "queue size	: " << queue.size() << std::endl;
// 	std::cout << "my queue size	: " << mqueue.size() << std::endl;
// 	std::cout << "queue empty	: " << queue.empty() << std::endl;
// 	std::cout << "my queue empty	: " << mqueue.empty() << std::endl;

	
// 	std::cout << "**	OPERATORS 	**" << std::endl;
// 	Queue<int> oqueue;
// 	bool a;
// 	mqueue.push(1);
// 	oqueue.push(1);
// 	a = oqueue == mqueue;
// 	std::cout << "	==  	: " << a << std::endl;
// 	a = oqueue != mqueue;
// 	std::cout << "	!=  	: " << a << std::endl;
// 	oqueue.push(2);
// 	a = oqueue >= mqueue;
// 	std::cout << "	>=  	: " << a << std::endl;
// 	a = oqueue <= mqueue;
// 	std::cout << "	<=  	: " << a << std::endl;
// 	a = oqueue > mqueue;
// 	std::cout << "	>  	: " << a << std::endl;
// 	a = oqueue < mqueue;
// 	std::cout << "	<  	: " << a << std::endl;
// }


void	test_list()
{
	List<std::string>		mlist;
	List<std::string>::iterator	it = mlist.begin();

	mlist.push_back("ab");
	mlist.push_back("ac");
	mlist.push_back("ad");

	for(++it; it != mlist.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

int main()
{
	// test_stack();
	// test_queue();
	test_list();
	return 0;
}