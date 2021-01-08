#ifndef QUEUE_HPP
# define QUEUE_HPP

#include <iostream>

//copy constructor not done and exceptions
template< typename T>
class Queue
{
private:
	int		_cap;
	T		*_items;
	int		_current;
	size_t	_top;

public:
	Queue();
	Queue(const Queue<T>& src);
	~Queue();

	bool 			empty() const;
	size_t			size() const;
	T&				front();
	const T&		front() const;
	T&				back();
	const T&		back() const;
	void 			push(const T& item);
	void 			pop();

	T&				operator[](int i) const;
	Queue<T>&		operator=(const Queue<T>& lhs);
	bool			operator==(const Queue<T>& rhs);
	bool			operator>=(const Queue<T>& rhs);
	bool			operator>(const Queue<T>& rhs);
	bool			operator<=(const Queue<T>& rhs);
	bool			operator<(const Queue<T>& rhs);
	bool			operator!=(const Queue<T>& rhs);

};

template< typename T>
Queue<T>::Queue()
{
	_top = 0;
	_cap = 10;
	_items = new T[_cap];
}

template< typename T>
Queue<T>::~Queue()
{
}

template< typename T>
bool 	Queue<T>::empty() const 
{
	return _top == 0;
}

template< typename T>
size_t	Queue<T>::size() const
{
	return _top;
}

template< typename T>
T&		Queue<T>::front()
{
	return _items[0];
}

template< typename T>
const T& Queue<T>::front() const
{
	return front();
}

template< typename T>
T&		Queue<T>::back()
{
	return _items[_top - 1];
}

template< typename T>
const T& Queue<T>::back() const
{
	return back();
}

template< typename T>
void	Queue<T>::push(const T& item)
{
	if (_top == _cap)
	{
		T *tmp = _items;
		_cap += 10;
		_items = new T[_cap];
		for(int i = 0; i < _cap - 10; i++)
		{
			_items[i] = tmp[i];
			// delete tmp[i];
		}
		// delete[] tmp;
	}
	_items[_top] = item;
	_top++;
}

template< typename T>
void	Queue<T>::pop()
{
	if (_top > 0)
	{
		_top--;
	}
	if (_top - _cap > 10)
	{
		T *tmp = _items;
		_cap -= 10;
		_items = new T[_cap];
		for(int i = 0; i < _cap; i++)
		{
			_items[i] = tmp[i];
			// delete tmp[i];
		}
		// delete[] tmp;
	}
}


template< typename T>
T&	Queue<T>::operator[](int i) const
	{
		if (i >= _top)
		{
			std::cout << "Index out of bounds" << std::endl; 
			//exception to throw
		}
		return _items[i];
}


template< typename T>
Queue<T>&		Queue<T>::operator=(const Queue<T>& rhs)
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

template< typename T>
bool			Queue<T>::operator==(const Queue<T>& rhs)
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

template< typename T>
bool			Queue<T>::operator>=(const Queue<T>& rhs)
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

template< typename T>
bool			Queue<T>::operator>(const Queue<T>& rhs)
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

template< typename T>
bool			Queue<T>::operator<=(const Queue<T>& rhs)
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

template< typename T>
bool			Queue<T>::operator<(const Queue<T>& rhs)
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

template< typename T>
bool			Queue<T>::operator!=(const Queue<T>& rhs)
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

#endif