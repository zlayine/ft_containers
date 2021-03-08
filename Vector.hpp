#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "ReverseIterator.hpp"
#include <cmath>

namespace ft
{
	template <typename Vector>
	class VectorIterator
	{
	public:
		typedef typename Vector::value_type value_type;
		typedef value_type *pointer_type;
		typedef value_type &reference_type;
		typedef ptrdiff_t difference_type;

		VectorIterator() : _ptr(nullptr), i(0)
		{
		}

		VectorIterator(VectorIterator const &src) : _ptr(src._ptr), i(src.i)
		{
		}

		VectorIterator(pointer_type ptr) : _ptr(ptr), i(0)
		{
		}

		VectorIterator(pointer_type ptr, unsigned int len) : _ptr(ptr), i(len)
		{
		}

		virtual ~VectorIterator()
		{
		}

		unsigned int getI()
		{
			return i;
		}

		VectorIterator &operator++()
		{
			++i;
			return *this;
		}

		VectorIterator operator++(int)
		{
			VectorIterator iterator = *this;
			++(*this);
			return iterator;
		}

		VectorIterator operator+(difference_type v)
		{
			return VectorIterator(_ptr, i + v);
		}

		VectorIterator operator-(difference_type v)
		{
			return VectorIterator(_ptr, i - v);
		}

		VectorIterator &operator--()
		{
			--i;
			return *this;
		}

		VectorIterator operator--(int)
		{
			VectorIterator iterator = *this;
			--(*this);
			return iterator;
		}

		pointer_type operator->()
		{
			return &(*_ptr)[i];
		}

		reference_type operator*()
		{
			return _ptr[i];
		}

		bool operator==(const VectorIterator &other) const
		{
			return i == other.i;
		}

		bool operator!=(const VectorIterator &other) const
		{
			return i != other.i;
		}

		VectorIterator &operator=(const VectorIterator &src)
		{
			i = src.i;
			_ptr = src._ptr;
			return *this;
		}

	protected:
		pointer_type _ptr;
		unsigned int i;
	};

	template <typename T>
	class Vector
	{

	public:
		typedef T value_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef VectorIterator<Vector<T> > iterator;
		typedef const VectorIterator<Vector<T> > const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef const ReverseIterator<iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		T *_items;
		size_type _top;
		size_type _cap;

		void re_alloc_items(size_type n = 0)
		{
			size_type sz = n ? n : _cap * 2;
			if (_items)
			{
				T *tmp = _items;
				_items = new T[sz];
				for (size_type i = 0; i < _cap; i++)
					_items[i] = tmp[i];
				delete[] tmp;
			}
			_cap = sz;
		}

	public:
		Vector() : _top(0), _cap(1)
		{
			_items = new T[1];
		}

		Vector(Vector const &src) : _top(0), _cap(0)
		{
			_items = nullptr;
			this->reserve(src._cap);
			_items = new T[1];
			assign(src.begin(), src.end());
		}

		virtual ~Vector()
		{
			clear();
			delete[] _items;
		}

		iterator begin()
		{
			return iterator(_items);
		}

		const_iterator begin() const
		{
			return iterator(_items);
		}

		iterator end()
		{
			return iterator(_items, _top);
		}

		const_iterator end() const
		{
			return iterator(_items, _top);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(_items, _top);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(_items);
		}

		bool empty() const
		{
			return _top == 0;
		}

		size_t size() const
		{
			return _top;
		}

		size_type max_size() const
		{
			return std::numeric_limits<size_type>::max() / sizeof(value_type);
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n < _top)
			{
				size_type total = _top;
				for (size_type i = n; i < total; i++)
					pop_back();
			}
			else if (n > _top)
			{
				for (size_type i = _top; i < n; i++)
					push_back(val);
			}
		}

		size_type capacity() const
		{
			return _cap;
		}

		void reserve(size_type n)
		{
			if (n > _cap)
				re_alloc_items(n);
		}

		reference at(size_type n)
		{
			if (n > _top || n < 0)
				throw std::out_of_range("Index out of range");
			return _items[n];
		}

		const_reference at(size_type n) const
		{
			if (n > _top || n < 0)
				throw std::out_of_range("Index out of range");
			return at(n);
		}

		reference front()
		{
			return _items[0];
		}

		const_reference front() const
		{
			return _items[0];
		}

		reference back()
		{
			return _items[_top - 1];
		}

		const_reference back() const
		{
			return _items[_top - 1];
		}

		void assign(iterator first, iterator last)
		{
			clear();
			for ((void)first; first != last; ++first)
				push_back(*first);
		}

		void assign(size_type n, const value_type &val)
		{
			clear();
			for (size_type i = 0; i < n; i++)
				push_back(val);
		}

		void push_back(const value_type &val)
		{
			if (_top == _cap)
				re_alloc_items();
			_items[_top++] = val;
		}

		void pop_back()
		{
			if (_top > 0)
				_top--;
		}

		iterator insert(iterator position, const value_type &val)
		{
			if (_top + 1 == _cap)
				re_alloc_items();
			for (iterator it = rbegin(); it != position; --it)
				*it = *(it - 1);
			*position = val;
			_top++;
			return iterator(position);
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			for (size_t i = 0; i < n; i++)
				insert(position, val);
		}

		void insert(iterator position, iterator first, iterator last)
		{
			for ((void)first; first != last; ++first)
			{
				for (iterator it = rbegin(); it != position; --it)
					*it = *(it - 1);
				*position = *first;
				position++;
				_top++;
			}
		}

		iterator erase(iterator position)
		{
			for (iterator it = position; it != end(); ++it)
				*it = *(it + 1);
			pop_back();
			return iterator(position);
		}

		iterator erase(iterator first, iterator last)
		{
			int returnPosition = 0;
			for (iterator it = begin(); it != first; ++it)
				returnPosition++;
			iterator position;
			position = first;
			for ((void)first; first != last; ++first)
				erase(position);
			return iterator(&this->_items[returnPosition]);
		}

		void swap(Vector<T> &x)
		{
			Vector<T> tmp;

			tmp = x;
			x.clear();
			for (iterator it = begin(); it != end(); ++it)
				x.push_back(*it);
			clear();
			for (iterator it = tmp.begin(); it != tmp.end(); ++it)
				push_back(*it);
		}

		void clear()
		{
			size_type total = _top;
			for (size_type i = 0; i < total; i++)
				pop_back();
		}

		T &operator[](int i) const
		{
			if (static_cast<size_type>(i) >= _top || i < 0)
				throw std::out_of_range("Index out of range");
			return _items[i];
		}

		Vector<T> &operator=(const Vector<T> &rhs)
		{
			if (_top)
				delete[] _items;
			_items = new T[rhs._cap];
			_top = rhs._top;
			_cap = rhs._cap;
			for (size_type i = 0; i < _top; i++)
				_items[i] = rhs._items[i];
			return *this;
		}
	};

	template <typename T>
	bool operator==(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (rhs.size() > lhs.size() || rhs.size() < lhs.size())
			return false;
		if (rhs.size() == 0)
			return true;
		for (size_t i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] != lhs[i])
				return false;
		}
		return true;
	}

	template <typename T>
	bool operator>=(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (lhs.size() < rhs.size())
			return false;
		if ((rhs.size() == 0 && lhs.size() == 0) || rhs.size() < lhs.size())
			return true;
		for (size_t i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] > lhs[i])
				return false;
			else if (rhs[i] < lhs[i])
				return true;
		}
		return true;
	}

	template <typename T>
	bool operator>(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (lhs.size() < rhs.size() || (rhs.size() == 0 && lhs.size() == 0))
			return false;
		if (rhs.size() < lhs.size())
			return true;
		for (size_t i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] > lhs[i])
				return false;
			else if (rhs[i] < lhs[i])
				return true;
		}
		return false;
	}

	template <typename T>
	bool operator<=(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (rhs.size() < lhs.size())
			return false;
		if ((rhs.size() == 0 && lhs.size() == 0) || lhs.size() < rhs.size())
			return true;
		for (size_t i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] < lhs[i])
				return false;
			else if (rhs[i] > lhs[i])
				return true;
		}
		return true;
	}

	template <typename T>
	bool operator<(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (rhs.size() < lhs.size() || (lhs.size() == 0 && rhs.size() == 0))
			return false;
		if (lhs.size() < rhs.size())
			return true;
		for (size_t i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] < lhs[i])
				return false;
			else if (rhs[i] > lhs[i])
				return true;
		}
		return false;
	}

	template <typename T>
	bool operator!=(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (rhs.size() > lhs.size() || rhs.size() < lhs.size())
			return true;
		if (rhs.size() == 0)
			return false;
		for (size_t i = 0; i < rhs.size(); i++)
		{
			if (rhs[i] != lhs[i])
				return true;
		}
		return false;
	}
} // namespace ft

#endif