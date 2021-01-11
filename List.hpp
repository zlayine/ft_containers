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

	~List()
	{
		clear();
		delete _tail;
	}

	iterator			begin()
	{
		return iterator(_head);
	}

	const_iterator			begin() const
	{
		return iterator(_head);
	}

	iterator			end()
	{
		return iterator(_tail);
	}

	const_iterator			end() const
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

	//tested 0
	void 				assign(size_type n, const value_type& val)
	{
		clear();
		for(size_type i = 0; i < n; i++)
			push_front(val);
	}

	//tested 0
 	void				assign(const_iterator first, const_iterator last)
	{
		clear();
		for(first; first != last; ++first)
			push_front(*first);
	}

	//tested 1
	void				push_front(const T& val)
	{
		Node<T> *n = new Node<T>(val, _head);
		_head = n;
		_size++;
	}

	//tested 1
	void				pop_front()
	{
		Node<T> *tmp;
		
		if (_size == 0)
			return ;
		tmp = _head;
		_head = _head->next;
		_head->prev = nullptr;
		delete tmp;
		if (--_size == 0)
			_tail = _head;
	}

	//tested 1
	void				push_back(const T& val)
	{
		Node<T> *n = new Node<T>(val, _tail);
		if (_size == 0)
			_head = n;
		_tail = n->next;
		_size++;
	}

	//tested 1
	void				pop_back()
	{
		Node<T> *tmp;

		// std::cout << "size: " << _size << std::endl;
		if (_size == 0)
			return ;
		tmp = _tail->prev;
		_tail->prev = tmp->prev;
		delete tmp;
		if (--_size == 0)
		{
			// _head = _tail;
			_tail = _head;
		}
		else 
		{
			// std::cout << "h size: " << _size << std::endl;
			_tail->prev->next = _tail;
		}
		// std::cout << "head: " << _tail->data << std::endl;
	}

	//tested 0
	iterator 			insert(iterator &position, const value_type& val)
	{
		Node<T> *n = new Node<T>();
		n->data = val;
		n->next = position.getNode();
		n->prev = position->prev;
		n->prev->next = n;
		n->next->prev = n;
		position = n->prev;
		position++;
		_size++;
		return position;
	}

	//tested 0
	void				insert(iterator &position, size_type n, const value_type& val)
	{
		Node<T> *tmp;
		
		tmp = position.getNode();
		for (size_t i = 0; i < n; i++)
		{
			Node<T> *n = new Node<T>();
			n->data = val;
			n->next = tmp;
			n->prev = tmp->prev;
			n->prev->next = n;
			n->next->prev = n;
			_size++;
		}
		position = tmp->prev;
	}

	//tested 0
	void				insert(iterator position, iterator first, iterator last)
	{
		Node<T> *tmp;

		tmp = position.getNode();
		for((void)first; first != last; ++first)
		{
			Node<T> *n = new Node<T>();
			n->data = *first;
			n->next = tmp;
			n->prev = tmp->prev;
			n->prev->next = n;
			n->next->prev = n;
			_size++;
			++position;
		}
		position = tmp->prev;
	}

	//tested 0
	iterator			erase(iterator& position)
	{
		Node<T> *tmp;

		tmp = position.getNode();
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		delete tmp;
		return position;
	}

	//tested 0 (test weird shit with this)
	iterator			erase(iterator first, iterator last)
	{
		Node<T> *tmp;

		while (first.getNode() != last.getNode())
		{
			tmp = first.getNode();
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			delete tmp;
		}
		return first;
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

	//tested 0
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

	//tested 0
	void				clear()
	{
		for (List<T>::iterator it = begin(); begin() != end(); ++it)
		{
			pop_back();
		}
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