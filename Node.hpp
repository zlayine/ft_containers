#ifndef NODE_HPP
#define NODE_HPP

namespace ft
{

	template <typename T>
	class Node
	{
	public:
		T data;
		Node<T> *next;
		Node<T> *prev;

		Node() : next(nullptr), prev(nullptr)
		{
			data = 0;
		}

		Node(T data) : data(data), next(nullptr), prev(nullptr)
		{
		}

		Node(T data, Node<T> *nx, Node<T> *pv) : data(data), next(nx), prev(pv)
		{
		}

		void insert(Node<T> *n)
		{
			n->prev = this->prev;
			n->next = this;
			if (this->prev)
				this->prev->next = n;
			this->prev = n;
		}

		Node<T> *erase()
		{
			Node<T> *n;

			n = this->next;
			if (this->prev)
				this->prev->next = this->next;
			if (this->next)
				this->next->prev = this->prev;
			delete this;
			return n;
		}

		Node<T> &operator=(Node<T> &rhs)
		{
			this->data = rhs->data;
			this->next = rhs->next;
			this->prev = rhs->prev;
			return *this;
		}

		void swap(Node<T> *toswap)
		{
			if (this->next == toswap)
			{
				if (this->prev)
					this->prev->next = toswap;
				toswap->prev = this->prev;
				this->prev = toswap;
				if (toswap->next)
					toswap->next->prev = this;
				this->next = toswap->next;
				toswap->next = this;
			}
			else if (this->prev == toswap)
			{
				if (toswap->prev)
					toswap->prev->next = this;
				this->prev = toswap->prev;
				toswap->prev = this;
				if (this->next)
					this->next->prev = toswap;
				toswap->next = this->next;
				this->next = toswap;
			}
			else
			{
				Node<T> *tprevious = this->prev;
				Node<T> *tnext = this->next;
				if (this->prev)
					this->prev->next = toswap;
				if (this->next)
					this->next->prev = toswap;
				this->prev = toswap->prev;
				this->next = toswap->next;

				if (toswap->prev)
					toswap->prev->next = this;
				if (toswap->next)
					toswap->next->prev = this;
				toswap->prev = tprevious;
				toswap->next = tnext;
			}
		}
	};

}
#endif