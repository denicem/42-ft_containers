/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:43:36 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/21 18:04:22 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
#define ITERATOR_H

#include "iterator_traits.hpp"

namespace ft
{
	template < typename T >
	class Iterator
	{
	/*
	** ----------------------- MEMBER TYPES -----------------------
	*/
	public:
		typedef random_access_iterator_tag	iterator_category; // NOTE: usage??
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef value_type*						pointer;
		typedef const value_type*				const_pointer;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;

	protected:
		pointer _ptr;

	public:
		explicit Iterator(pointer ptr = NULL): _ptr(ptr) { }
		Iterator(const Iterator& other): _ptr(other._ptr) { }
		template< typename T1 >
		Iterator(const Iterator<T1>& other): _ptr(other.base()) { }
		~Iterator() {}

		pointer base() const { return this->_ptr; }

		Iterator& operator=(const Iterator& other)
		{
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}
		template< typename T1 >
		Iterator& operator=(const Iterator<T1>& other)
		{
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}
		Iterator& operator=(pointer ptr)
		{
			this->_ptr = ptr;
			return (*this);
		}

		pointer operator->() { return (_ptr); }
		reference operator*() { return (*_ptr); }
		reference operator[](int idx) { return (*(_ptr + idx)); }

		Iterator& operator++()
		{
			_ptr++;
			return (*this);
		}
		Iterator& operator++(int)
		{
			Iterator old = *this;
			_ptr++;

			return (old);
		}
		Iterator& operator--()
		{
			_ptr--;
			return (*this);
		}
		Iterator& operator--(int)
		{
			Iterator old = *this;
			_ptr--;

			return (old);
		}

		bool operator==(const Iterator& other) const
		{
			return (_ptr == other._ptr);
		}
		bool operator!=(const Iterator& other) const
		{
			return (_ptr != other._ptr);
		}
		bool operator<(const Iterator& other) const
		{
			return (_ptr < other._ptr);
		}
		bool operator<=(const Iterator& other) const
		{
			return (_ptr <= other._ptr);
		}
		bool operator>(const Iterator& other) const
		{
			return (_ptr > other._ptr);
		}
		bool operator>=(const Iterator& other) const
		{
			return (_ptr >= other._ptr);
		}
	};
}

#endif