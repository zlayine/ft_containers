#ifndef MAP_HPP
# define MAP_HPP

#include "Tools.hpp"
#include "Tree.hpp"

template<typename key, typename T, typename Compare = ::less<key> >
class MapCompare : public std::binary_function<std::pair<key, T>, std::pair<key, T>, bool>
{
public:
	MapCompare();
	// MapCompare();
	virtual ~MapCompare();

	typedef	typename std::pair<key, T>	value_type;

	bool operator()(const value_type& x, const value_type& y) const
    {
		return (cmp(x.first, y.first));
	}

	bool operator()(const value_type& x, const key& y) const
    {
		return (cmp(x.first, y));
	}

	bool operator()(const key& x, const value_type& y) const
    {
		return (cmp(x, y.first));
	}

private:
	Compare				cmp;

};

template<typename key, typename T, typename Compare = MapCompare<key, T> >
class Map
{

public:
    typedef T                   						value_type;
    typedef key                 						key_type;
    typedef T                   						mapped_type;
	typedef Compare										key_compare;
	typedef Compare										value_compare;
	typedef T&											reference;
	typedef const T&									const_reference;
	typedef T*											pointer;
	typedef const T*									const_pointer;
	typedef	std::pair<key, T>							pair_type;
	typedef	Tree<pair_type, Compare>					tree_type;
	typedef	typename tree_type::node_type				node_type;
	typedef TreeIterator<pair_type, node_type>			iterator;
	typedef const TreeIterator<pair_type, node_type>	const_iterator;
	typedef TreeIterator<pair_type, node_type>			reverse_iterator;
	typedef const TreeIterator<pair_type, node_type>	const_reverse_iterator;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;
private:
	tree_type	_tree;
	size_type	_size;

public:
    Map();
	~Map();

	//tested 0
	iterator			begin()
	{
		return iterator(_head);
	}

	//tested 0
	const_iterator		begin() const
	{
		return iterator(_head);
	}

	//tested 0
	iterator			end()
	{
		return iterator(_tail);
	}

	//tested 0
	const_iterator		end() const
	{
		return iterator(_tail);
	}

	//tested 0
	reverse_iterator	rbegin()
	{
		return iterator(_tail);
	}

	//tested 0
	reverse_iterator	rend()
	{
		return iterator(_head);
	}
	
	//tested 0
	bool				empty() const
	{
		return _size == 0;
	}

	//tested 0
	size_type			size() const
	{
		return _size;
	}

	// not done
	//tested 0
	size_type			max_size() const
	{
		return _size;
	}

	//tested 1
	void				clear()
	{
		for (iterator it = begin(); it != end(); ++it)
			pop_front();
	}

	//tested 1
	T&	operator[](int i) const
	{
		
	}

	//tested 0
	std::pair<iterator, bool>	insert(const value_type& val)
	{
		
	}

	//tested 0
	iterator 			insert(iterator position, const value_type& val)
	{
		
	}

	//tested 0
	void				insert(iterator first, iterator last)
	{
		for((void)first; first != last; ++first)
			insert(*first);
	}

	void				erase(iterator position)
	{

	}

	size_type			erase(const key_type& k)
	{

	}

	void				erase(iterator first, iterator last)
	{

	}

	void				swap(Map<key, T>& x)
	{

	}

	key_compare			key_comp() const
	{

	}

	value_compare		value_comp() const
	{

	}

	iterator			find(const key_type& k)
	{

	}

	const_iterator		find(const key_type& k) const
	{

	}

	size_type			count(const key_type& k) const
	{

	}

	iterator			lower_bound(const key_type& k)
	{

	}

	const_iterator		lower_bound(const key_type& k) const
	{

	}

	iterator			upper_bound(const key_type& k)
	{

	}

	const_iterator		upper_bound(const key_type& k) const
	{

	}

	pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
	{

	}

	pair<iterator, iterator>				equal_range(const key_type& k)
	{

	}

};

#endif