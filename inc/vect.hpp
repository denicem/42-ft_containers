/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:17:07 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/16 18:46:00 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT_HPP
#define VECT_HPP

#include <iostream>
#include <memory>

namespace func
{
		/*
	** ----------------------- VECT ITER -----------------------
	*/
	template<typename Vect>
	class VectIter
	{
	public:
		typedef typename Vect::value_type value_type;
		typedef value_type* pointer;
		typedef value_type& reference;

	private:
		pointer _ptr;
	public:
		VectIter(pointer ptr): _ptr(ptr) { }

	public:
		VectIter& operator++()
		{
			_ptr++;
			return (*this);
		}

		VectIter& operator++(int)
		{
			VectIter old = *this;
			_ptr++;
			return (old);
		}

		VectIter& operator--()
		{
			_ptr--;
			return (*this);
		}

		VectIter& operator--(int)
		{
			VectIter old = *this;
			_ptr--;
			return (old);
		}

		reference operator[](int idx)
		{
			return (*(_ptr + idx));
		}

		pointer operator->()
		{
			return (_ptr);
		}

		reference operator*()
		{
			return (*_ptr);
		}

		bool operator==(const VectIter& other) const
		{
			return (_ptr == other._ptr);
		}

		bool operator!=(const VectIter& other) const
		{
			return (_ptr != other._ptr);
		}

		bool operator<(const VectIter& other) const
		{
			return (_ptr < other._ptr);
		}

		bool operator<=(const VectIter& other) const
		{
			return (_ptr <= other._ptr);
		}

		bool operator>(const VectIter& other) const
		{
			return (_ptr > other._ptr);
		}
		
		bool operator>=(const VectIter& other) const
		{
			return (_ptr >= other._ptr);
		}
	};

	/*
	** ----------------------- VECT -----------------------
	*/
	template< typename T, class Alloc = std::allocator<T> >
	class Vect
	{
	public:
		typedef T value_type;
		typedef VectIter< Vect<T> > iterator;
	private:
		T*		_data;
		size_t	_size;
		size_t	_capacity;

	private:
		void realloc(size_t newCap)
		{
			// 1 allocate new block of memory
			// 2 copy/move old elements to new block
			// 3 delete

			T* newData = new T[newCap];
			
			if (newCap < _size)
				_size = newCap;

			for (size_t i = 0; i < _size; i++)
				newData[i] = _data[i];
			
			_capacity = newCap;
			delete[] _data;
			_data = newData;
		}

	public:
		Vect()
		{
			// allocate 2 blocks of memory
			realloc(2);
		}

		~Vect() { delete[] _data; }

		T& operator[](size_t idx)
		{
			// if (idx >= _size)
			return (_data[idx]);
		}

		const T& operator[](size_t idx) const
		{
			// if (idx >= _size)
			return (_data[idx]);
		}

		void push_back(const T& value)
		{
			if (_size >= _capacity)
				realloc(_capacity * 1.5);
			_data[_size] = value;
			_size++;
		}

		void pop_back()
		{
			if (_size > 0)
			{
				_size--;
				_data[_size].~T();
			}
		}

		void clear()
		{
			for (size_t i = 0; i < _size; i++)
				_data[i].~T();

			_size = 0;
		}

		size_t size() const { return (_size); }
		size_t capacity() const { return (_capacity); }

		iterator begin() { return iterator(_data); }
		iterator end() { return iterator(_data + _size); }

	};
}

#endif
