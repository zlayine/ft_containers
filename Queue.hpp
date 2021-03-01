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

		//tested 1
		Queue(const Queue<T> &src)
		{
			this->c = src.c;
		}

		virtual ~Queue()
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
		T &front()
		{
			return this->c.front();
		}

		//tested 1
		T &back()
		{
			return this->c.back();
		}

		//tested 1
		void push(const T &item)
		{
			this->c.push_back(item);
		}

		//tested 1
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
	
	//tested 1
	template <typename value, typename container>
	bool operator==(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return lhs.c == rhs.c;
	}

	//tested 1
	template <typename value, typename container>
	bool operator>=(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return !(lhs.c < rhs.c);
	}

	//tested 1
	template <typename value, typename container>
	bool operator>(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return lhs.c > rhs.c;
	}

	//tested 1
	template <typename value, typename container>
	bool operator<=(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return !(lhs.c > rhs.c);
	}

	//tested 1
	template <typename value, typename container>
	bool operator<(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return (rhs.c > lhs.c);
	}

	//tested 1
	template <typename value, typename container>
	bool operator!=(const Queue<value, container> &lhs, const Queue<value, container> &rhs)
	{
		return lhs.c != rhs.c;
	}
}

#endif