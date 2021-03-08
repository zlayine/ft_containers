#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

namespace ft
{

	template <typename T>
	class TreeNode
	{
	public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;
		TreeNode<T> *parent;

		TreeNode(T const & data = T()) : data(data), left(nullptr), right(nullptr), parent(nullptr)
		{
		}

		TreeNode(T data, TreeNode<T> *parent) : data(data), left(nullptr), right(nullptr), parent(parent)
		{
		}
	};

	template <typename T, typename N>
	class TreeIterator
	{
	public:
		typedef T value_type;
		typedef T *pointer_type;
		typedef const T *const_pointer;
		typedef T &reference_type;
		typedef const T &const_reference;
		typedef TreeNode<T> *node_type;
		typedef N *node_pointer;
		typedef ptrdiff_t difference_type;

		TreeIterator() : _ptr(nullptr)
		{
		}

		TreeIterator(TreeIterator const &src) : _ptr(src._ptr)
		{
		}

		TreeIterator(node_pointer ptr) : _ptr(ptr)
		{
		}

		node_pointer get_node() const
		{
			return _ptr;
		}

		TreeIterator &operator++()
		{
			_ptr = next();
			return *this;
		}

		TreeIterator operator++(int)
		{
			TreeIterator iterator = *this;
			++(*this);
			return iterator;
		}

		TreeIterator operator+(difference_type v)
		{
			node_pointer tmp;
			tmp = _ptr;
			while (v--)
				tmp = next();
			return TreeIterator(tmp);
		}

		TreeIterator operator-(difference_type v)
		{
			node_pointer tmp;
			tmp = _ptr;
			while (v--)
				tmp = previous();
			return TreeIterator(tmp);
		}

		TreeIterator &operator--()
		{
			_ptr = previous();
			return *this;
		}

		TreeIterator operator--(int)
		{
			TreeIterator iterator = *this;
			--(*this);
			return iterator;
		}

		pointer_type operator->()
		{
			return &_ptr->data;
		}

		reference_type operator*()
		{
			return _ptr->data;
		}

		bool operator==(const TreeIterator &other) const
		{
			return _ptr == other._ptr;
		}

		bool operator!=(const TreeIterator &other) const
		{
			return _ptr != other._ptr;
		}


		TreeIterator &operator=(const TreeIterator &src)
		{
			_ptr = src._ptr;
			return *this;
		}

	protected:
		node_pointer _ptr;

	private:
		node_pointer next()
		{
			TreeNode<T> *curr;
			TreeNode<T> *last;

			curr = _ptr;
			if (curr->right)
			{
				curr = curr->right;
				while (curr->left)
					curr = curr->left;
				return curr;
			}
			else
			{
				while (curr->parent)
				{
					last = curr;
					curr = curr->parent;
					if (curr->right != last)
						return curr;
				}
			}
			return nullptr;
		}

		node_pointer previous()
		{
			TreeNode<T> *curr;
			TreeNode<T> *last;

			curr = _ptr;
			if (curr->left)
			{
				curr = curr->left;
				while (curr->right)
					curr = curr->right;
				return curr;
			}
			else
			{
				while (curr->parent)
				{
					last = curr;
					curr = curr->parent;
					if (curr->right == last)
						return curr;
				}
			}
			return nullptr;
		}
	};

	template <typename T, typename Compare>
	class Tree
	{
	private:
		TreeNode<T> *root;
		TreeNode<T> *head;
		TreeNode<T> *tail;
		Compare cmp;

	public:
		typedef T value_type;
		typedef TreeNode<T> node_type;
		typedef node_type *node_pointer;

		Tree()
		{
			root = NULL;
			head = tail = new TreeNode<T>();
		}

		Tree(Tree const &src) : root(src.root), head(src.head), tail(src.tail), cmp(src.cmp)
		{
		}

		~Tree()
		{
			destroyTree();
			delete tail;
		}

		node_pointer getHead()
		{
			return head;
		}

		node_pointer getTail()
		{
			return tail;
		}

		void insertNode(value_type data)
		{
			if (root != nullptr)
				insertNode(data, root);
			else
				root = new TreeNode<T>(data);
			reset_edges();
		}

		node_pointer searchNode(value_type data)
		{
			return searchNode(data, root);
		}

		void deleteNode(value_type data)
		{
			root = deleteNode(data, root);
			reset_edges();
			if (root == tail)
				root = nullptr;
		}

		void destroyTree()
		{
			destroyTree(root);
			root = nullptr;
			head = tail;
		}

		void print_tree()
		{
			print_tree(root);
		}

	private:
		void reset_edges()
		{
			node_pointer tmp = root;
			if (!root)
				return;
			while (tmp->left)
				tmp = tmp->left;
			head = tmp;
			tmp = root;
			while (tmp->right)
				tmp = tmp->right;
			if (tmp == tail)
				tmp = tmp->parent;
			else
				tmp->right = tail;
			tail->parent = tmp;
		}

		void insertNode(value_type data, node_pointer leaf)
		{
			if (cmp(data, leaf->data))
			{
				if (leaf->left)
					insertNode(data, leaf->left);
				else
					leaf->left = new TreeNode<T>(data, leaf);
			}
			else
			{
				if (leaf->right && leaf->right != tail)
					insertNode(data, leaf->right);
				else
					leaf->right = new TreeNode<T>(data, leaf);
			}
		}

		node_pointer minValueNode(node_pointer node)
		{
			node_pointer current = node;

			while (current && current->left != NULL)
				current = current->left;
			return current;
		}

		node_pointer deleteNode(value_type data, node_pointer leaf)
		{
			if (leaf == nullptr)
				return leaf;
			if (cmp(data, leaf->data))
				leaf->left = deleteNode(data, leaf->left);
			else if (data.first > leaf->data.first)
				leaf->right = deleteNode(data, leaf->right);
			else
			{
				if (leaf->left == nullptr)
				{
					node_pointer tmp = leaf->right;
					if (tmp)
						tmp->parent = leaf->parent;
					delete leaf;
					return tmp;
				}
				else if (leaf->right == nullptr)
				{
					node_pointer tmp = leaf->left;
					if (tmp)
						tmp->parent = leaf->parent;
					delete leaf;
					return tmp;
				}
			
				node_pointer succParent = leaf;

				node_pointer succ = leaf->right;
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

		node_pointer searchNode(value_type data, node_pointer leaf)
		{
			if (leaf)
			{
				if (leaf->data.first == data.first)
				{
					return leaf;
				}
				else if (cmp(data, leaf->data))
					return searchNode(data, leaf->left);
				else
					return searchNode(data, leaf->right);
			}
			else
				return nullptr;
		}

		void print_tree(node_pointer leaf)
		{
			if (leaf)
			{
				std::cout << "data: " << leaf->data.first << std::endl;
				print_tree(leaf->left);
				print_tree(leaf->right);
			}
		}

		void destroyTree(node_pointer leaf)
		{
			if (leaf && leaf != tail)
			{
				destroyTree(leaf->left);
				destroyTree(leaf->right);
				delete leaf;
			}
		}
	};

}

#endif