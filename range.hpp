namespace itertools
{


template <class T>

class _range
{

private:
    T start; // starting point
    T _to;   // stopping point.

    // Inner class (iterator)
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
    _range(T from, T to) : star(from), _to(to) {}                      // constructor
    _range::iterator begin() const { return _range::iterator(start); }  // iteratable object
    _range::iterator end() const { return _range::iterator(_to); }      // iteratable object
}; // class



template <typename T>

_range<T> range(T from, T to)
{
    return _range<T>(from, to);
}

} // namespace itertools
