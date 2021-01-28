#ifndef TOOLS_HPP
# define TOOLS_HPP

#include <utility>
#include <functional>

template<typename T>
struct less : public std::binary_function<T, T, bool>
{
	bool operator()(const T& x, const T& y) const
    {
		return (x < y);
	}
};

#endif