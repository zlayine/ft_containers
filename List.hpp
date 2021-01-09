#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>

template<typename List>
class ListIterator
{
public:
	typedef typename List::value_type		value_type;
	typedef typename List::allocator_type*	pointer_type;
	typedef typename List::value_type&		reference_type;

	ListIterator(pointer_type ptr) : _ptr(ptr)
	{
	}

	ListIterator&	operator++()
	{
		_ptr = _ptr->next;
		return *this;
	}

	ListIterator	operator++(int)
	{
		ListIterator iterator = *this;
		++(*this);
		return iterator;
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
		return _ptr->data == other._ptr->data;
	}

	bool			operator!=(const ListIterator& other) const
	{
		return _ptr->data != other._ptr->data;
	}

private:
	pointer_type	_ptr;

};

template<typename T>
class Node 
{ 
public:
	T			data; 
	Node<T>*	next; 
	Node<T>*	prev; 

	Node() : next(nullptr), prev(nullptr)
	{
	}
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
	typedef Node<T>							allocator_type;
	typedef Node<T>&						reference;
	typedef const Node<T>&					const_reference;
	typedef Node<T>*						pointer;
	typedef const Node<T>*					const_pointer;
	typedef ListIterator<List<T> >			iterator;
	typedef const ListIterator<List<T> >	const_iterator;
	typedef ListIterator<List<T> >			reverse_iterator;
	typedef const ListIterator<List<T> >	const_reverse_iterator;
	typedef ptrdiff_t						difference_type;
	typedef size_t							size_type;

	List();
	~List();

	size_t		size() const;

	iterator	begin() const
	{
		return iterator(_head);
	}

	iterator	end() const
	{
		return iterator(_tail);
	}

	void		push_back(const T& val);
};

template<typename T>
List<T>::List() : _size(0)
{
	_head = new Node<T>();
	_tail = new Node<T>();
	_head->next = _tail;
	_tail->prev = _head;
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
size_t		List<T>::size() const
{
	return (_size);
}

template<typename T>
void		List<T>::push_back(const T& val)
{
	Node<T> *n;
	n = _tail;
	n->data = val;
	_tail = new Node<T>();
	_tail->prev = n;
	n->next = _tail;
	_size++;
}

#endif