// #include "List.hpp"
// #include "Map.hpp"
#include "List.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
// #include "Vector.hpp"

#include <stack>
#include <queue>
#include <list>
#include <string>


void	print_here()
{
	std::cout << "here\n";
}

bool below_3 (const int& value)
{
	return (value < 4);
}

bool is_equal (const int& first, const int &second)
{
	return (first == second);
}

bool compare_nothrees (const int first, const int second)
{
	if (first == 3 || second == 3)
		return false;
	if (first > second)
		return false;
 	return true;
}

void	test_stack()
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
	bool a;
	Stack<int> ostack;
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
	
	// a = ostack <= mstack;
	// std::cout << "	<=  	: " << a << std::endl;
	// a = ostack > mstack;
	// std::cout << "	>  	: " << a << std::endl;
	// a = ostack < mstack;
	// std::cout << "	<  	: " << a << std::endl;
}

void	test_queue()
{
	std::queue<int> queue;
	Queue<int> mqueue;

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

	// operations has a problem	
	// std::cout << "**	OPERATORS 	**" << std::endl;
	// Queue<int> oqueue;
	// bool a;
	// mqueue.push(1);
	// oqueue.push(1);
	// a = oqueue == mqueue;
	// std::cout << "	==  	: " << a << std::endl;
	// a = oqueue != mqueue;
	// std::cout << "	!=  	: " << a << std::endl;
	// oqueue.push(2);
	// a = oqueue >= mqueue;
	// std::cout << "	>=  	: " << a << std::endl;
	// a = oqueue <= mqueue;
	// std::cout << "	<=  	: " << a << std::endl;
	// a = oqueue > mqueue;
	// std::cout << "	>  	: " << a << std::endl;
	// a = oqueue < mqueue;
	// std::cout << "	<  	: " << a << std::endl;
}


template<typename T>
void	print_lists(List<T> &x, std::list<T> &y)
{
	std::cout << "----------mine:----------\n"; 
	for(List<int>::iterator	it = x.begin() ; it != x.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n----------syst:----------\n"; 
	for(std::list<int>::iterator it = y.begin() ; it != y.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n----------e----------\n"; 
}


void	test_list()
{
	List<int>			mlist;
	List<int>			mlist2;

	std::list<int>		list;
	std::list<int>		list2;

	// =====================> Push test 1

	// mlist.push_back(1);
	// mlist.push_back(2);
	// mlist.push_back(3);
	// mlist.push_back(4);
	// mlist.push_back(5);

	// list.push_back(1);
	// list.push_back(2);
	// list.push_back(3);
	// list.push_back(4);
	// list.push_back(5);

	// print_lists(mlist, list);

	// =====================> Pop test 1

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

	// print_lists(mlist, list);

	// =====================> Clear test 1

	// mlist.clear();
	// list.clear();

	// print_lists(mlist, list);

	// =====================> Assign test 1

	// mlist.assign(7, 100);
	// list.assign(7, 100);

	// print_lists(mlist, list);

	// =====================> Assign test 2

	// mlist2.assign(mlist.begin(), mlist.end());

	// print_lists(mlist2, list);

	// =====================> Insert test 1

	// problem with iterating over itself still occurs
	// List<int>::iterator it = mlist.begin();
	// // it++;
	// // it++;
	// // it++;
	// // it++;
	// // it++;
	// it = mlist.insert(it, 10);
	// mlist.insert(it, 2, 100);
	// std::cout << *it << std::endl;

	// std::list<int>::iterator its = list.begin();
	// // its++;
	// // its++;
	// // its++;
	// // its++;
	// // its++;
	// its = list.insert(its, 10);
	// list.insert(its, 2, 100);
	// std::cout << *its << std::endl;

	// print_lists(mlist, list);

	// =====================> Insert test 2

	// mlist2.push_back(9);
	// List<int>::iterator it = mlist2.begin();
	// it++;
	// mlist2.insert(it, mlist.begin(), mlist.end());

	// list2.push_back(9);
	// std::list<int>::iterator its = list2.begin();
	// its++;
	// list2.insert(its, list.begin(), list.end());

	// print_lists(mlist2, list2);

	// =====================> Insert test 3

	// List<int>::iterator it = mlist.begin();
	// it++;
	// it++;
	// it++;
	// // it++;
	// it = mlist.erase(it);
	// it = mlist.erase(it);
	// std::cout << *it << std::endl;

	// std::list<int>::iterator its = list.begin();
	// its++;
	// its++;
	// its++;
	// // its++;
	// its = list.erase(its);
	// its = list.erase(its);
	// std::cout << *its << std::endl;

	// print_lists(mlist, list);

	// =====================> Erase test 1

	// List<int>::iterator it = mlist.begin();
	// it++;
	// it++;
	// it = mlist.erase(it, mlist.end());
	// std::cout << *it << std::endl;

	// std::list<int>::iterator its = list.begin();
	// its++;
	// its++;
	// its = list.erase(its, list.end());
	// std::cout << *its << std::endl;

	// print_lists(mlist, list);

	// =====================> Erase test 2

	// List<int>::iterator it = mlist.begin();
	// it = mlist.erase(mlist.begin(), mlist.end());
	// std::cout << *it << std::endl;

	// std::list<int>::iterator its = list.begin();
	// its = list.erase(list.begin(), list.end());
	// std::cout << *its << std::endl;

	// print_lists(mlist, list);

	// =====================> Resize test 1

	// list.resize(2);
	// list.resize(5, 100);
	// list.resize(10);

	// mlist.resize(2);
	// mlist.resize(5, 100);
	// mlist.resize(10);

	// print_lists(mlist, list);

	// =====================> Swap test 1

	// print_lists(mlist2, list2);
	// print_lists(mlist, list);

	// list.swap(list2);
	// mlist.swap(mlist2);
	// std::cout << "after swap: \n";

	// print_lists(mlist2, list2);
	// print_lists(mlist, list);

	// =====================> Splice test 1

	// print_lists(mlist, list);
	// print_lists(mlist2, list2);

	// mlist2.splice(mlist2.begin(), mlist);
	// list2.splice(list2.begin(), list);
	// std::cout << "after splice: \n";

	// print_lists(mlist, list);
	// print_lists(mlist2, list2);

	// =====================> Splice test 2

	// mlist2.push_back(5);
	// mlist2.push_back(6);
	// mlist2.push_back(7);

	// list2.push_back(5);
	// list2.push_back(6);
	// list2.push_back(7);

	// List<int>::iterator it = mlist2.begin();
	// std::list<int>::iterator its = list2.begin();

	// print_lists(mlist, list);
	// print_lists(mlist2, list2);

	// it++;
	// its++;
	// mlist2.splice(it, mlist);
	// list2.splice(its, list);
	// std::cout << "after splice: \n";

	// print_lists(mlist, list);
	// print_lists(mlist2, list2);

	// =====================> Splice test 3

	// mlist2.push_back(5);
	// mlist2.push_back(6);
	// mlist2.push_back(7);

	// list2.push_back(5);
	// list2.push_back(6);
	// list2.push_back(7);

	// List<int>::iterator it = mlist2.begin();
	// List<int>::iterator it1 = mlist.begin();
	// std::list<int>::iterator its = list2.begin();
	// std::list<int>::iterator its1 = list.begin();

	// print_lists(mlist, list);
	// print_lists(mlist2, list2);

	// it++;
	// its++;

	// it1++;
	// its1++;
	
	// mlist2.splice(it, mlist, it1);
	// list2.splice(its, list, its1);
	// std::cout << "after splice: \n";

	// print_lists(mlist, list);
	// print_lists(mlist2, list2);

	// =====================> Splice test 4

	// mlist2.push_back(5);
	// mlist2.push_back(6);
	// mlist2.push_back(7);

	// list2.push_back(5);
	// list2.push_back(6);
	// list2.push_back(7);

	// List<int>::iterator it = mlist2.begin();
	// List<int>::iterator it1 = mlist.begin();
	// std::list<int>::iterator its = list2.begin();
	// std::list<int>::iterator its1 = list.begin();

	// print_lists(mlist, list);
	// print_lists(mlist2, list2);

	// it++;
	// its++;

	// it1++;
	// its1++;
	
	// mlist2.splice(it, mlist, it1, mlist.end());
	// list2.splice(its, list, its1, list.end());
	// std::cout << "after splice: \n";

	// print_lists(mlist, list);
	// print_lists(mlist2, list2);

	// =====================> Remove test 1
	
	// mlist.remove(2);
	// list.remove(2);
	// print_lists(mlist, list);

	// =====================> Remove test 2
	
	// mlist.remove_if(below_3);
	// list.remove_if(below_3);

	// print_lists(mlist, list);

	// =====================> Unique test 1

	// mlist.push_back(3);
	// mlist.push_back(3);
	// list.push_back(3);
	// list.push_back(3);
	
	// print_lists(mlist, list);

	// mlist.unique();
	// list.unique();
	// std::cout << "after unique: \n";

	// print_lists(mlist, list);

	// =====================> Unique test 2

	// mlist.push_back(3);
	// mlist.push_back(3);
	// list.push_back(3);
	// list.push_back(3);
	
	// print_lists(mlist, list);

	// mlist.unique(is_equal);
	// list.unique(is_equal);
	// std::cout << "after unique: \n";

	// print_lists(mlist, list);

	// =====================> Sort test 1

	// mlist.push_back(3);
	// mlist.push_back(4);

	// list.push_back(3);
	// list.push_back(4);

	// mlist.sort();
	// list.sort();

	// print_lists(mlist, list);

	// =====================> Sort test 2

	// mlist.push_back(3);
	// mlist.push_back(4);

	// list.push_back(3);
	// list.push_back(4);

	// print_lists(mlist, list);

	// mlist.sort(compare_nothrees);
	// list.sort(compare_nothrees);

	// print_lists(mlist, list);

	// =====================> Merge test 1

	// mlist2.push_back(3);
	// mlist2.push_back(2);
	// mlist2.push_back(1);

	// list2.push_back(3);
	// list2.push_back(2);
	// list2.push_back(1);

	// list.merge(list2);

	// mlist.merge(mlist2);

	// print_lists(mlist, list);

	// print_lists(mlist2, list2);


	// =====================> Merge test 2

	// mlist2.push_back(1);
	// mlist2.push_back(2);
	// mlist2.push_back(3);

	// list2.push_back(1);
	// list2.push_back(2);
	// list2.push_back(3);

	// list.merge(list2);

	// mlist.merge(mlist2);

	// print_lists(mlist, list);

	// print_lists(mlist2, list2);

	// =====================> Reverse test 1

	// mlist.reverse();

	// list.reverse();

	// print_lists(mlist, list);

	std::cout << "**	OPERATORS 	**" << std::endl;
	bool a;

	mlist.push_back(1);
	mlist2.push_back(1);
	a = mlist == mlist2;
	std::cout << "mine:	==  	: " << a << std::endl;

	list.push_back(1);
	list2.push_back(1);
	a = list == list2;
	std::cout << "orgn:	==  	: " << a << std::endl;

	a = mlist != mlist2;
	std::cout << "mine:	!=  	: " << a << std::endl;

	a = list != list2;
	std::cout << "orgn:	!=  	: " << a << std::endl;

	mlist.push_back(2);
	a = mlist > mlist2;
	std::cout << "mine:	>  	: " << a << std::endl;

	list.push_back(2);
	a = list > list2;
	std::cout << "orgn:	>  	: " << a << std::endl;

	a = mlist < mlist2;
	std::cout << "mine:	<  	: " << a << std::endl;

	a = list < list2;
	std::cout << "orgn:	<  	: " << a << std::endl;

	mlist2.push_back(2);
	a = mlist <= mlist2;
	std::cout << "mine:	<=  	: " << a << std::endl;

	list2.push_back(2);
	a = list <= list2;
	std::cout << "orgn:	<=  	: " << a << std::endl;

	a = mlist >= mlist2;
	std::cout << "mine:	>=  	: " << a << std::endl;

	a = list >= list2;
	std::cout << "orgn:	>=  	: " << a << std::endl;

}

int main()
{
	// test_stack();
	// test_queue();
	test_list();
	return 0;
}