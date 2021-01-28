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
private:
	Tree<T, Compare>	_tree;
	size_t				_size;
public:

    typedef T                   value_type;
    typedef key                 key_type;
    typedef T                   mapped_type;
	typedef Compare				key_compare;
	typedef Compare				value_compare;
	typedef T&					reference;
	typedef const T&			const_reference;
	typedef T*					pointer;
	typedef const T*			const_pointer;
	typedef TreeIterator<Map<key, T>, >			iterator;
	typedef const TreeIterator<Map<key, T> >	const_iterator;
	typedef TreeIterator<Map<key, T> >			reverse_iterator;
	typedef const TreeIterator<Map<key, T> >	const_reverse_iterator;
	typedef ptrdiff_t						difference_type;
	typedef size_t							size_type;

    Map();

};

#endif