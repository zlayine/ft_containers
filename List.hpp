#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include "Node.hpp"

namespace ft {
	
template<typename List>
class ListIterator
{
public:
	typedef typename List::value_type		value_type;
	typedef typename List::node_type*		pointer_type;
	typedef typename List::value_type&		reference_type;
	typedef ptrdiff_t						difference_type;

	ListIterator() : _ptr(nullptr)
	{
	}

	ListIterator(pointer_type ptr) : _ptr(ptr)
	{
	}

	pointer_type	getNode() const
	{
		return _ptr;
	}

	// if its the end it segfault
	ListIterator&	operator++()
	{
		_ptr = _ptr->next;
		return *this;
	}

	// if its the end it segfault
	ListIterator	operator++(int)
	{
		ListIterator iterator = *this;
		++(*this);
		return iterator;
	}
	// tmp + 1
	ListIterator	operator+(difference_type v)
	{	
		pointer_type tmp;
		tmp = _ptr;
		while (v--)
			tmp = tmp->next;
		return tmp;
	}

	ListIterator	operator-(difference_type v)
	{
		while (v--)
			_ptr = _ptr->prev;
		return *this;
	}

	ListIterator&	operator--()
	{
		_ptr = _ptr->prev;
		return *this;
	}

	ListIterator	operator--(int)
	{
		ListIterator iterator = *this;
		--(*this);
		return iterator;
	}

	pointer_type	operator->()
	{
		return _ptr;
	}

	reference_type	operator*()
	{
		return _ptr->data;
	}

	bool			operator==(const ListIterator& other) const
	{
		return _ptr == other._ptr;
	}

	bool			operator!=(const ListIterator& other) const
	{
		return _ptr != other._ptr;
	}

private:
	pointer_type	_ptr;

};

template<typename T>
class List
{
private:
	Node<T>	*_head;
	Node<T>	*_tail;
	size_t	_size;

public:

	typedef T								value_type;
	typedef Node<T>							node_type;
	typedef T&								reference;
	typedef const T&						const_reference;
	typedef T*								pointer;
	typedef const T*						const_pointer;
	typedef ListIterator<List<T> >			iterator;
	typedef const ListIterator<List<T> >	const_iterator;
	typedef ListIterator<List<T> >			reverse_iterator;
	typedef const ListIterator<List<T> >	const_reverse_iterator;
	typedef ptrdiff_t						difference_type;
	typedef size_t							size_type;

	List() : _size(0)
	{
		_head = _tail = new Node<T>();
	}

	List(List<T> const &src)
	{

	}

	virtual ~List()
	{
		clear();
		delete _tail;
	}

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
	
	//tested 0
	reference			front()
	{
		return _head->data;
	}

	//tested 0
	const_reference		front() const
	{
		return _head->data;
	}

	//tested 0
	reference			back()
	{
		return _tail->prev->data;
	}

	//tested 0
	const_reference		back() const
	{
		return _tail->prev->data;
	}

	//tested 1
	void 				assign(size_type n, const value_type& val)
	{
		clear();
		for(size_type i = 0; i < n; i++)
			push_front(val);
	}

	//tested 1
 	void				assign(iterator first, iterator last)
	{
		clear();
		for((void)first; first != last; ++first)
			push_front(*first);
	}

	//tested 1
	void				push_front(const T& val)
	{
		Node<T> *n = new Node<T>(val);
		_head->insert(n);
		_head = n;
		_size++;
	}

	//tested 1
	void				push_back(const T& val)
	{
		Node<T> *n = new Node<T>(val);
		_tail->insert(n);
		if (_size++ == 0)
			_head = n;
	}

	//tested 1
	void				pop_front()
	{
		if (!_size)
			return;
		_head = _head->erase();
		if (_size-- == 1)
			_head = _tail;
	}

	//tested 1
	void				pop_back()
	{
		if (!_size)
			return;
		_tail->prev->erase();
		if (_size-- == 1)
			_head = _tail;
	}

	//tested 1
	iterator 			insert(iterator position, const value_type& val)
	{
		Node<T> *n = new Node<T>(val);
		position.getNode()->insert(n);
		if (position == begin())
			_head = n;
		_size++;
		return iterator(n);
	}

	//tested 1
	void				insert(iterator position, size_type n, const value_type& val)
	{
		for (size_t i = 0; i < n; i++)
			insert(position, val);
		// _size += n;
	}

	//tested 1
	void				insert(iterator position, iterator first, iterator last)
	{
		for((void)first; first != last; ++first)
			insert(position, *first);
	}

	//tested 0  just removed the reference, must be checked again
	iterator			erase(iterator position)
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

	//tested 1 (test weird shit with this)
	iterator			erase(iterator first, iterator last)
	{
		iterator position;
		position = first;
		for((void)first; first != last; ++first)
			position = erase(position);
		if (position == last)
			return iterator(first);
		if (position.getNode() == nullptr)
			position = first;
		return iterator(position);
	}

	//tested 1
	void 				swap(List<T>& x)
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

	//tested 1
	void 				resize(size_type n, value_type val = value_type())
	{
		if (n < _size)
		{
			size_type 	total = _size;
			for (size_type i = n; i < total; i++)
				pop_back();
		}
		else if (n > _size)
		{
			for (size_type i = _size; i < n; i++)
				push_back(val);
		}
	}

	//tested 1
	void				clear()
	{
		for (iterator it = begin(); it != end(); ++it)
			pop_front();
	}

	//tested 1
	void				splice(iterator position, List<T>& x)
	{
		for(iterator it = x.begin(); it != x.end(); ++it)
			insert(position, *it);
		x.clear();
	}

	//tested 1
	void				splice(iterator position, List<T>& x, iterator i)
	{
		insert(position, *i);
		x.erase(i);
	}

	//tested 1
	void				splice(iterator position, List<T>& x, iterator first, iterator last)
	{
		for(iterator it = first; it != last; ++it)
			insert(position, *it);
		x.erase(first, last);
	}

	//tested 1
	void				remove(const value_type& val)
	{
		for(iterator it = begin(); it != end(); ++it)
		{
			if (*it == val)
				erase(it);
		}
	}

	//tested 1 need more testing
	template <class Predicate>
  	void				remove_if(Predicate pred)
	{
		for(iterator it = begin(); it != end(); ++it)
		{
			if (pred(*it))
				remove(*it);
		}
	}

	//tested 1
	void				unique()
	{
		for(iterator it = begin() + 1; it != end(); ++it)
		{
			if (*(it + 1) == *it)
				erase(it);
		}
	}

	//tested 1
	template <class BinaryPredicate>
  	void				unique(BinaryPredicate binary_pred)
	{
		for(iterator it = begin() + 1; it != end(); ++it)
		{
			if (binary_pred(*(it + 1), *it))
				erase(it);
		}
	}

	//tested 0
	void				merge(List<T>& x)
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

	//tested 0
	template <class Compare>
	void				merge(List<T>& x, Compare comp)
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

	//tested 1
	void				sort()
	{
		T	tmp;

		for(iterator it = begin(); it != end(); ++it)
		{
			for(iterator its = it + 1; its != end(); ++its)
			{
				if (*its < *it)
				{
					tmp = *its;
					*its = *it;
					*it = tmp;
				}
			}
		}
	}

	//tested 0
	template <class Compare>
	void				sort(Compare comp)
	{
		T	tmp;

		for(iterator it = begin(); it != end(); ++it)
		{
			for(iterator its = it + 1; its != end(); ++its)
			{
				if (comp(*its, *it))
				{
					tmp = *its;
					*its = *it;
					*it = tmp;
				}
			}
		}
	}

	//tested 1
	void				reverse()
	{
		T tmp;
		iterator h = begin();
		iterator e = --end();

		size_type len = size() / 2;
		for (size_type i = 0; i < len ; i++)
		{
			tmp = h.getNode()->data;
			h.getNode()->data = e.getNode()->data;
			e.getNode()->data = tmp;
			h++;
			e--;
		}
	}


	//tested 0
	List<T>&		operator=(const List<T>& lhs)
	{
		clear();
		for (iterator it = lhs.begin(); it != lhs.end(); ++it)
			push_back(*it);
		return *this;
	}

};

template<typename T>
bool			operator==(const List<T>& lhs, const List<T>& rhs)
{
	typename iterator s1 = lhs.begin();
	typename iterator s2 = rhs.begin();
	for((void)s1; s1 != lhs.end(); ++s1)
	{
		if (*s1 != *s2 || s2 == rhs.end())
			return false;
		s2++;
	}
	return true;
}

template<typename T>
bool			operator>=(const List<T>& lhs, const List<T>& rhs)
{
	return !(lhs < rhs);
}

template<typename T>
bool			operator>(const List<T>& lhs, const List<T>& rhs)
{
	typename iterator s1 = lhs.begin();
	typename iterator s2 = rhs.begin();
	for((void)s1; s1 != lhs.end(); ++s1)
	{
		if (*s1 < *s2)
			return false;
		else if (*s1 > *s2 || s2 == rhs.end())
			return true;
		s2++;
	}
	return (s2 == rhs.end());
}

template<typename T>
bool			operator<=(const List<T>& lhs, const List<T>& rhs)
{
	return !(lhs > rhs);
}

template<typename T>
bool			operator<(const List<T>& lhs, const List<T>& rhs)
{
	return (rhs > lhs);
}

template<typename T>
bool			operator!=(const List<T>& lhs, const List<T>& rhs)
{
	return !(lhs == rhs);
}

}

#endif