#ifndef MAP_HPP
#define MAP_HPP

#include "Tools.hpp"
#include "Tree.hpp"
#include "ReverseIterator.hpp"
#include <cmath>

namespace ft
{
	template <typename key, typename T, typename Compare = ft::less<key> >
	class MapCompare : public std::binary_function<std::pair<key, T>, std::pair<key, T>, bool>
	{
	public:
		typedef typename std::pair<key, T> value_type;

		MapCompare()
		{
		}

		MapCompare(MapCompare const &src)
		{
			cmp = src.cmp;
		}

		virtual ~MapCompare()
		{
		}

		bool operator()(const value_type &x, const value_type &y) const
		{
			return (cmp(x.first, y.first));
		}

		bool operator()(const key &x, const key &y) const
		{
			return (cmp(x, y));
		}

	private:
		Compare cmp;
	};

	template <typename key, typename T, typename Compare = MapCompare<key, T> >
	class Map
	{

	public:
		typedef T mapped_type;
		typedef key key_type;
		typedef typename std::pair<key_type, mapped_type> pair_type;
		typedef pair_type value_type;
		typedef Compare key_compare;
		typedef Compare value_compare;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef Tree<value_type, Compare> tree_type;
		typedef typename tree_type::node_type node_type;
		typedef TreeIterator<pair_type, node_type> iterator;
		typedef const TreeIterator<pair_type, node_type> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef const ReverseIterator<iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		tree_type _tree;
		size_type _size;

	public:
		Map()
		{
		}

		Map(Map<key, T> &src)
		{
			insert(src.begin(), src.end());
		}

		virtual ~Map()
		{
		}

		iterator begin()
		{
			return iterator(_tree.getHead());
		}

		const_iterator begin() const
		{
			return iterator(_tree.getHead());
		}

		iterator end()
		{
			return iterator(_tree.getTail());
		}

		const_iterator end() const
		{
			return iterator(_tree.getTail());
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(_tree.getTail());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(_tree.getHead());
		}

		bool empty() const
		{
			return _size == 0;
		}

		size_type size() const
		{
			return _size;
		}

		size_type max_size() const
		{
			return std::numeric_limits<size_type>::max() / sizeof(node_type);
		}

		void clear()
		{
			erase(begin(), end());
		}

		mapped_type &operator[](key_type const &k)
		{
			TreeNode<pair_type> *node = _tree.searchNode(std::pair<key, T>(k, mapped_type()));
			if (node)
				return node->data.second;
			return (*((this->insert(std::make_pair(k, mapped_type()))).first)).second;
		}

		std::pair<iterator, bool> insert(const value_type &val)
		{
			if (!_tree.searchNode(val))
			{
				_tree.insertNode(val);
				_size++;
				return std::pair<iterator, bool>(iterator(_tree.getHead()), true);
			}
			return std::pair<iterator, bool>(iterator(_tree.getHead()), false);
		}

		iterator insert(iterator position, const value_type &val)
		{
			position = 0;
			return insert(val).first;
		}

		void insert(iterator first, iterator last)
		{
			for ((void)first; first != last; ++first)
				insert(*first);
		}

		void erase(iterator position)
		{
			_tree.deleteNode(*position);
			_size--;
		}

		size_type erase(const key_type &k)
		{
			_tree.deleteNode(std::make_pair(k, mapped_type()));
			return --_size;
		}

		void erase(iterator first, iterator last)
		{
			for ((void)first; first != last; ++first)
				erase(first);
		}

		void swap(Map<key, T> &x)
		{
			Map<key, T> tmp(x);

			x.clear();
			x.insert(begin(), end());
			clear();
			insert(tmp.begin(), tmp.end());
		}

		key_compare key_comp() const
		{
			key_compare cmp;
			return cmp;
		}

		value_compare value_comp() const
		{
			value_compare cmp;
			return cmp;
		}

		iterator find(const key_type &k)
		{
			TreeNode<pair_type> *node = _tree.searchNode(std::pair<key, T>(k, mapped_type()));
			if (node)
				return iterator(node);
			else
				return end();
		}

		const_iterator find(const key_type &k) const
		{
			return find(k);
		}

		size_type count(const key_type &k) const
		{
			if (find(k))
				return 1;
			return 0;
		}

		iterator lower_bound(const key_type &k)
		{
			Compare cmp;
			for (iterator it = begin(); it != end(); ++it)
			{
				if (cmp(k, (*it).first))
				{
					if (it != begin())
						return --it;
					return it;
				}
				else if (k == (*it).first)
					return it;
			}
			return this->end();
		}

		const_iterator lower_bound(const key_type &k) const
		{
			return lower_bound(k);
		}

		iterator upper_bound(const key_type &k)
		{
			Compare cmp;
			for (iterator it = begin(); it != end(); ++it)
			{
				if (cmp(k, (*it).first))
					return it;
			}
			return this->end();
		}

		const_iterator upper_bound(const key_type &k) const
		{
			return upper_bound(k);
		}

		std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return std::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
		}

		
		std::pair<iterator, iterator> equal_range(const key_type &k)
		{
			return std::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
		}

		Map<key, T> &operator=(const Map<key, T> &lhs)
		{
			clear();
			insert(lhs.begin(), lhs.end());
			return *this;
		}
	};

}

#endif