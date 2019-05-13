#pragma once
namespace itertools
{
template <class T>

class range
{

private:
    T _from; // starting point
    T _to;   // stopping point.

    class iterator
    {

    public:
        // variables
        T val;

        //constructor
        iterator(T vall) : val(vall){}

        // operators
        bool operator!=(_range::iterator const &other) const
        { 
            return val != (other.val);
        }

        T operator*() const
        {
            return val;
        }


        _range::iterator &operator++()
        {

            ++val;
            return *this;
        }
    };

public:
    _range(T from, T to) : _from(from), _to(to) {}                      // constructor
    _range::iterator begin() const { return _range::iterator(_from); }  // iteratable object
    _range::iterator end() const { return _range::iterator(_to); }      // iteratable object
}; // class



template <typename T>
/*
* range function, use in loops to iterate between two values.
* Example use case: 
* for(int i : range(1,5))
*   // do somethin...
*/
_range<T> range(T from, T to)
{
    return _range<T>(from, to);
}
}    
