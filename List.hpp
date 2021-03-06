#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"
#include "ReverseIterator.hpp"
#include <cmath>

namespace ft
{

	template <typename List>
	class ListIterator
	{
	public:
		typedef typename List::value_type value_type;
		typedef typename List::node_type *pointer_type;
		typedef typename List::value_type &reference_type;
		typedef ptrdiff_t difference_type;

		ListIterator() : _ptr(nullptr)
		{
		}

		ListIterator(ListIterator const &src) : _ptr(src._ptr)
		{
		}

		ListIterator(pointer_type ptr) : _ptr(ptr)
		{
		}

		virtual ~ListIterator()
		{
		}

		pointer_type getNode() const
		{
			return _ptr;
		}

		ListIterator &operator++()
		{
			_ptr = _ptr->next;
			return *this;
		}

		ListIterator operator++(int)
		{
			ListIterator iterator = *this;
			++(*this);
			return iterator;
		}

		ListIterator operator+(difference_type v)
		{
			pointer_type tmp;
			tmp = _ptr;
			while (v--)
				tmp = tmp->next;
			return tmp;
		}

		ListIterator operator-(difference_type v)
		{
			while (v--)
				_ptr = _ptr->prev;
			return *this;
		}

		ListIterator &operator--()
		{
			_ptr = _ptr->prev;
			return *this;
		}

		ListIterator operator--(int)
		{
			ListIterator iterator = *this;
			--(*this);
			return iterator;
		}

		pointer_type operator->()
		{
			return _ptr;
		}

		reference_type operator*()
		{
			return _ptr->data;
		}

		bool operator==(const ListIterator &other) const
		{
			return _ptr == other._ptr;
		}

		bool operator!=(const ListIterator &other) const
		{
			return _ptr != other._ptr;
		}

		ListIterator &operator=(const ListIterator &src)
		{
			_ptr = src._ptr;
			return *this;
		}

	protected:
		pointer_type _ptr;
	};

	template <typename T>
	class List
	{
	private:
		Node<T> *_head;
		Node<T> *_tail;
		size_t _size;

	public:
		typedef T value_type;
		typedef Node<T> node_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef ListIterator<List<T> > iterator;
		typedef const ListIterator<List<T> > const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef const ReverseIterator<iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		List() : _size(0)
		{
			_head = _tail = new Node<T>();
		}

		List(List<T> const &src)
		{
			_size = 0;
			_head = _tail = new Node<T>();
			for (iterator it = src.begin(); it != src.end(); ++it)
				push_back(*it);
		}

		virtual ~List()
		{
			clear();
			delete _tail;
		}

		iterator begin()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return iterator(_head);
		}

		iterator end()
		{
			return iterator(_tail);
		}

		const_iterator end() const
		{
			return iterator(_tail);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(_tail);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(_head);
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
			return std::numeric_limits<size_type>::max() / sizeof(Node<T>);
		}

		reference front()
		{
			return _head->data;
		}

		const_reference front() const
		{
			return _head->data;
		}

		reference back()
		{
			return _tail->prev->data;
		}

		const_reference back() const
		{
			return _tail->prev->data;
		}

		void assign(size_type n, const value_type &val)
		{
			clear();
			for (size_type i = 0; i < n; i++)
				push_back(val);
		}

		void assign(iterator first, iterator last)
		{
			clear();
			for ((void)first; first != last; ++first)
				push_back(*first);
		}

		void push_front(const T &val)
		{
			Node<T> *n = new Node<T>(val);
			_head->insert(n);
			_head = n;
			_size++;
		}

		void push_back(const T &val)
		{
			Node<T> *n = new Node<T>(val);
			_tail->insert(n);
			if (_size++ == 0)
				_head = n;
		}

		void pop_front()
		{
			if (!_size)
				return;
			_head = _head->erase();
			if (_size-- == 1)
				_head = _tail;
		}

		void pop_back()
		{
			if (!_size)
				return;
			_tail->prev->erase();
			if (_size-- == 1)
				_head = _tail;
		}

		iterator insert(iterator position, const value_type &val)
		{
			Node<T> *n = new Node<T>(val);
			position.getNode()->insert(n);
			if (position == begin())
				_head = n;
			_size++;
			return iterator(n);
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			for (size_t i = 0; i < n; i++)
				insert(position, val);
		}

		void insert(iterator position, iterator first, iterator last)
		{
			for ((void)first; first != last; ++first)
				insert(position, *first);
		}

		iterator erase(iterator position)
		{
			position.getNode()->erase();
			if (position == begin())
				_head = _head->next;
			position++;
			_size--;
			if (position == end())
				return (iterator(--position));
			return iterator(position);
		}

		iterator erase(iterator first, iterator last)
		{
			iterator position;
			position = first;
			for ((void)first; first != last; ++first)
				position = erase(position);
			if (position == last)
				return iterator(first);
			if (position.getNode() == nullptr)
				position = first;
			return iterator(position);
		}

		void swap(List<T> &x)
		{
			List<T> tmp;

			tmp = x;
			x.clear();
			for (iterator it = begin(); it != end(); ++it)
				x.push_back(*it);
			clear();
			for (iterator it = tmp.begin(); it != tmp.end(); ++it)
				push_back(*it);
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n < _size)
			{
				size_type total = _size;
				for (size_type i = n; i < total; i++)
					pop_back();
			}
			else if (n > _size)
			{
				for (size_type i = _size; i < n; i++)
					push_back(val);
			}
		}

		void clear()
		{
			for (iterator it = begin(); it != end(); ++it)
				pop_front();
		}

		void splice(iterator position, List<T> &x)
		{
			for (iterator it = x.begin(); it != x.end(); ++it)
				insert(position, *it);
			x.clear();
		}

		void splice(iterator position, List<T> &x, iterator i)
		{
			insert(position, *i);
			x.erase(i);
		}

		void splice(iterator position, List<T> &x, iterator first, iterator last)
		{
			for (iterator it = first; it != last; ++it)
				insert(position, *it);
			x.erase(first, last);
		}

		void remove(const value_type &val)
		{
			for (iterator it = begin(); it != end(); ++it)
			{
				if (*it == val)
					erase(it);
			}
		}

		template <class Predicate>
		void remove_if(Predicate pred)
		{
			for (iterator it = begin(); it != end(); ++it)
			{
				if (pred(*it))
					remove(*it);
			}
		}

		void unique()
		{
			for (iterator it = begin() + 1; it != end(); ++it)
			{
				if (*(it + 1) == *it)
					erase(it);
			}
		}

		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{
			for (iterator it = begin() + 1; it != end(); ++it)
			{
				if (binary_pred(*(it + 1), *it))
					erase(it);
			}
		}

		void merge(List<T> &x)
		{
			iterator s1 = begin();
			iterator s2 = x.begin();

			iterator e1 = end();
			iterator e2 = x.end();

			while (s1 != e1 && s2 != e2)
			{
				if (*s2 < *s1)
				{
					insert(s1, *s2);
					x.pop_front();
					s2++;
				}
				else
					s1++;
			}
			splice(s1, x);
		}

		template <class Compare>
		void merge(List<T> &x, Compare comp)
		{
			iterator s1 = begin();
			iterator s2 = x.begin();

			iterator e1 = end();
			iterator e2 = x.end();

			while (s1 != e1 && s2 != e2)
			{
				if (comp(*s1, *s2))
				{
					insert(s1, *s2);
					x.pop_front();
					s2++;
				}
				else
					s1++;
			}
			splice(s1, x);
		}

		void sort()
		{
			iterator tmp;
			if (this->_size == 1)
				return;
			for (iterator it = begin(); it != end(); ++it)
			{
				for (iterator its = it + 1; its != end(); ++its)
				{
					if (*its < *it)
					{
						if (it.getNode() == this->_head)
							this->_head = its.getNode();
						it.getNode()->swap(its.getNode());
						tmp = its;
						its = it;
						it = tmp;
					}
				}
			}
		}

		template <class Compare>
		void sort(Compare comp)
		{
			iterator tmp;
			if (this->_size == 1)
				return;
			for (iterator it = begin(); it != end(); ++it)
			{
				for (iterator its = it + 1; its != end(); ++its)
				{
					if ((*comp)(*its, *it))
					{
						if (it.getNode() == this->_head)
							this->_head = its.getNode();
						it.getNode()->swap(its.getNode());
						tmp = its;
						its = it;
						it = tmp;
					}
				}
			}
		}

		void reverse()
		{
			T tmp;
			iterator h = begin();
			iterator e = --end();

			size_type len = size() / 2;
			for (size_type i = 0; i < len; i++)
			{
				tmp = h.getNode()->data;
				h.getNode()->data = e.getNode()->data;
				e.getNode()->data = tmp;
				h++;
				e--;
			}
		}

		//tested 0
		List<T> &operator=(const List<T> &lhs)
		{
			clear();
			for (iterator it = lhs.begin(); it != lhs.end(); ++it)
				push_back(*it);
			return *this;
		}
	};

	template <typename T>
	bool operator==(const List<T> &lhs, const List<T> &rhs)
	{
		typename List<T>::iterator s1 = lhs.begin();
		typename List<T>::iterator s2 = rhs.begin();
		for ((void)s1; s1 != lhs.end(); ++s1)
		{
			if (*s1 != *s2 || s2 == rhs.end())
				return false;
			s2++;
		}
		return true;
	}

	template <typename T>
	bool operator>=(const List<T> &lhs, const List<T> &rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T>
	bool operator>(const List<T> &lhs, const List<T> &rhs)
	{
		typename List<T>::iterator s1 = lhs.begin();
		typename List<T>::iterator s2 = rhs.begin();
		for ((void)s1; s1 != lhs.end(); ++s1)
		{
			if (*s1 < *s2)
				return false;
			else if (*s1 > *s2 || s2 == rhs.end())
				return true;
			s2++;
		}
		return (s2 == rhs.end());
	}

	template <typename T>
	bool operator<=(const List<T> &lhs, const List<T> &rhs)
	{
		return !(lhs > rhs);
	}

	template <typename T>
	bool operator<(const List<T> &lhs, const List<T> &rhs)
	{
		return (rhs > lhs);
	}

	template <typename T>
	bool operator!=(const List<T> &lhs, const List<T> &rhs)
	{
		return !(lhs == rhs);
	}

}

#endif