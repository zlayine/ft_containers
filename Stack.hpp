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

		Stack(const Stack<T> &src)
		{
			this->c = src.c;
		}

		virtual ~Stack()
		{
		}

		bool empty()
		{
			return this->c.empty();
		}

		size_t size()
		{
			return this->c.size();
		}

		T &top()
		{
			return this->c.back();
		}

		void push(const T &item)
		{
			this->c.push_front(item);
		}

		void pop()
		{
			this->c.pop_back();
		}

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