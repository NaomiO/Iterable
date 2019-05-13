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
        bool operator!=(range::iterator const &other) const
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
    range(T from, T to) : _from(from), _to(to) {}                      // constructor
    range::iterator begin() const { return range::iterator(_from); }  // iteratable object
    range::iterator end() const { return range::iterator(_to); }      // iteratable object
}; // class



template <typename T>
/*
* range function, use in loops to iterate between two values.
* Example use case: 
* for(int i : range(1,5))
*   // do somethin...
*/
range<T> range(T from, T to)
{
    return range<T>(from, to);
}
}    
