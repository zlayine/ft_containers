#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"

namespace ft
{

	template <typename T, class Container = List<T> >
	class Queue
	{
	public:
		typedef Container container_type;
		typedef T value_type;
		typedef size_t size_type;

		container_type c;

		Queue()
		{
		}

		Queue(const Queue<T> &src)
		{
			this->c = src.c;
		}

		virtual ~Queue()
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

		T &front()
		{
			return this->c.front();
		}

		T &back()
		{
			return this->c.back();
		}

		void push(const T &item)
		{
			this->c.push_back(item);
		}

		void pop()
		{
			this->c.pop_front();
		}

		Queue<T> &operator=(const Queue<T> &lhs)
		{
			this->c = lhs.c;
			return *this;
		}
	};

	template <typename value, typename container>
	bool operator==(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return lhs.c == rhs.c;
	}
	template <typename value, typename container>
	bool operator>=(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return !(lhs.c < rhs.c);
	}
	template <typename value, typename container>
	bool operator>(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return lhs.c > rhs.c;
	}
	template <typename value, typename container>
	bool operator<=(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return !(lhs.c > rhs.c);
	}
	template <typename value, typename container>
	bool operator<(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return (rhs.c > lhs.c);
	}
	template <typename value, typename container>
	bool operator!=(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return lhs.c != rhs.c;
	}
}

#endif