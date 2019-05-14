#include <set>
#include <vector>
#include <cmath>
#include <iostream>
namespace itertools
{

template <typename T>
std::ostream &operator<<(std::ostream &stream, const std::vector<V> &vec)
{
    stream << "{";

    auto temp = vec.begin();
    if(temp != vec.end())
    { 
        stream << *temp; 
        ++temp;
    }

    while (temp != vec.end())
    {
        stream << ',' << *temp;
        ++temp;
    }

    stream << "}";
    return stream;
    
}

template <class T>

class powerset
{

private:
    T from; 
    template <class E>
    
    class iterator
    {

    public:

        E _element_iterator_begin;
        E _element_iterator_end;
        unsigned int index;
        unsigned int num_of_elements;

        iterator(E element_it_begin, E element_it_end) : _element_iterator_begin(element_it_begin),
                                                         _element_iterator_end(element_it_end),
                                                         index(0),
                                                         num_of_elements(0)
        {
            E _element_iterator = _element_iterator_begin;
            while (_element_iterator != _element_iterator_end)
            {
                ++num_of_elements;
                ++_element_iterator;
            }

            num_of_elements = std::pow(2, num_of_elements);
        }

        // operators
        bool operator!=(powerset::iterator<E> const &other) const
        {
            return ((num_of_elements - index) != (other.num_of_elements - other.index - 1));
        }

        auto operator*() const
        {
            E _element_iterator = _element_iterator_begin;
            std::vector<typename std::remove_const<typename std::remove_reference<decltype(*_element_iterator_begin)>::type>::type> S;
           
            unsigned int i = index;
            while (i != 0 && _element_iterator != _element_iterator_end)
            { 
                unsigned int r = i % 2;
                i = i >> 1; //divide by 2.

                if (r == 1)
                    S.emplace_back(*_element_iterator);

                ++_element_iterator;
            }

            return S;
        }

        powerset::iterator<E> &operator++()
        {

            ++index;
            return *this;
        }
    };

public:
    powerset(T start) : from(start) {}                                                                                                              // constructor
    auto begin() const { return powerset::iterator<decltype(from.begin())>(from.begin(), from.end()); } // iteratable object
    auto end() const { return powerset::iterator<decltype(from.begin())>(from.end(), from.end()); }       // iteratable object
};                                                                                                                                                  // class

template <typename T>

powerset<T> power(T start)
{
    return powerset<T>(start);
}

} // namespace itertools
