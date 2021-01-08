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
	bool 			pop();

	T&				operator[](int i)
	bool			operator>=(const Stack<T>& lhs, const Stack<T>& rhs);
	bool			operator>(const Stack<T>& lhs, const Stack<T>& rhs);
	bool			operator<=(const Stack<T>& lhs, const Stack<T>& rhs);
	bool			operator<(const Stack<T>& lhs, const Stack<T>& rhs);
	bool			operator!=(const Stack<T>& lhs, const Stack<T>& rhs);
	bool			operator==(const Stack<T>& lhs, const Stack<T>& rhs);
	bool			operator=(const Stack<T>& lhs);

};

template< typename T>
Stack<T>::Stack()
{
	top = 0;
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
	if (_top)
		return _items[_top - 1];
	else
		return NULL;
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
T&	Stack<T>::operator[](int i)
	{
		if (i >= len)
		{
			std::cout << "Index out of bounds" << std::endl; 
			//exception to throw
		}
		return array[i];
}

#endif