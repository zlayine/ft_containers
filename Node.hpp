#ifndef NODE_HPP
# define NODE_HPP

template<typename T>
class Node 
{ 
public:
	T			data; 
	Node<T>*	next; 
	Node<T>*	prev; 

	Node() : next(nullptr), prev(nullptr)
	{
		data = 0;
	}

	Node(T data) : data(data), next(nullptr), prev(nullptr)
	{
	}

	Node(T data, Node<T>* nx, Node<T>* pv) : data(data), next(nx), prev(pv)
	{
	}

	void	insert(Node<T> *n)
	{
		n->prev = this->prev;
		n->next = this;
		if (this->prev)
			this->prev->next = n;
		this->prev = n;
	}

	Node<T>	*erase()
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

	Node<T>&	operator=(Node<T>& rhs)
	{
		this->data = rhs->data;
		this->next = rhs->next;
		this->prev = rhs->prev;
		return *this;
	}
};

#endif