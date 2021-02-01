#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "List.hpp"

namespace ft {

template< typename T, class Container = List<T> >
class Queue
{
public:
	typedef Container	container_type;
	typedef T			value_type;
	typedef size_t		size_type;
private:
	container_type c;
public:
	Queue()
	{

	}

	//tested 0
	Queue(const Queue<T>& src)
	{
		
	}

	~Queue()
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
	T&				front()
	{
		return this->c.front();
	}

	//tested 0
	T&				back()
	{
		return this->c.back();
	}

	//tested 0
	void 			push(const T& item)
	{
		this->c.push_back(item);
	}

	//tested 0
	void 			pop()
	{
		this->c.pop_front();
	}

	Queue<T>&		operator=(const Queue<T>& lhs)
	{
		this->c = lhs.c;
		return *this;
	}


	//tested 0
	template<typename value, typename container>
	friend bool			operator==(const Queue<value, container>& lhs, const Queue<value, container>& rhs)
	{
		return lhs.c == rhs.c;
	}

	//tested 0
	template<typename value, typename container>
	friend bool			operator>=(const Queue<value, container>& lhs, const Queue<value, container>& rhs)
	{
		return !(lhs.c < rhs.c);
	}

	//tested 0
	template<typename value, typename container>
	friend bool			operator>(const Queue<value, container>& lhs, const Queue<value, container>& rhs)
	{
		return lhs.c > rhs.c;
	}

	//tested 0
	template<typename value, typename container>
	friend bool			operator<=(const Queue<value, container>& lhs, const Queue<value, container>& rhs)
	{
		return !(lhs.c > rhs.c);
	}

	//tested 0
	template<typename value, typename container>
	friend bool			operator<(const Queue<value, container>& lhs, const Queue<value, container>& rhs)
	{
		return (rhs.c > lhs.c);
	}

	//tested 0
	template<typename value, typename container>
	friend bool			operator!=(const Queue<value, container>& lhs, const Queue<value, container>& rhs)
	{
		return lhs.c != rhs.c;
	}
};

}

#endif