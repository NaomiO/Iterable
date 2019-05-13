namespace itertools
{

template <class T>

class _range
{

private:
    T start; // start
    T fin;   // end

    class iterator
    {

    public:
  
        T t_val;
        iterator(T itr) : t_val(itr){}

        bool operator!=(_range::iterator const &other) const
        { 
            return t_val != (other.t_val);
        }

        T operator*() const
        {
            return t_val;
        }

        _range::iterator &operator++()
        {
            ++t_val;
            return *this;
        }
    };

public:
    _range(T from, T to) : start(from), fin(to) {}                     
    _range::iterator begin() const { return _range::iterator(start); } 
    _range::iterator end() const { return _range::iterator(fin); }      
}; 

    
template <typename T>

_range<T> range(T from, T to)
{
    return _range<T>(from, to);
}

} 
