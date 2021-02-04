#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

template<typename Iterator>
class ReverseIterator : public Iterator
{
public:
    using typename Iterator::value_type;
    using typename Iterator::pointer_type;
    using typename Iterator::reference_type;
    using typename Iterator::difference_type;

    ReverseIterator()
    {

    }

    ReverseIterator(Iterator const &it) : Iterator(it)
    {

    }

    ReverseIterator(ReverseIterator const &src) : Iterator(src._ptr)
    {
    }

    ~ReverseIterator() 
    {

    }

    ReverseIterator&    operator=(ReverseIterator const &rhs)
    {
        this->_ptr = rhs._ptr;
        return *this;
    }

    reference_type  operator*()
    {
        Iterator it(*this);
        return *--it;
    }

    pointer_type    operator->()
    {
        Iterator it(*this);
        return &*--it;
    }

    ReverseIterator&    operator++()
    {

    }

    ReverseIterator     operator++(int)
    {

    }

    ReverseIterator&    operator--()
    {

    }

    ReverseIterator     operator--(int)
    {
        
    }

};

#endif