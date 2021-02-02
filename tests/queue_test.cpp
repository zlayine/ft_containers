#include "../Queue.hpp"
#include <queue>

void	test_queue()
{
	std::queue<int> queue;
	ft::Queue<int> mqueue;

	std::cout << "TESTING QUEUE FUNCTIONS:" << std::endl << std::endl;
	std::cout << "queue empty	: " << queue.empty() << std::endl;
	std::cout << "my queue empty	: " << mqueue.empty() << std::endl;
	std::cout << "queue size	: " << queue.size() << std::endl;
	std::cout << "my queue size	: " << mqueue.size() << std::endl;
	queue.push(1);
	mqueue.push(1);
	queue.push(10);
	mqueue.push(10);
	std::cout << "queue size	: " << queue.size() << std::endl;
	std::cout << "my queue size	: " << mqueue.size() << std::endl;
	std::cout << "queue empty	: " << queue.empty() << std::endl;
	std::cout << "my queue empty	: " << mqueue.empty() << std::endl;
	std::cout << "fqueue value	: " << queue.front() << std::endl;
	std::cout << "my fqueue value	: " << mqueue.front() << std::endl;
	queue.front() += 5;
	mqueue.front() += 5;
	std::cout << "fqueue value	: " << queue.front() << std::endl;
	std::cout << "my fqueue value	: " << mqueue.front() << std::endl;
	queue.back() += 5;
	mqueue.back() += 5;
	std::cout << "bqueue value	: " << queue.back() << std::endl;
	std::cout << "my bqueue value	: " << mqueue.back() << std::endl;
	queue.pop();
	mqueue.pop();
	std::cout << "queue size	: " << queue.size() << std::endl;
	std::cout << "my queue size	: " << mqueue.size() << std::endl;
	std::cout << "queue empty	: " << queue.empty() << std::endl;
	std::cout << "my queue empty	: " << mqueue.empty() << std::endl;

	std::cout << "**	OPERATORS 	**" << std::endl;
	bool a;

	ft::Queue<int> oqueue;
	std::queue<int> nqueue;

	mqueue.push(1);
	oqueue.push(1);
	a = oqueue == mqueue;
	std::cout << "mine:	==  	: " << a << std::endl;

	queue.push(1);
	nqueue.push(1);
	a = queue == nqueue;
	std::cout << "orgn:	==  	: " << a << std::endl;

	a = oqueue != mqueue;
	std::cout << "mine:	!=  	: " << a << std::endl;

	a = queue != nqueue;
	std::cout << "orgn:	!=  	: " << a << std::endl;

	oqueue.push(2);
	a = oqueue >= mqueue;
	std::cout << "	>=  	: " << a << std::endl;
	
	a = oqueue <= mqueue;
	std::cout << "	<=  	: " << a << std::endl;
	a = oqueue > mqueue;
	std::cout << "	>  	: " << a << std::endl;
	a = oqueue < mqueue;
	std::cout << "	<  	: " << a << std::endl;
}