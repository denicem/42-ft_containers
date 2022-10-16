/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:17:07 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/15 21:31:55 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT_HPP
#define VECT_HPP

#include <iostream>

namespace func
{
	template<typename T>
	class Vect
	{
	private:
		T*		_data;
		size_t	_size;
		size_t	_capacity;

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
	};
}

#endif
