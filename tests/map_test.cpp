#include "../Map.hpp"
#include <map>

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

	// ===================== ValueComp Test

	// std::cout << "map contains:\n";
	// std::map<int,int>::iterator its = map.begin();
	// do {
	// 	std::cout << its->first << " => " << its->second << '\n';
	// } while ( map.value_comp()(*its++, *map.rbegin()) );

	// std::cout << "mmap contains:\n";
	// ft::Map<int,int>::iterator it = mmap.begin();
	// do {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// } while ( mmap.value_comp()(*it++, *mmap.rbegin()) );

	// ===================== Find Test

	// std::cout << mmap.find(7)->second << "\n";
	// std::cout << map.find(7)->second << "\n";

	// // ===================== Lower Bound Test
	
	// std::map<int,int>::iterator its = map.begin();
	// its = map.lower_bound(8);
	// std::cout << its->first << " " << its->second << "\n";

	// ft::Map<int,int>::iterator it = mmap.begin();
	// it = mmap.lower_bound(8);
	// std::cout << it->first << " " << it->second << "\n";

	// ===================== Upper Bound Test
	
	// std::map<int,int>::iterator its = map.begin();
	// its = map.upper_bound(7);
	// std::cout << its->first << " " << its->second << "\n";

	// ft::Map<int,int>::iterator it = mmap.begin();
	// it = mmap.upper_bound(7);
	// std::cout << it->first << " " << it->second << "\n";

	// ===================== Equal range Test
	
	// std::pair<std::map<int, int>::iterator,std::map<int, int>::iterator> ret;
	// ret = map.equal_range(8);

	// std::cout << "lower bound points to: ";
	// std::cout << ret.first->first << " => " << ret.first->second << '\n';

	// std::cout << "upper bound points to: ";
	// std::cout << ret.second->first << " => " << ret.second->second << '\n';

	// std::cout << "------------mine-----------\n";
	// std::pair<ft::Map<int, int>::iterator,ft::Map<int, int>::iterator> rets;
	// rets = mmap.equal_range(8);

	// std::cout << "lower bound points to: ";
	// std::cout << rets.first->first << " => " << rets.first->second << '\n';

	// std::cout << "upper bound points to: ";
	// std::cout << rets.second->first << " => " << rets.second->second << '\n';

}