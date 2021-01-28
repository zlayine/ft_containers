#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
// #include "Map.hpp";

template<typename T>
class TreeNode
{
public:
    T			data;
    TreeNode<T>		*left;
    TreeNode<T>		*right;

	TreeNode() : left(nullptr), right(nullptr)
	{
		data = 0;
	}

	TreeNode(T data) : data(data), left(nullptr), right(nullptr)
	{
	}
};

template<typename T, typename N>
class TreeIterator
{
public:
	typedef T		value_type;
	typedef T*		pointer;
	typedef const T* const_pointer;
	typedef T&		reference;
	typedef const T& const_reference;
	typedef N		node_type;
	typedef	N*		node_pointer;

	TreeIterator() : _ptr(nullptr)
	{
	}

	TreeIterator(node_pointer ptr) : _ptr(ptr)
	{
	}

	node_pointer	get_node() const
	{
		return _ptr;
	}

	TreeIterator&	operator++
	{
		
	}

private:
	node_pointer	_ptr;

};

template<typename T, typename Compare>
class Tree
{
private:
	TreeNode<T>	*root;
	TreeNode<T>	*head;
	TreeNode<T>	*tail;
	Compare		cmp;
public:
    Tree()
	{
		root = NULL;
	}

    ~Tree()
	{
		destroyTree();
	}

	void	insertNode(int data)
	{
		if (root != nullptr)
			insertNode(data, root);
		else
			root = new TreeNode<T>(data);
	}

	TreeNode<T>	*searchNode(int data)
	{
		return searchNode(data, root);
	}

	void	deleteNode(int data)
	{
		deleteNode(data, root);
	}

	void	destroyTree()
	{
		destroyTree(root);
	}

	void	print_tree()
	{
		print_tree(root);
		std::cout << "\n";
	}


private:

	void	insertNode(int data, TreeNode<T>* leaf)
	{
		if (cmp(data ,leaf->data))
		{
			if (leaf->left != nullptr)
				insertNode(data, leaf->left);
			else
				leaf->left = new TreeNode<T>(data);
		}
		else
		{
			if (leaf->right != nullptr)
				insertNode(data, leaf->right);
			else
				leaf->right = new TreeNode<T>(data);
		}
	}

	TreeNode<T>* minValueNode(TreeNode<T>* node)
	{
		TreeNode<T>* current = node;
	
		while (current && current->left != NULL)
			current = current->left;
		return current;
	}

	TreeNode<T>	*deleteNode(int data, TreeNode<T> *leaf)
	{
		if (leaf == nullptr)
			return leaf;

		if (cmp(data, leaf->data))
			leaf->left = deleteNode(data, leaf->left);
		else if (cmp(data, leaf->data))
			leaf->right = deleteNode(data, leaf->right);
		else
		{
			if (leaf->left == nullptr)
			{
				TreeNode<T> *tmp = leaf->right;
				delete leaf;
				return tmp;
			}
			else if (leaf->right == nullptr)
			{
				TreeNode<T> *tmp = leaf->left;
				delete leaf;
				return tmp;
			}

			// Simple way to delete
			// TreeNode<T> *tmp = minValueNode(leaf->right);
			// leaf->data = tmp->data;
			// leaf->right = deleteNode(tmp->data, leaf->right);

			//optimized way to delete
			TreeNode<T> *succParent = leaf;

			TreeNode<T> *succ = leaf->right;
			while (succ->left != nullptr)
			{
				succParent = succ;
				succ = succ->left;
			}

			if (succParent != leaf)
				succParent->left = succ->right;
			else
				succParent->right = succ->right;
			leaf->data = succ->data;
			delete succ;
			return leaf;
		}
		return leaf;
	}

	TreeNode<T>	*searchNode(int data, TreeNode<T> *leaf)
	{
		if (leaf != nullptr)
		{
			if (leaf->data == data)
				return leaf;
			else if (data < leaf->data)
				return searchNode(data, leaf->left);
			else
				return searchNode(data, leaf->right);
		}
		else
			return nullptr;
	}

	void	print_tree(TreeNode<T> *leaf)
	{
		if (leaf != nullptr)
		{
			std::cout << leaf->data << std::endl;
			print_tree(leaf->left);
			print_tree(leaf->right);

		}
	}

	void	destroyTree(TreeNode<T> *leaf)
	{
		if (leaf)
		{
			destroyTree(leaf->left);
			destroyTree(leaf->right);
			delete leaf;
		}
	}

};


#endif