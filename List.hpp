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
	List(List<T> const &src);
	~List();

	iterator			begin();
	iterator			end();
	reverse_iterator	rbgein();
	reverse_iterator	rend();
	
	bool				empty() const;
	size_type			size() const;
	size_type			max_size() const;
	
	reference			front();
	const_reference		front() const;
	reference			back();
	const_reference		back() const;
	
	// template <class InputIterator>
 	// void assign (InputIterator first, InputIterator last);
	void 				assign (size_type n, const value_type& val);
	void				push_front(const T& val);
	void				pop_front();
	void				push_back(const T& val);
	void				pop_front();
	iterator 			insert(iterator position, const value_type& val);
	iterator			erase (iterator position);
	iterator			erase (iterator first, iterator last);
	void 				swap(List<T>& x);
	void 				resize(size_type n, value_type val = value_type());
	void				clear();

	void				splice(iterator position, List<T>& x);
	void				splice(iterator position, List<T>& x, iterator i);
	void				splice(iterator position, List<T>& x, iterator first, iterator last);
	void				remove(const value_type& val);
// 	template <class Predicate>
//   void remove_if (Predicate pred);
	void				unique();
	// template <class BinaryPredicate>
  	// void unique (BinaryPredicate binary_pred);
	void				merge(List<T>& x);
	// template <class Compare>
	// void merge (List<T>& x, Compare comp);
	void				sort();
	// template <class Compare>
	// void sort (Compare comp);
	void				reverse();

	List<T>&		operator=(const List<T>& lhs);
	bool			operator==(const List<T>& rhs);
	bool			operator>=(const List<T>& rhs);
	bool			operator>(const List<T>& rhs);
	bool			operator<=(const List<T>& rhs);
	bool			operator<(const List<T>& rhs);
	bool			operator!=(const List<T>& rhs);
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
List<T>::size_type		List<T>::size() const
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

template<typename T>
List<T>::iterator	List<T>::begin()
{
	return iterator(_head);
}

template<typename T>
List<T>::iterator	List<T>::end()
{
	return iterator(_tail);
}

#endif