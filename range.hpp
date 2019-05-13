namespace itertools
{

template <class T>

class _range
{


private:
    T start; 
    T end;   

    class iterator
    {

    public:
        T val;

        iterator(T it_val) : val(it_val){}

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
    _range(T from, T to) : start(from), end(to) {}                      
    _range::iterator begin() const { return _range::iterator(start); }  
    _range::iterator end() const { return _range::iterator(end); }     
};


template <typename T>

_range<T> range(T from, T to)
{
    return _range<T>(from, to);
}

} // namespace itertools
