#include "../List.hpp"
#include <list>

bool below_3(const int &value)
{
	return (value < 4);
}

bool is_equal(const int &first, const int &second)
{
	return (first == second);
}

bool compare_nothrees(const int first, const int second)
{
	if (first == 3 || second == 3)
		return false;
	if (first < second)
		return true;
	return false;
}

template <typename T, typename L1, typename L2>
void print_temp(L1 &x, L2 &y)
{
	std::cout << "----------mine:----------\n";
	for (typename L1::iterator it = x.begin(); it != x.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n----------syst:----------\n";
	for (typename L2::iterator it = y.begin(); it != y.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n----------e----------\n";
}

template <typename C>
C reinsert()
{
	C list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	return list;
}

void test_list()
{

	std::cout << "=====================> Max size test 1" << std::endl;

	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		std::cout << mlist.max_size() << std::endl;
		std::cout << list.max_size() << std::endl;
	}

	std::cout << "=====================> Size test 1" << std::endl;

	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		std::cout << mlist.size() << std::endl;
		std::cout << list.size() << std::endl;
	}

	std::cout << "=====================> Copy 1 " << std::endl;

	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		ft::List<int> mlist3(mlist);
		std::list<int> list3(list);

		std::cout << mlist3.size() << std::endl;
		std::cout << list3.size() << std::endl;

		print_temp<int, ft::List<int>, std::list<int> >(mlist3, list3);
	}

	std::cout << "=====================> Push test 1" << std::endl;

	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}

	std::cout << "=====================> Reverse Iteration print" << std::endl;

	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		std::cout << "----------mine:----------\n";
		for (ft::List<int>::reverse_iterator it = mlist.rbegin(); it != mlist.rend(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << "\n----------syst:----------\n";
		for (std::list<int>::reverse_iterator it = list.rbegin(); it != list.rend(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << "\n----------e----------\n";
	}

	std::cout << "=====================> Front " << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		std::cout << mlist.front() << std::endl;
		std::cout << list.front() << std::endl;
	}
	std::cout << "=====================> Back " << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		std::cout << mlist.back() << std::endl;
		std::cout << list.back() << std::endl;
	}
	std::cout << "=====================> Pop test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		mlist.pop_front();
		list.pop_front();

		mlist.pop_back();
		list.pop_back();

		mlist.pop_back();
		list.pop_back();

		mlist.pop_back();
		list.pop_back();

		mlist.pop_front();
		list.pop_front();

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Clear test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		mlist.clear();
		list.clear();

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}

	std::cout << "=====================> Assign test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		mlist.assign(7, 100);
		list.assign(7, 100);

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Assign test 2" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		
		mlist2.assign(mlist.begin(), mlist.end());

		list2.assign(list.begin(), list.end());

		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
	}
	std::cout << "=====================> Insert test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		ft::List<int>::iterator it = mlist.begin();
		it++;
		it++;
		it++;
		it++;
		it = mlist.insert(it, 10);
		mlist.insert(it, 2, 100);
		std::cout << *it << std::endl;

		std::list<int>::iterator its = list.begin();
		its++;
		its++;
		its++;
		its++;
		its = list.insert(its, 10);
		list.insert(its, 2, 100);
		std::cout << *its << std::endl;

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}

	std::cout << "=====================> Insert test 2" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		ft::List<int>::iterator it = mlist2.begin();
		mlist2.insert(it, mlist.begin(), mlist.end());

		std::list<int>::iterator its = list2.begin();
		list2.insert(its, list.begin(), list.end());

		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
	}

	std::cout << "=====================> Erase test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		ft::List<int>::iterator it = mlist.begin();
		it++;
		it++;
		it++;
		it = mlist.erase(it);
		it = mlist.erase(it);
		std::cout << *it << std::endl;

		std::list<int>::iterator its = list.begin();
		its++;
		its++;
		its++;
		its = list.erase(its);
		its = list.erase(its);
		std::cout << *its << std::endl;

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Erase test 2" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		ft::List<int>::iterator it = mlist.begin();
		it++;
		it++;
		it = mlist.erase(it, mlist.end());
		std::cout << *it << std::endl;

		std::list<int>::iterator its = list.begin();
		its++;
		its++;
		its = list.erase(its, list.end());
		std::cout << *its << std::endl;

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Erase test 3" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		ft::List<int>::iterator it = mlist.begin();
		it = mlist.erase(mlist.begin(), mlist.end());
		std::cout << *it << std::endl;

		std::list<int>::iterator its = list.begin();
		its = list.erase(list.begin(), list.end());
		std::cout << *its << std::endl;

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Resize test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		list.resize(2);
		list.resize(5, 100);
		list.resize(10);

		mlist.resize(2);
		mlist.resize(5, 100);
		mlist.resize(10);

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Swap test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

		list.swap(list2);
		mlist.swap(mlist2);
		std::cout << "after swap: \n";

		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Splice test 1" << std::endl;

	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();
		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

		mlist2.splice(mlist2.begin(), mlist);
		list2.splice(list2.begin(), list);
		std::cout << "after splice: \n";

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
	}

	std::cout << "=====================> Splice test 2" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist2.push_back(5);
		mlist2.push_back(6);
		mlist2.push_back(7);

		list2.push_back(5);
		list2.push_back(6);
		list2.push_back(7);

		ft::List<int>::iterator it = mlist2.begin();
		std::list<int>::iterator its = list2.begin();

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

		it++;
		its++;
		mlist2.splice(it, mlist);
		list2.splice(its, list);
		std::cout << "after splice: \n";

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
	}
	std::cout << "=====================> Splice test 3" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;
		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist2.push_back(5);
		mlist2.push_back(6);
		mlist2.push_back(7);

		list2.push_back(5);
		list2.push_back(6);
		list2.push_back(7);

		ft::List<int>::iterator it = mlist2.begin();
		ft::List<int>::iterator it1 = mlist.begin();
		std::list<int>::iterator its = list2.begin();
		std::list<int>::iterator its1 = list.begin();

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

		it++;
		its++;

		it1++;
		its1++;

		mlist2.splice(it, mlist, it1);
		list2.splice(its, list, its1);
		std::cout << "after splice: \n";

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
	}
	std::cout << "=====================> Splice test 4" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist2.push_back(5);
		mlist2.push_back(6);
		mlist2.push_back(7);

		list2.push_back(5);
		list2.push_back(6);
		list2.push_back(7);

		ft::List<int>::iterator it = mlist2.begin();
		ft::List<int>::iterator it1 = mlist.begin();
		std::list<int>::iterator its = list2.begin();
		std::list<int>::iterator its1 = list.begin();

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);

		it++;
		its++;

		it1++;
		its1++;

		mlist2.splice(it, mlist, it1, mlist.end());
		list2.splice(its, list, its1, list.end());
		std::cout << "after splice: \n";

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
	}
	std::cout << "=====================> Remove test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist.remove(2);
		list.remove(2);
		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Remove test 2" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist.remove_if(below_3);
		list.remove_if(below_3);

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Unique test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist.push_back(3);
		mlist.push_back(3);
		list.push_back(3);
		list.push_back(3);

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

		mlist.unique();
		list.unique();
		std::cout << "after unique: \n";

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Unique test 2" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist.push_back(3);
		mlist.push_back(3);
		list.push_back(3);
		list.push_back(3);

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

		mlist.unique(is_equal);
		list.unique(is_equal);
		std::cout << "after unique: \n";

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Sort test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist.push_back(2);
		mlist.push_back(3);
		mlist.push_back(4);

		list.push_back(2);
		list.push_back(3);
		list.push_back(4);

		mlist.sort();
		list.sort();

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Sort test 2" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist.push_back(2);
		mlist.push_back(4);

		list.push_back(2);
		list.push_back(4);

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

		mlist.sort(compare_nothrees);
		list.sort(compare_nothrees);

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Merge test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist2.push_back(3);
		mlist2.push_back(2);
		mlist2.push_back(1);

		list2.push_back(3);
		list2.push_back(2);
		list2.push_back(1);

		list.merge(list2);

		mlist.merge(mlist2);

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
	}
	std::cout << "=====================> Merge test 2" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist2.push_back(1);
		mlist2.push_back(2);
		mlist2.push_back(3);

		list2.push_back(1);
		list2.push_back(2);
		list2.push_back(3);

		list.merge(list2);

		mlist.merge(mlist2);

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);

		print_temp<int, ft::List<int>, std::list<int> >(mlist2, list2);
	}
	std::cout << "=====================> Reverse test 1" << std::endl;
	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

		mlist.reverse();

		list.reverse();

		print_temp<int, ft::List<int>, std::list<int> >(mlist, list);
	}
	std::cout << "=====================> Operations " << std ::endl;

	{
		ft::List<int> mlist;
		ft::List<int> mlist2;

		std::list<int> list;
		std::list<int> list2;

		mlist = reinsert<ft::List<int> >();
		list = reinsert<std::list<int> >();

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
}
