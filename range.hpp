#pragma once
namespace itertools
{
template <typename T>
class range
{
  private:
	T _begin;
	T _end;

  public:
	
	range <T> (T _begin,T _end):_begin(_begin) , _end(_end){}


	class iterator
	{
	  private:
		T _iter;

    public:
		iterator( T _iter ) : _iter(_iter) {}

		auto &operator*() const
		{
			
				return _iter;
			
		}

		// auto *operator-> () const
		// {
		
		// 		return &_iter;
		
		// }

		// ++i;
		iterator &operator++()
		{
			++(_iter);
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const iterator operator++(int)
		{
			iterator tmp = *this;
			(_iter)++;
			return tmp;
		}

		bool operator==(const iterator &rhs) const
		{
			return (_iter) == (rhs._iter);
		}

		bool operator!=(const iterator &rhs) const
		{
			return (_iter) != (rhs._iter);
		}
	};

public:
	iterator begin()
	{
		return range<T>::iterator(_begin);
	}

	iterator end()
	{
		return  range<T>::iterator(_end);
	}
};
} // namespace itertools

