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

	Node(T data, Node<T>* nx) : data(data), next(nx), prev(nx->prev)
	{
		if (nx->prev)
			nx->prev->next = this;
		nx->prev = this;
	}
};

#endif