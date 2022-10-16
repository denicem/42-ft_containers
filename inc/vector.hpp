/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:17:12 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/15 21:56:13 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{
	template< typename T, class Alloc = std::allocator<T> >
	class vector
	{
		/*
		** ----------------------- MEMBER TYPES -----------------------
		*/
	private:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::size_type size_type;
		// typedef typename allocator_type::size_t size_type;
		typedef typename allocator_type::difference_type difference_type;
		// typedef typename allocator_type::ptrdiff_t difference_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef pointer iterator;
		typedef const_pointer const_iterator;
		// reverse_iterator;
		// const_reverse_iterator;
		
		/*
		** ----------------------- MEMBER VARIABLES -----------------------
		*/
	private:
		pointer		_data;
		size_type	_size;
		size_type	_cap;

		/*
		** ----------------------- PRIVATE METHODS -----------------------
		*/
	private:
		void _realloc(size_type newCap)
		{
			T* newData = new T[newCap];
			if (newCap < this->_size)
				this->_size = newCap;
			for (size_type i = 0; i < this->_size; i++)
				newData[i] = this->_data[i];
			this->_cap = newCap;
			delete[] this->_data;
			this->_data = newData;
		}

		/*
		** ----------------------- CONSTRUCTORS & DESTRUCTOR -----------------------
		*/
	public:
		explicit vector(const allocator_type& alloc = allocator_type())
		{
			std::cout << "default constructor.\n";
			this->_data = NULL;
			this->_cap = 0;
			this->_size = 0;
		}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			std::cout << "size constructor.\n";
			this->_cap = n;
			this->_realloc(n);

			for (size_type i = 0; i < n; i++)
				this->_data[i] = val;
			this->_size = n;
		}

		~vector()
		{
			delete[] this->_data;
		}

		/*
		** ----------------------- OPERATOR OVERLOADS -----------------------
		*/
	public:
		reference operator[](size_type idx) { return (this->_data[idx]); }
		const_reference operator[](size_type idx) const { return (this->_data[idx]); }

		/*
		** ----------------------- GETTER AND SETTER METHODS -----------------------
		*/
	public:
		size_type size() const { return (this->_size); }
		size_type capacity() const { return (this->_cap); }

		/*
		** ----------------------- METHODS -----------------------
		*/
	public:
		void push_back(const_reference value)
		{
			if (this->_cap == 0)
				this->_realloc(2);
			else if (this->_size >= this->_cap)
				this->_realloc(this->_cap * 1.5);
			this->_data[this->_size] = value;
			this->_size++;
		}

		void pop_back()
		{
			if (this->_size > 0)
			{
				this->_size--;
				this->_data[this->_size].~T();
			}
		}

		void clear()
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_data[i].~T();
			this->_size = 0;
		}

		/*
		** ----------------------- CLASS ATTRIBUTES -----------------------
		*/

		/*
		** ----------------------- CLASS METHODS -----------------------
		*/

	};
}

/*
** ----------------------- FUNCS -----------------------
*/

#endif
