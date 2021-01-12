#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include "Node.hpp"

template<typename List>
class ListIterator
{
public:
	typedef typename List::value_type		value_type;
	typedef typename List::node_type*		pointer_type;
	typedef typename List::value_type&		reference_type;

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

	void	print_here()
	{
		std::cout << "here\n";
	}

public:

	typedef T								value_type;
	typedef Node<T>							node_type;
	typedef T&								reference;
	typedef const Node<T>&					const_reference;
	typedef Node<T>*						pointer;
	typedef const Node<T>*					const_pointer;
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

	iterator			begin()
	{
		return iterator(_head);
	}

	const_iterator		begin() const
	{
		return iterator(_head);
	}

	iterator			end()
	{
		return iterator(_tail);
	}

	const_iterator		end() const
	{
		return iterator(_tail);
	}

	reverse_iterator	rbgein()
	{
		return iterator(_tail);
	}

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
		return _head->next;
	}

	//tested 0
	const_reference		front() const
	{
		return _head->next;
	}

	//tested 0
	reference			back()
	{
		return _tail;
	}

	//tested 0
	const_reference		back() const
	{
		return _tail;
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
	iterator 			insert(iterator &position, const value_type& val)
	{
		Node<T> *n = new Node<T>(val);
		position.getNode()->insert(n);
		if (position == begin())
			_head = n;
		_size++;
		return iterator(n);
	}

	//tested 1
	void				insert(iterator &position, size_type n, const value_type& val)
	{
		for (size_t i = 0; i < n; i++)
			insert(position, val);
		_size += n;
	}

	//tested 1
	void				insert(iterator position, iterator first, iterator last)
	{
		for((void)first; first != last; ++first)
			insert(position, *first);
	}

	//tested 1
	iterator			erase(iterator& position)
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
		for (List<T>::iterator it = begin(); it != end(); ++it)
			x.push_back(*it);
		clear();
		for (List<T>::iterator it = tmp.begin(); it != tmp.end(); ++it)
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
		for (List<T>::iterator it = begin(); it != end(); ++it)
			pop_front();
	}

	//tested 0
	void				splice(iterator position, List<T>& x)
	{
		for(List<T>::iterator it = x.begin(); it != x.end(); ++it)
			insert(position, *it);
		x.clear();
	}

	//tested 0
	void				splice(iterator position, List<T>& x, iterator i)
	{
		for(List<T>::iterator it = i; it != x.end(); ++it)
		{
			print_here();
			insert(position, *it);
		}
	}

	//tested 0
	void				splice(iterator position, List<T>& x, iterator first, iterator last)
	{

	}

	//tested 0
	void				remove(const value_type& val)
	{

	}

	//tested 0
	template <class Predicate>
  	void				remove_if (Predicate pred)
	  {

	  }

	void				unique()
	{

	}

	//tested 0
	template <class BinaryPredicate>
  	void				unique(BinaryPredicate binary_pred)
	  {

	  }

	//tested 0
	void				merge(List<T>& x)
	{

	}

	//tested 0
	template <class Compare>
	void				merge(List<T>& x, Compare comp)
	{

	}

	//tested 0
	void				sort()
	{

	}

	//tested 0
	template <class Compare>
	void				sort(Compare comp)
	{

	}

	//tested 0
	void				reverse()
	{

	}


	//tested 0
	List<T>&		operator=(const List<T>& lhs)
	{
		clear();
		for (List<T>::iterator it = lhs.begin(); it != lhs.end(); ++it)
			push_back(*it);
		return *this;
	}

};

#endif