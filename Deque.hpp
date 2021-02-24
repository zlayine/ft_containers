#ifndef DEQUE_HPP
# define DEQUE_HPP

#include <iostream>

namespace ft {

template<typename Deque>
class DequeIterator
{
public:
	typedef typename Deque::value_type		value_type;
	typedef value_type*						pointer_type;
	typedef value_type&						reference_type;
	typedef ptrdiff_t						difference_type;

	DequeIterator() : i(0), _ptr(nullptr)
	{

	}

	DequeIterator(pointer_type ptr) : i(0), _ptr(ptr)
	{
	}

	DequeIterator(pointer_type ptr, unsigned int len) : i(len), _ptr(ptr)
	{
	}

	unsigned int getI()
	{
		return i;
	}

	DequeIterator&	operator++()
	{
		++i;
		return *this;
	}

	DequeIterator	operator++(int)
	{
		DequeIterator iterator = *this;
		++(*this);
		return iterator;
	}

	DequeIterator	operator+(difference_type v)
	{	
		return DequeIterator(_ptr, i + v);
	}

	DequeIterator	operator-(difference_type v)
	{
		return DequeIterator(_ptr, i - v);
	}

	DequeIterator&	operator--()
	{
		--i;
		return *this;
	}

	DequeIterator	operator--(int)
	{
		DequeIterator iterator = *this;
		--(*this);
		return iterator;
	}

	pointer_type	operator->()
	{
		return &(*_ptr)[i];
	}

	reference_type	operator*()
	{
		return _ptr[i];
	}

	bool			operator==(const DequeIterator& other) const
	{
		return i == other.i;
	}

	bool			operator!=(const DequeIterator& other) const
	{
		return i != other.i;
	}

	DequeIterator&	operator=(const DequeIterator& src)
	{
		i = src.i;
		_ptr = src._ptr;
		return *this;
	}

	/*
	operators miissing 
	+=
	-=

	*/

private:
	pointer_type	_ptr;
	unsigned int 	i;
};

template<typename T>
class Deque
{
public:

	typedef T									value_type;
	typedef T&									reference;
	typedef const T&							const_reference;
	typedef T*									pointer;
	typedef const T*							const_pointer;
	typedef DequeIterator<Deque<T> >			iterator;
	typedef const DequeIterator<Deque<T> >		const_iterator;
	typedef DequeIterator<Deque<T> >			reverse_iterator;
	typedef const DequeIterator<Deque<T> >		const_reverse_iterator;
	typedef ptrdiff_t							difference_type;
	typedef size_t								size_type;
private:
	T				*_items;
	unsigned int	_top;
	size_type		_cap;

	void	re_alloc_items(size_type n = 0)
	{
		size_type sz = n ? n : _cap * 2;
		T *tmp = _items;
		if (n)
		{
			std::cout << tmp[0] << std::endl;
			std::cout << _items[0] << std::endl;
		}
		_items = new T[sz];
		for(size_type i = 0; i < _cap; i++)
			_items[i] = tmp[i];
		delete[] tmp;
		_cap = sz;
	}

public:
	
	Deque() : _size(0)
	{
	}

	Deque(Deque<T> const &src)
	{

	}

	virtual ~Deque()
	{
		clear();
		delete[] _items;
	}

	//tested 0
	iterator			begin()
	{
		return iterator(_items);
	}

	//tested 0
	const_iterator		begin() const
	{
		return iterator(_items);
	}

	//tested 0
	iterator			end()
	{
		return iterator(_items, _top);
	}

	//tested 0
	const_iterator		end() const
	{
		return iterator(_items, _top);
	}

	//tested 0
	reverse_iterator	rbegin()
	{
		return iterator(_items, _top);
	}

	//tested 0
	reverse_iterator	rend()
	{
		return iterator(_items);
	}
	
	//tested 0
	bool				empty() const
	{
		return _top == 0;
	}

	//tested 0
	size_type			size() const
	{
		return _top;
	}

	// not done
	//tested 0
	size_type			max_size() const
	{
		long long size;
		#ifdef __x86_64
			size = pow(2, 64) / sizeof(Node<T>) - 1;
		#else
		#ifdef _M_AMD64
			size = pow(2, 64) / sizeof(Node<T>) - 1;
		#else
			size = pow(2, 32) / sizeof(Node<T>) - 1;
		#endif
		#endif
		return size;
	}

	//exception
	reference		at(size_type n)
	{
		// if (n > _top)
			// throw exception();
		return _items[n];
	}

	//tested 0
	const_reference at(size_type n) const
	{
		return at(n);
	}

	//tested 0
	reference			front()
	{
		return _items[0];
	}

	//tested 0
	const_reference		front() const
	{
		return _items[0];
	}

	//tested 0
	reference			back()
	{
		return _items[_top - 1];
	}

	//tested 0
	const_reference		back() const
	{
		return _items[_top - 1];
	}

	//tested 1
	void 				assign(size_type n, const value_type& val)
	{
		clear();
		for((void)first; first != last; ++first)
			push_back(*first);
	}

	//tested 1
 	void				assign(iterator first, iterator last)
	{
		clear();
		for(size_type i = 0; i < n; i++)
			push_back(val);
	}

	//tested 1
	void				push_front(const T& val)
	{
	}

	//tested 1
	void				push_back(const T& val)
	{
		if (_top == _cap)
			re_alloc_items();
		_items[_top++] = val;
	}

	//tested 1
	void				pop_front()
	{
	}

	//tested 1
	void				pop_back()
	{
		if (_top > 0)
			_top--;
	}

	//tested 1
	iterator 			insert(iterator position, const value_type& val)
	{
		if (_top + 1 == _cap)
			re_alloc_items();
		for(iterator it = rbegin(); it != position; --it)
			*it = *(it - 1);
		*position = val;
		_top++;
		position++;
		return iterator(position);
	}

	//tested 1
	void				insert(iterator position, size_type n, const value_type& val)
	{
		for (size_t i = 0; i < n; i++)
			insert(position, val);
	}

	//tested 1
	void				insert(iterator position, iterator first, iterator last)
	{
		for((void)first; first != last; ++first)
		{
			for(iterator it = rbegin(); it != position; --it)
				*it = *(it - 1);
			*position = *first;
			position++;
			_top++;
		}
	}

	//tested 0  just removed the reference, must be checked again
	iterator			erase(iterator position)
	{
		for(iterator it = position; it != end(); ++it)
			*it = *(it + 1);
		pop_back();
		return iterator(position);
	}

	//tested 1 (test weird shit with this)
	iterator			erase(iterator first, iterator last)
	{
		iterator position;
		position = first;
		for((void)first; first != last; ++first)
			position = erase(position);
		return iterator(position);
	}

	//tested 1
	void 				swap(Deque<T>& x)
	{
		Vector<T> tmp;

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
	}

	//tested 1
	void				clear()
	{
		size_type total = _top;
		for (size_type i = 0; i < total; i++)
			pop_back();
	}

	//tested 1
	T&	operator[](int i) const
	{
		if (i >= _top)
		{
			std::cout << "Index out of bounds" << std::endl; 
			//exception to throw
		}
		return _items[i];
	}

	//tested 0
	Deque<T>&		operator=(const Deque<T>& lhs)
	{
		// clear();
		// for (Deque<T>::iterator it = lhs.begin(); it != lhs.end(); ++it)
		// 	push_back(*it);
		// return *this;
	}
};

}

#endif