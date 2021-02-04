// #include "List.hpp"
// #include "Stack.hpp"
// #include "Queue.hpp"
// #include "Vector.hpp"
#include "Map.hpp"

#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <string>


// dont forget coplien form for iterators and classes

// update the printing of list with the new print_temp

void	print_tree()
{

}

template<typename L1, typename L2>
void	print_tree(L1 &x, L2 &y)
{
	std::cout << "----------mine:----------\n"; 
	for(typename L1::iterator	it = x.begin() ; it != x.end(); ++it)
	{
		std::cout << "(" << (*it).first << ")" << (*it).second << " ";
	}
	std::cout << "\n----------syst:----------\n"; 
	for(typename L2::iterator it = y.begin() ; it != y.end(); ++it)
	{
		std::cout << "(" << (*it).first << ")" << (*it).second << " ";
	}
	std::cout << "\n**********end**********\n"; 
}

void	test_map()
{
	ft::Map<int, int> mmap;
	ft::Map<int, int> mmap2;
	std::pair<ft::Map<int, int>::iterator, bool> mp;

	std::map<int, int> map;
	std::map<int, int> map2;
	std::pair<std::map<int, int>::iterator, bool> p;

	mp = mmap.insert(std::pair<int, int>(5, 1));
	mp = mmap.insert(std::pair<int, int>(3, 1));
	mp = mmap.insert(std::pair<int, int>(8, 1));
	mp = mmap.insert(std::pair<int, int>(4, 1));
	mp = mmap.insert(std::pair<int, int>(2, 1));

	p = map.insert(std::pair<int, int>(5, 1));
	p = map.insert(std::pair<int, int>(3, 1));
	p = map.insert(std::pair<int, int>(8, 1));
	p = map.insert(std::pair<int, int>(4, 1));
	p = map.insert(std::pair<int, int>(2, 1));

	// ===================== Insert Test

	// std:: cout << mp.second << " " << p.second << "\n";
	// print_tree<Map<int, int>, std::map<int, int> >(mmap, map);

	// ===================== Insert Test

	// Map<int, int>::iterator it = mmap.begin();
	// it++;
	// mmap.insert(it, std::pair<int, int>(1, 1));

	// std::map<int, int>::iterator its = map.begin();
	// its++;
	// map.insert(its, std::pair<int, int>(1, 1));

	// print_tree<Map<int, int>, std::map<int, int> >(mmap, map);

	// ===================== Insert Test

	// mmap2.insert(mmap.begin(), mmap.end());

	// map2.insert(map.begin(), map.end());

	// print_tree<Map<int, int>, std::map<int, int> >(mmap2, map2);

	// ===================== Erase Test

	// Map<int, int>::iterator it = mmap.begin();
	// // it++;
	// mmap.erase(it);

	// std::map<int, int>::iterator its = map.begin();
	// // its++;
	// map.erase(its);

	// print_tree<Map<int, int>, std::map<int, int> >(mmap, map);

	// ===================== Erase Test

	// mmap.erase(2);

	// map.erase(2);
	
	// print_tree<Map<int, int>, std::map<int, int> >(mmap, map);

	// ===================== Erase Test

	// mmap.erase(mmap.begin(), mmap.end());

	// map.erase(map.begin(), map.end());

	// print_tree<Map<int, int>, std::map<int, int> >(mmap, map);

	// ===================== Clear Test

	// mmap.clear();

	// map.clear();

	// print_tree<Map<int, int>, std::map<int, int> >(mmap, map);

	// mmap.insert(std::pair<int, int>(7, 1));

	// map.insert(std::pair<int, int>(7, 1));

	// print_tree<Map<int, int>, std::map<int, int> >(mmap, map);

	// ===================== Swap Test

	// mmap2.insert(std::pair<int, int>(7, 1));
	// mmap2.insert(std::pair<int, int>(5, 1));

	// mmap2.swap(mmap);

	// map2.insert(std::pair<int, int>(7, 1));
	// map2.insert(std::pair<int, int>(5, 1));

	// map2.swap(map);

	// print_tree<ft::Map<int, int>, std::map<int, int> >(mmap, map);

	// print_tree<ft::Map<int, int>, std::map<int, int> >(mmap2, map2);

	// ===================== KeyComp Test

	ft::Map<int,int>::iterator it = mmap.rbegin();
	// it++;
	// it++;
	// it++;
	// it++;
	// it++;
	// it--;
	// it--;
	std::cout << it->first << "\n";

	// std::map<int,int>::key_compare comp = map.key_comp();
	// std::cout << "map contains:\n";
	// std::map<int,int>::iterator its = map.begin();
	// do {
	// 	std::cout << its->first << " => " << its->second << '\n';
	// } while ( comp((*its++).first, map.rbegin()->first) );

	// ft::Map<int,int>::key_compare mcomp = mmap.key_comp();
	// std::cout << "mmap contains:\n";
	// ft::Map<int,int>::iterator it = mmap.begin();
	// do {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// } while ( mcomp((*it++).first, mmap.rbegin()->first) );
}


int main()
{
	// test_stack();


	// test_queue();


	// test_list();

	//vector has error in : erase test 2,
	// test_vector();

	test_map();

	return 0;
}