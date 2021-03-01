#ifndef STACK_HPP
#define STACK_HPP

#include "List.hpp"

namespace ft
{

	template <typename T, class Container = ft::List<T> >
	class Stack
	{
	public:
		typedef Container container_type;
		typedef T value_type;
		typedef size_t size_type;

		container_type c;

		Stack()
		{
		}

		//tested 1
		Stack(const Stack<T> &src)
		{
			this->c = src.c;
		}

		virtual ~Stack()
		{
		}

		//tested 1
		bool empty()
		{
			return this->c.empty();
		}

		//tested 1
		size_t size()
		{
			return this->c.size();
		}

		//tested 1
		T &top()
		{
			return this->c.back();
		}

		//tested 1
		void push(const T &item)
		{
			this->c.push_front(item);
		}

		//tested 1
		void pop()
		{
			this->c.pop_back();
		}

		//tested 1
		Stack<T> &operator=(const Stack<T> &lhs)
		{
			this->c = lhs.c;
			return *this;
		}
	};

	template <typename value, typename container>
	bool operator==(const Stack<value, container> &lhs, const Stack<value, container> &rhs)
	{
		return lhs.c == rhs.c;
	}

	template <typename value, typename container>
	bool operator>=(const Stack<value, container> &lhs, const Stack<value, container> &rhs)
	{
		return lhs.c >= rhs.c;
	}

	template <typename value, typename container>
	bool operator>(const Stack<value, container> &lhs, const Stack<value, container> &rhs)
	{
		return lhs.c > rhs.c;
	}

	template <typename value, typename container>
	bool operator<=(const Stack<value, container> &lhs, const Stack<value, container> &rhs)
	{
		return lhs.c <= rhs.c;
	}

	template <typename value, typename container>
	bool operator<(const Stack<value, container> &lhs, const Stack<value, container> &rhs)
	{
		return lhs.c < rhs.c;
	}

	template <typename value, typename container>
	bool operator!=(const Stack<value, container> &lhs, const Stack<value, container> &rhs)
	{
		return lhs.c != rhs.c;
	}

}
#endif