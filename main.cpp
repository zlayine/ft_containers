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

void	print_here()
{
	std::cout << "here\n";
}

template<typename T>
void	print_lists(List<T> &x, std::list<T> &y)
{
	std::cout << "--------------------\n"; 
	for(List<int>::iterator	it = x.begin() ; it != x.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "--------------------\n"; 
	for(std::list<int>::iterator it = y.begin() ; it != y.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}


void	test_list()
{
	List<int>			mlist;
	std::list<int>		list;

	mlist.push_front(1);
	mlist.push_front(2);
	mlist.push_front(3);
	mlist.push_front(4);
	mlist.push_front(5);

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.push_front(5);

	// mlist.pop_front();
	// list.pop_front();

	// mlist.pop_back();
	// list.pop_back();

	// mlist.pop_back();
	// list.pop_back();

	// mlist.pop_back();
	// list.pop_back();

	// mlist.pop_front();
	// list.pop_front();

	// mlist.pop_front();
	// list.pop_front();

	// mlist.clear();
	// list.clear();
	print_lists(mlist, list);


	// list.clear();
	// std::cout << *list.begin() << std::endl;

	// list.resize(2);
	// list.resize(5, 100);
	// list.resize(10);

	// mlist.resize(2);
	// mlist.resize(5, 100);
	// mlist.resize(10);

	// List<int>::iterator ita;
	// std::list<int>::iterator its;

	// ita = mlist.begin();
	// its = list.begin();

	// ++ita;
	// ++its;

	// mlist.insert(ita, 10);
	// // std::cout << *ita << std::endl;
	// list.insert(its, 10);
	// // std::cout << *its << std::endl;

	// mlist.insert(ita, 2, 12);
	// // std::cout << *ita << std::endl;
	// list.insert(its, 2, 12);
	// // std::cout << *its << std::endl;

	// List<int>			nlist;
	// std::list<int>		list1;

	// nlist.push_back(22);
	// nlist.push_back(23);

	// list1.push_back(22);
	// list1.push_back(23);

	// mlist.insert(ita, nlist.begin(), nlist.end());
	// list.insert(its, list1.begin(), list1.end());
	
	// ita = mlist.erase(ita);
	// std::cout << *ita << std::endl;
	// its = list.erase(its);
	// std::cout << *its << std::endl;

	
	// std::list<int>::iterator it1 = list.begin();
	
	
	// std::list<int>::iterator it2 = list.end();

	// it1++;
	// it1++;
	// it2--;
	// // std::cout << *it1 << std::endl;
	// its = list.erase(it1, it2);
	// // std::cout << *its << std::endl;


	// List<int>::iterator it3 = mlist.begin();
	// List<int>::iterator it4 = mlist.end();

	// it3++;
	// mlist.splice(it3, mlist2);

	// list.clear();
	// std::cout << *mlist2.begin() << std::endl;
	// mlist2.splice(mlist2.begin() , mlist, it3);

	// it3++;
	// it4--;
	// // std::cout << *it3 << std::endl;
	// ita = mlist.erase(it3, it4);
	// std::cout << *ita << std::endl;

	// std::cout << "--------------------\n"; 
	// for(std::list<int>::iterator	it = list.begin() ; it != list.end(); ++it)
	// {
	// 	std::cout << *it << std::endl;
	// }

}



int main()
{
	// test_stack();
	// test_queue();
	test_list();
	return 0;
}