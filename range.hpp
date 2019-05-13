namespace itertools
{

template <class T>

class range
{

private:
    T start; // start
    T fin;   // end

    class iterator
    {

    public:
  
        T t_val;
        iterator(T itr) : t_val(itr){}

        bool operator!=(range::iterator const &other) const
        { 
            return t_val != (other.t_val);
        }

        T operator*() const
        {
            return t_val;
        }

        range::iterator &operator++()
        {
            ++t_val;
            return *this;
        }
    };

public:
    range(T from, T to) : start(from), fin(to) {}                     
    range::iterator begin() const { return _range::iterator(start); } 
    range::iterator end() const { return _range::iterator(fin); }      
}; 

    
template <typename T>

range<T> range(T from, T to)
{
    return range<T>(from, to);
}

} 
