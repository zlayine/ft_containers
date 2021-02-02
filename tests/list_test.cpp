#include "../List.hpp"
#include <list>

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

template<typename T, typename L1, typename L2>
void	print_temp(L1 &x, L2 &y)
{
	std::cout << "----------mine:----------\n"; 
	for(typename L1::iterator	it = x.begin() ; it != x.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n----------syst:----------\n"; 
	for(typename L2::iterator it = y.begin() ; it != y.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n----------e----------\n"; 
}

void	test_list()
{
	ft::List<int>		mlist;
	ft::List<int>		mlist2;

	std::list<int>		list;
	std::list<int>		list2;

	/* =====================> Push test 1 */

	mlist.push_back(1);
	mlist.push_back(2);
	mlist.push_back(3);
	mlist.push_back(4);
	mlist.push_back(5);

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Pop test 1 */

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

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Clear test 1 */

	// mlist.clear();
	// list.clear();

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Assign test 1 */

	// mlist.assign(7, 100);
	// list.assign(7, 100);

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Assign test 2 */

	// mlist2.assign(mlist.begin(), mlist.end());

	// list2.assign(list.begin(), list.end());

	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	/* =====================> Insert test 1 */

	// ft::List<int>::iterator it = mlist.begin();
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

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Insert test 2 */

	// mlist2.push_back(9);
	// ft::List<int>::iterator it = mlist2.begin();
	// it++;
	// mlist2.insert(it, mlist.begin(), mlist.end());

	// list2.push_back(9);
	// std::list<int>::iterator its = list2.begin();
	// its++;
	// list2.insert(its, list.begin(), list.end());

	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	/* =====================> Insert test 3 */

	// ft::List<int>::iterator it = mlist.begin();
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

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Erase test 1 */

	// ft::List<int>::iterator it = mlist.begin();
	// it++;
	// it++;
	// it = mlist.erase(it, mlist.end());
	// std::cout << *it << std::endl;

	// std::list<int>::iterator its = list.begin();
	// its++;
	// its++;
	// its = list.erase(its, list.end());
	// std::cout << *its << std::endl;

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Erase test 2 */

	// ft::List<int>::iterator it = mlist.begin();
	// it = mlist.erase(mlist.begin(), mlist.end());
	// std::cout << *it << std::endl;

	// std::list<int>::iterator its = list.begin();
	// its = list.erase(list.begin(), list.end());
	// std::cout << *its << std::endl;

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Resize test 1 */

	// list.resize(2);
	// list.resize(5, 100);
	// list.resize(10);

	// mlist.resize(2);
	// mlist.resize(5, 100);
	// mlist.resize(10);

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Swap test 1 */

	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	// list.swap(list2);
	// mlist.swap(mlist2);
	// std::cout << "after swap: \n";

	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Splice test 1 */

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	// mlist2.splice(mlist2.begin(), mlist);
	// list2.splice(list2.begin(), list);
	// std::cout << "after splice: \n";

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	/* =====================> Splice test 2 */

	// mlist2.push_back(5);
	// mlist2.push_back(6);
	// mlist2.push_back(7);

	// list2.push_back(5);
	// list2.push_back(6);
	// list2.push_back(7);

	// ft::List<int>::iterator it = mlist2.begin();
	// std::list<int>::iterator its = list2.begin();

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	// it++;
	// its++;
	// mlist2.splice(it, mlist);
	// list2.splice(its, list);
	// std::cout << "after splice: \n";

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	/* =====================> Splice test 3 */

	// mlist2.push_back(5);
	// mlist2.push_back(6);
	// mlist2.push_back(7);

	// list2.push_back(5);
	// list2.push_back(6);
	// list2.push_back(7);

	// ft::List<int>::iterator it = mlist2.begin();
	// ft::List<int>::iterator it1 = mlist.begin();
	// std::list<int>::iterator its = list2.begin();
	// std::list<int>::iterator its1 = list.begin();

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	// it++;
	// its++;

	// it1++;
	// its1++;
	
	// mlist2.splice(it, mlist, it1);
	// list2.splice(its, list, its1);
	// std::cout << "after splice: \n";

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	/* =====================> Splice test 4 */

	// mlist2.push_back(5);
	// mlist2.push_back(6);
	// mlist2.push_back(7);

	// list2.push_back(5);
	// list2.push_back(6);
	// list2.push_back(7);

	// ft::List<int>::iterator it = mlist2.begin();
	// ft::List<int>::iterator it1 = mlist.begin();
	// std::list<int>::iterator its = list2.begin();
	// std::list<int>::iterator its1 = list.begin();

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	// it++;
	// its++;

	// it1++;
	// its1++;
	
	// mlist2.splice(it, mlist, it1, mlist.end());
	// list2.splice(its, list, its1, list.end());
	// std::cout << "after splice: \n";

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	/* =====================> Remove test 1 */
	
	// mlist.remove(2);
	// list.remove(2);
	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Remove test 2 */
	
	// mlist.remove_if(below_3);
	// list.remove_if(below_3);

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Unique test 1 */

	// mlist.push_back(3);
	// mlist.push_back(3);
	// list.push_back(3);
	// list.push_back(3);
	
	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	// mlist.unique();
	// list.unique();
	// std::cout << "after unique: \n";

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Unique test 2 */

	// mlist.push_back(3);
	// mlist.push_back(3);
	// list.push_back(3);
	// list.push_back(3);
	
	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	// mlist.unique(is_equal);
	// list.unique(is_equal);
	// std::cout << "after unique: \n";

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Sort test 1 */

	// mlist.push_back(3);
	// mlist.push_back(4);

	// list.push_back(3);
	// list.push_back(4);

	// mlist.sort();
	// list.sort();

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Sort test 2 */

	// mlist.push_back(3);
	// mlist.push_back(4);

	// list.push_back(3);
	// list.push_back(4);

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	// mlist.sort(compare_nothrees);
	// list.sort(compare_nothrees);

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	/* =====================> Merge test 1 */

	// mlist2.push_back(3);
	// mlist2.push_back(2);
	// mlist2.push_back(1);

	// list2.push_back(3);
	// list2.push_back(2);
	// list2.push_back(1);

	// list.merge(list2);

	// mlist.merge(mlist2);

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);


	/* =====================> Merge test 2 */

	// mlist2.push_back(1);
	// mlist2.push_back(2);
	// mlist2.push_back(3);

	// list2.push_back(1);
	// list2.push_back(2);
	// list2.push_back(3);

	// list.merge(list2);

	// mlist.merge(mlist2);

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	// print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

	/* =====================> Reverse test 1 */

	// mlist.reverse();

	// list.reverse();

	// print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

	// std::cout << "**	OPERATORS 	**" << std::endl;
	// bool a;

	// mlist.push_back(1);
	// mlist2.push_back(1);
	// a = mlist == mlist2;
	// std::cout << "mine:	==  	: " << a << std::endl;

	// list.push_back(1);
	// list2.push_back(1);
	// a = list == list2;
	// std::cout << "orgn:	==  	: " << a << std::endl;

	// a = mlist != mlist2;
	// std::cout << "mine:	!=  	: " << a << std::endl;

	// a = list != list2;
	// std::cout << "orgn:	!=  	: " << a << std::endl;

	// mlist.push_back(2);
	// a = mlist > mlist2;
	// std::cout << "mine:	>  	: " << a << std::endl;

	// list.push_back(2);
	// a = list > list2;
	// std::cout << "orgn:	>  	: " << a << std::endl;

	// a = mlist < mlist2;
	// std::cout << "mine:	<  	: " << a << std::endl;

	// a = list < list2;
	// std::cout << "orgn:	<  	: " << a << std::endl;

	// mlist2.push_back(2);
	// a = mlist <= mlist2;
	// std::cout << "mine:	<=  	: " << a << std::endl;

	// list2.push_back(2);
	// a = list <= list2;
	// std::cout << "orgn:	<=  	: " << a << std::endl;

	// a = mlist >= mlist2;
	// std::cout << "mine:	>=  	: " << a << std::endl;

	// a = list >= list2;
	// std::cout << "orgn:	>=  	: " << a << std::endl;

}
