#ifndef STACK_HPP
# define STACK_HPP

#include "List.hpp"

template< typename T, class Container = List<T> >
class Stack
{
public:
	typedef Container	container_type;
	typedef T			value_type;
	typedef size_t		size_type;
private:
	container_type c;

public:
	Stack()
	{

	}

	//tested 0
	Stack(const Stack<T>& src)
	{

	}

	~Stack()
	{

	}


	//tested 0
	bool 			empty()
	{
		return this->c.empty();
	}

	//tested 0
	size_t			size()
	{
		return this->c.size();
	}

	//tested 0
	T&				top()
	{
		return this->c.back();
	}

	//tested 0
	void 			push(const T& item)
	{
		this->c.push_front(item);
	}

	//tested 0
	void 			pop()
	{
		this->c.pop_back();
	}

	//tested 0
	Stack<T>&		operator=(const Stack<T>& lhs)
	{
		this->c = lhs.c;
		return *this;
	}
	
	//tested 0
	// template<typename value, typename container>
	// bool			operator==(const Stack<value, container>& lhs, const Stack<value, container>& rhs)
	// {
	// 	return lhs.c == rhs.c;
	// }

	//tested 0
	// template<typename value, typename container>
	// bool			operator>=(const Stack<value, container>& lhs, const Stack<value, container>& rhs)
	// {
	// 	return lhs.c >= rhs.c;
	// }

	//tested 0
	// template<typename value, typename container>
	// bool			operator>(const Stack<value, container>& lhs, const Stack<value, container>& rhs)
	// {
	// 	return lhs.c > rhs.c;
	// }

	//tested 0
	// template<typename value, typename container>
	// bool			operator<=(const Stack<value, container>& lhs, const Stack<value, container>& rhs)
	// {
	// 	return lhs.c <= rhs.c;
	// }

	//tested 0
	// template<typename value, typename container>
	// bool			operator<(const Stack<value, container>& lhs, const Stack<value, container>& rhs)
	// {
	// 	return lhs.c < rhs.c;
	// }

	//tested 0
	// template<typename value, typename container>
	// bool			operator!=(const Stack<value, container>& lhs, const Stack<value, container>& rhs)
	// {
	// 	return lhs.c != rhs.c;
	// }


};


// template< typename T>
// Stack<T>::Stack()
// {
// 	_top = 0;
// 	_items = nullptr;
// }

// template< typename T>
// Stack<T>::~Stack()
// {
// }

// template< typename T>
// bool 	Stack<T>::empty() const 
// {
// 	return _top == 0;
// }

// template< typename T>
// size_t	Stack<T>::size() const
// {
// 	return _top;
// }

// template< typename T>
// T&		Stack<T>::top()
// {
// 	return _items;
// }

// template< typename T>
// const T& Stack<T>::top() const
// {
// 	return top();
// }

// template< typename T>
// void	Stack<T>::push(const T& item)
// {
// 	// if (_top == _cap)
// 	// {
// 	// 	T *tmp = _items;
// 	// 	_cap += 10;
// 	// 	_items = new T[_cap];
// 	// 	for(int i = 0; i < _cap - 10; i++)
// 	// 	{
// 	// 		_items[i] = tmp[i];
// 	// 		// delete tmp[i];
// 	// 	}
// 	// 	// delete[] tmp;
// 	// }
// 	// _items[_top] = item;

// 	Node *n = new Node();
// 	n->data = item;
// 	n->prev = NULL;
// 	n->next = NULL;
// 	if (_items)
// 	{
// 		_items->next = n;
// 		n->prev = _items;
// 		_items = _items->next;
// 	}
// 	else
// 		_items = n;
// 	_top++;
// }

// template< typename T>
// void	Stack<T>::pop()
// {
// 	// if (_top > 0)
// 	// {
// 	// 	_top--;
// 	// }
// 	// if (_top - _cap > 10)
// 	// {
// 	// 	T *tmp = _items;
// 	// 	_cap -= 10;
// 	// 	_items = new T[_cap];
// 	// 	for(int i = 0; i < _cap; i++)
// 	// 	{
// 	// 		_items[i] = tmp[i];
// 	// 		// delete tmp[i];
// 	// 	}
// 	// 	// delete[] tmp;
// 	// }
// }

// template< typename T>
// T&	Stack<T>::operator[](int i) const
// 	{
// 		if (i >= _top)
// 		{
// 			std::cout << "Index out of bounds" << std::endl; 
// 			//exception to throw
// 		}
// 		return _items[i];
// }


// template< typename T>
// Stack<T>&		Stack<T>::operator=(const Stack<T>& rhs)
// {
// 	if (_top)
// 		delete[] _items;
// 	_items = new T[rhs.size()];
// 	_top = rhs.size();
// 	_cap = rhs._cap;
// 	for(int i = 0; i < _top; i++)
// 	{
// 		_items[i] = rhs._items[i];
// 	}
// 	return *this;
// }

// template< typename T>
// bool			Stack<T>::operator==(const Stack<T>& rhs)
// {
// 	if (rhs.size() > this->size() || rhs.size() < this->size())
// 		return false;
// 	if (rhs.size() == 0)
// 		return true;
// 	for(int i = 0; i < rhs.size(); i++)
// 	{
// 		if (rhs[i] != _items[i])
// 			return false;
// 	}
// 	return true;
// }

// template< typename T>
// bool			Stack<T>::operator>=(const Stack<T>& rhs)
// {
// 	if (this->size() < rhs.size())
// 		return false;
// 	if ((rhs.size() == 0 && this->size() == 0) || rhs.size() < this->size())
// 		return true;
// 	for(int i = 0; i < rhs.size(); i++)
// 	{
// 		if (rhs[i] > _items[i])
// 			return false;
// 		else if (rhs[i] < _items[i])
// 			return true;
// 	}
// 	return true;
// }

// template< typename T>
// bool			Stack<T>::operator>(const Stack<T>& rhs)
// {
// 	if (this->size() < rhs.size() || (rhs.size() == 0 && this->size() == 0))
// 		return false;
// 	if (rhs.size() < this->size())
// 		return true;
// 	for(int i = 0; i < rhs.size(); i++)
// 	{
// 		if (rhs[i] > _items[i])
// 			return false;
// 		else if (rhs[i] < _items[i])
// 			return true;
// 	}
// 	return false;
// }

// template< typename T>
// bool			Stack<T>::operator<=(const Stack<T>& rhs)
// {
// 	if (rhs.size() < this->size())
// 		return false;
// 	if ((rhs.size() == 0 && this->size() == 0) || this->size() < rhs.size())
// 		return true;
// 	for(int i = 0; i < rhs.size(); i++)
// 	{
// 		if (rhs[i] < _items[i])
// 			return false;
// 		else if (rhs[i] > _items[i])
// 			return true;
// 	}
// 	return true;
// }

// template< typename T>
// bool			Stack<T>::operator<(const Stack<T>& rhs)
// {
// 	if (rhs.size() < this->size() || (this->size() == 0 && rhs.size() == 0))
// 		return false;
// 	if (this->size() < rhs.size())
// 		return true;
// 	for(int i = 0; i < rhs.size(); i++)
// 	{
// 		if (rhs[i] < _items[i])
// 			return false;
// 		else if (rhs[i] > _items[i])
// 			return true;
// 	}
// 	return false;
// }

// template< typename T>
// bool			Stack<T>::operator!=(const Stack<T>& rhs)
// {
// 	if (rhs.size() > this->size() || rhs.size() < this->size())
// 		return true;
// 	if (rhs.size() == 0)
// 		return false;
// 	for(int i = 0; i < rhs.size(); i++)
// 	{
// 		if (rhs[i] != _items[i])
// 			return true;
// 	}
// 	return false;
// }

#endif