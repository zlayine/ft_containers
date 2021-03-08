#include "../Map.hpp"
#include <map>

template <typename L1, typename L2>
void print_tree(L1 &x, L2 &y)
{
	std::cout << "----------mine:----------\n";
	for (typename L1::iterator it = x.begin(); it != x.end(); ++it)
	{
		std::cout << "(" << (*it).first << ")" << (*it).second << " ";
	}
	std::cout << "\n----------syst:----------\n";
	for (typename L2::iterator it = y.begin(); it != y.end(); ++it)
	{
		std::cout << "(" << (*it).first << ")" << (*it).second << " ";
	}
	std::cout << "\n**********end**********\n";
}

template <typename C, typename key, typename val>
C reinsert()
{
	C container;

	container.insert(std::pair<key, val>(5, 1));
	container.insert(std::pair<key, val>(3, 1));
	container.insert(std::pair<key, val>(8, 1));
	container.insert(std::pair<key, val>(4, 1));
	container.insert(std::pair<key, val>(2, 1));
	return container;
}

void test_map()
{

	std::cout << "===================== Insert Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();

		print_tree<ft::Map<int, int>, std::map<int, int> >(mmap, map);
	}
	std::cout << "===================== Insert Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		ft::Map<int, int>::iterator it = mmap.begin();
		it++;
		mmap.insert(it, std::pair<int, int>(1, 1));

		std::map<int, int>::iterator its = map.begin();
		its++;
		map.insert(its, std::pair<int, int>(1, 1));

		print_tree<ft::Map<int, int>, std::map<int, int> >(mmap, map);
	}
	std::cout << "===================== Insert Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		mmap2.insert(mmap.begin(), mmap.end());

		map2.insert(map.begin(), map.end());

		print_tree<ft::Map<int, int>, std::map<int, int> >(mmap2, map2);
	}
	std::cout << "===================== Erase Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		ft::Map<int, int>::iterator it = mmap.begin();
		it++;
		mmap.erase(it);

		std::map<int, int>::iterator its = map.begin();
		its++;
		map.erase(its);

		print_tree<ft::Map<int, int>, std::map<int, int> >(mmap, map);
	}
	std::cout << "===================== Erase Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		mmap.erase(2);

		map.erase(2);

		print_tree<ft::Map<int, int>, std::map<int, int> >(mmap, map);
	}
	std::cout << "===================== Erase Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		mmap.erase(mmap.begin(), mmap.end());

		map.erase(map.begin(), map.end());

		print_tree<ft::Map<int, int>, std::map<int, int> >(mmap, map);
	}
	std::cout << "===================== Clear Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();

		mmap.clear();

		map.clear();

		print_tree<ft::Map<int, int>, std::map<int, int> >(mmap, map);

		mmap.insert(std::pair<int, int>(7, 1));

		map.insert(std::pair<int, int>(7, 1));

		print_tree<ft::Map<int, int>, std::map<int, int> >(mmap, map);
	}
	std::cout << "===================== Swap Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		mmap2.insert(std::pair<int, int>(7, 1));
		mmap2.insert(std::pair<int, int>(5, 1));

		mmap2.swap(mmap);

		map2.insert(std::pair<int, int>(7, 1));
		map2.insert(std::pair<int, int>(5, 1));

		map2.swap(map);

		print_tree<ft::Map<int, int>, std::map<int, int> >(mmap, map);

		print_tree<ft::Map<int, int>, std::map<int, int> >(mmap2, map2);
	}
	std::cout << "===================== KeyComp Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		std::map<int, int>::key_compare comp = map.key_comp();
		std::cout << "map contains:\n";
		std::map<int, int>::iterator its = map.begin();
		do
		{
			std::cout << its->first << " => " << its->second << '\n';
		} while (comp((*its++).first, map.rbegin()->first));

		ft::Map<int, int>::key_compare mcomp = mmap.key_comp();
		std::cout << "mmap contains:\n";
		ft::Map<int, int>::iterator it = mmap.begin();
		do
		{
			std::cout << it->first << " => " << it->second << '\n';
		} while (mcomp((*it++).first, mmap.rbegin()->first));
	}
	std::cout << "===================== ValueComp Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		std::cout << "map contains:\n";
		std::map<int, int>::iterator its = map.begin();
		do
		{
			std::cout << its->first << " => " << its->second << '\n';
		} while (map.value_comp()(*its++, *map.rbegin()));

		std::cout << "mmap contains:\n";
		ft::Map<int, int>::iterator it = mmap.begin();
		do
		{
			std::cout << it->first << " => " << it->second << '\n';
		} while (mmap.value_comp()(*it++, *mmap.rbegin()));
	}
	std::cout << "===================== Find Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		std::cout << mmap.find(7)->second << "\n";
		std::cout << map.find(7)->second << "\n";
	}
	std::cout << "===================== Lower Bound Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		std::map<int, int>::iterator its = map.begin();
		its = map.lower_bound(8);
		std::cout << its->first << " " << its->second << "\n";

		ft::Map<int, int>::iterator it = mmap.begin();
		it = mmap.lower_bound(8);
		std::cout << it->first << " " << it->second << "\n";
	}
	std::cout << "===================== Upper Bound Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		std::map<int, int>::iterator its = map.begin();
		its = map.upper_bound(8);
		std::cout << its->first << " " << its->second << "\n";

		ft::Map<int, int>::iterator it = mmap.begin();
		it = mmap.upper_bound(8);
		std::cout << it->first << " " << it->second << "\n";
	}
	std::cout << "===================== Equal range Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();
		std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> ret;
		ret = map.equal_range(8);

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';

		std::cout << "------------mine-----------\n";
		std::pair<ft::Map<int, int>::iterator, ft::Map<int, int>::iterator> rets;
		rets = mmap.equal_range(8);

		std::cout << "lower bound points to: ";
		std::cout << rets.first->first << " => " << rets.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << rets.second->first << " => " << rets.second->second << '\n';
	}
	std::cout << "===================== Operator [] Test" << std::endl;
	{
		ft::Map<int, int> mmap;
		ft::Map<int, int> mmap2;
		std::map<int, int> map;
		std::map<int, int> map2;

		mmap = reinsert<ft::Map<int, int>, int, int>();
		map = reinsert<std::map<int, int>, int, int>();

		std::cout << map[2] << "\n";
		std::cout << mmap[2] << "\n";
	}
}