#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

template<typename Vector>
class VectorIterator
{
public:
	typedef typename Vector::value_type		value_type;
	typedef value_type*						pointer_type;
	typedef value_type&						reference_type;
	typedef ptrdiff_t						difference_type;

	VectorIterator() : i(0), _ptr(nullptr)
	{

	}

	VectorIterator(pointer_type ptr) : i(0), _ptr(ptr)
	{
	}

	VectorIterator(pointer_type ptr, unsigned int len) : i(len), _ptr(ptr)
	{
	}

	VectorIterator&	operator++()
	{
		++i;
		return *this;
	}

	VectorIterator	operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	VectorIterator	operator+(difference_type v)
	{	
		return VectorIterator(_ptr + i + v);
	}

	VectorIterator	operator-(difference_type v)
	{
		return VectorIterator(_ptr + i - v);
	}

	VectorIterator&	operator--()
	{
		--i;
		return *this;
	}

	VectorIterator	operator--(int)
	{
		VectorIterator iterator = *this;
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

	bool			operator==(const VectorIterator& other) const
	{
		return i == other.i;
	}

	bool			operator!=(const VectorIterator& other) const
	{
		return i != other.i;
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
class Vector
{

public:
	typedef T									value_type;
	typedef T&									reference;
	typedef const T&							const_reference;
	typedef T*									pointer;
	typedef const T*							const_pointer;
	typedef VectorIterator<Vector<T> >			iterator;
	typedef const VectorIterator<Vector<T> >	const_iterator;
	typedef VectorIterator<Vector<T> >			reverse_iterator;
	typedef const VectorIterator<Vector<T> >	const_reverse_iterator;
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
		_items = new T[sz];
		for(size_type i = 0; i < _cap; i++)
			_items[i] = tmp[i];
		delete[] tmp;
		_cap = sz;
	}

public:

	Vector() : _top(0), _cap(1)
	{
		_items = new T[1];
	}

	~Vector()
	{
	}

	//tested 1
	iterator			begin()
	{
		return iterator(_items);
	}

	//tested 1
	const_iterator		begin() const
	{
		return iterator(_items);
	}

	//tested 1
	iterator			end()
	{
		return iterator(_items, _top);
	}

	//tested 1
	const_iterator		end() const
	{
		return iterator(_items, _top);
	}

	//tested 0
	reverse_iterator	rbgein()
	{
		return iterator(_items, _top);
	}

	//tested 0
	reverse_iterator	rend()
	{
		return iterator(_items);
	}

	//tested 1
	bool 	empty() const 
	{
		return _top == 0;
	}

	//tested 1
	size_t	size() const
	{
		return _top;
	}

	// not done
	//tested 0
	size_type			max_size() const
	{
		return _top;
	}

	void				resize(size_type n, value_type val = value_type())
	{
		if (n < _top)
		{
			size_type 	total = _top;
			for (size_type i = n; i < total; i++)
				pop_back();
		}
		else if (n > _top)
		{
			for (size_type i = _top; i < n; i++)
				push_back(val);
		}
	}

	size_type		capacity() const
	{
		return _cap;
	}

	void			reserve(size_type n)
	{
		if (n > _cap)
			re_alloc_items(n);
	}

	reference		at(size_type n)
	{

	}

	const_reference at(size_type n) const
	{

	}

	reference		front()
	{

	}

	const_reference front() const
	{

	}

	reference		back()
	{

	}

	const_reference back() const
	{

	}

	void				assign(iterator first, iterator last)
	{

	}

	void 				assign(size_type n, const value_type& val)
	{

	}

	void				push_back(const value_type& val)
	{
		if (_top == _cap)
			re_alloc_items();
		_items[_top++] = val;
	}

	// test for if (_top == _cap / 2)
	void				pop_back()
	{
		if (_top > 0)
			_top--;
		if (_top == _cap / 2)
			re_alloc_items();
	}

	//tested 0
	iterator 			insert(iterator &position, const value_type& val)
	{

	}

	//tested 0
	void				insert(iterator &position, size_type n, const value_type& val)
	{

	}

	//tested 0
	void				insert(iterator position, iterator first, iterator last)
	{

	}

	//tested 0
	iterator			erase(iterator& position)
	{

	}

	//tested 0
	iterator			erase(iterator first, iterator last)
	{

	}

	void				swap(Vector& x)
	{

	}


	void				clear()
	{

	}


	T&	operator[](int i) const
	{
		if (i >= _top)
		{
			std::cout << "Index out of bounds" << std::endl; 
			//exception to throw
		}
		return _items[i];
	}


	Vector<T>&		operator=(const Vector<T>& rhs)
	{
		if (_top)
			delete[] _items;
		_items = new T[rhs.size()];
		_top = rhs.size();
		_cap = rhs._cap;
		for(int i = 0; i < _top; i++)
		{
			_items[i] = rhs._items[i];
		}
		return *this;
	}

	bool			operator==(const Vector<T>& rhs)
	{
		if (rhs.size() > this->size() || rhs.size() < this->size())
			return false;
		if (rhs.size() == 0)
			return true;
		for(int i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] != _items[i])
				return false;
		}
		return true;
	}

	bool			operator>=(const Vector<T>& rhs)
	{
		if (this->size() < rhs.size())
			return false;
		if ((rhs.size() == 0 && this->size() == 0) || rhs.size() < this->size())
			return true;
		for(int i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] > _items[i])
				return false;
			else if (rhs[i] < _items[i])
				return true;
		}
		return true;
	}

	bool			operator>(const Vector<T>& rhs)
	{
		if (this->size() < rhs.size() || (rhs.size() == 0 && this->size() == 0))
			return false;
		if (rhs.size() < this->size())
			return true;
		for(int i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] > _items[i])
				return false;
			else if (rhs[i] < _items[i])
				return true;
		}
		return false;
	}

	bool			operator<=(const Vector<T>& rhs)
	{
		if (rhs.size() < this->size())
			return false;
		if ((rhs.size() == 0 && this->size() == 0) || this->size() < rhs.size())
			return true;
		for(int i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] < _items[i])
				return false;
			else if (rhs[i] > _items[i])
				return true;
		}
		return true;
	}

	bool			operator<(const Vector<T>& rhs)
	{
		if (rhs.size() < this->size() || (this->size() == 0 && rhs.size() == 0))
			return false;
		if (this->size() < rhs.size())
			return true;
		for(int i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] < _items[i])
				return false;
			else if (rhs[i] > _items[i])
				return true;
		}
		return false;
	}

	bool			operator!=(const Vector<T>& rhs)
	{
		if (rhs.size() > this->size() || rhs.size() < this->size())
			return true;
		if (rhs.size() == 0)
			return false;
		for(int i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] != _items[i])
				return true;
		}
		return false;
	}
};


#endif