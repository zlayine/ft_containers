#ifndef STACK_HPP
# define STACK_HPP

template< typename T>
class Stack
{
private:
	int		_cap;
	T		*_items;
	size_t	_top;

public:
	Stack();
	Stack(const Stack<T>& src);
	~Stack();

	bool 			empty() const;
	size_t			size() const;
	T&				top();
	const T&		top() const;
	void 			push(const T& item);
	void 			pop();

	T&				operator[](int i) const;
	Stack<T>&		operator=(const Stack<T>& lhs);
	bool			operator==(const Stack<T>& rhs);
	bool			operator>=(const Stack<T>& rhs);
	bool			operator>(const Stack<T>& rhs);
	bool			operator<=(const Stack<T>& rhs);
	bool			operator<(const Stack<T>& rhs);
	bool			operator!=(const Stack<T>& rhs);

};


template< typename T>
Stack<T>&		Stack<T>::operator=(const Stack<T>& rhs)
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
bool			Stack<T>::operator==(const Stack<T>& rhs)
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
bool			Stack<T>::operator>=(const Stack<T>& rhs)
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
bool			Stack<T>::operator>(const Stack<T>& rhs)
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
bool			Stack<T>::operator<=(const Stack<T>& rhs)
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
bool			Stack<T>::operator<(const Stack<T>& rhs)
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
bool			Stack<T>::operator!=(const Stack<T>& rhs)
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

template< typename T>
Stack<T>::Stack()
{
	_top = 0;
	_cap = 10;
	_items = new T[_cap];
}

template< typename T>
Stack<T>::~Stack()
{
}

template< typename T>
bool 	Stack<T>::empty() const 
{
	return _top == 0;
}

template< typename T>
size_t	Stack<T>::size() const
{
	return _top;
}

template< typename T>
T&		Stack<T>::top()
{
	return _items[_top - 1];
}

template< typename T>
const T& Stack<T>::top() const
{
	return top();
}

template< typename T>
void	Stack<T>::push(const T& item)
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
void	Stack<T>::pop()
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
T&	Stack<T>::operator[](int i) const
	{
		if (i >= _top)
		{
			std::cout << "Index out of bounds" << std::endl; 
			//exception to throw
		}
		return _items[i];
}

#endif