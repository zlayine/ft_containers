#ifndef MAP_HPP
# define MAP_HPP

#include "Tools.hpp"
#include "Tree.hpp"

template<typename key, typename T, typename Compare = ::less<key> >
class MapCompare : public std::binary_function<std::pair<key, T>, std::pair<key, T>, bool>
{
public:
	MapCompare()
	{

	}
	// MapCompare();
	virtual ~MapCompare()
	{

	}

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
    typedef T                   						mapped_type;
    typedef key                 						key_type;
	typedef	typename std::pair<key_type, mapped_type>	pair_type;
    typedef pair_type							value_type;
	typedef Compare										key_compare;
	typedef Compare										value_compare;
	typedef T&											reference;
	typedef const T&									const_reference;
	typedef T*											pointer;
	typedef const T*									const_pointer;
	typedef	Tree<value_type, Compare>					tree_type;
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
    Map()
	{

	}

	Map(Map const &src)
	{
		
	}
	
	~Map()
	{

	}

	//tested 0
	iterator			begin()
	{
		return iterator(_tree.getHead());
	}

	//tested 0
	const_iterator		begin() const
	{
		return iterator(_tree.getHead());
	}

	//tested 0
	iterator			end()
	{
		return iterator();
	}

	//tested 0
	const_iterator		end() const
	{
		return iterator();
	}

	//tested 0
	reverse_iterator	rbegin()
	{
		return iterator(_tree.getTail());
	}

	//tested 0
	reverse_iterator	rend()
	{
		return iterator();
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

	//tested 0
	void				clear()
	{
		// for (iterator it = begin(); it != end(); ++it)
		// 	pop_front();
	}

	//tested 0
	T&	operator[](int i) const
	{
		
	}

	//tested 0
	std::pair<iterator, bool>	insert(const value_type& val)
	{
		if (!_tree.searchNode(val))
		{
			_tree.insertNode(val);
			return std::pair<iterator, bool>(iterator(_tree.getHead()), true);
		}
		return std::pair<iterator, bool>(iterator(_tree.getHead()), false);
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

	//tested 0
	void				erase(iterator position)
	{

	}

	//tested 0
	size_type			erase(const key_type& k)
	{

	}

	//tested 0
	void				erase(iterator first, iterator last)
	{

	}

	//tested 0
	void				swap(Map<key, T>& x)
	{

	}

	//tested 0
	key_compare			key_comp() const
	{

	}

	//tested 0
	value_compare		value_comp() const
	{

	}

	//tested 0
	iterator			find(const key_type& k)
	{

	}

	//tested 0
	const_iterator		find(const key_type& k) const
	{

	}

	//tested 0
	size_type			count(const key_type& k) const
	{

	}

	//tested 0
	iterator			lower_bound(const key_type& k)
	{

	}

	//tested 0
	const_iterator		lower_bound(const key_type& k) const
	{

	}

	//tested 0
	iterator			upper_bound(const key_type& k)
	{

	}

	//tested 0
	const_iterator		upper_bound(const key_type& k) const
	{

	}

	//tested 0
	std::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
	{

	}

	//tested 0
	std::pair<iterator, iterator>				equal_range(const key_type& k)
	{

	}

};

#endif