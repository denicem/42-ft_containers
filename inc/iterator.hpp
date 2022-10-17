/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:43:36 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/17 03:49:26 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
#define ITERATOR_H

namespace ft
{
	template < class T >
	class Iterator
	{
	/*
	** ----------------------- MEMBER TYPES -----------------------
	*/
	public:
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef value_type*						pointer;
		typedef const value_type*				const_pointer;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;
		// typedef std::random_access_iterator_tag	iterator_category; // NOTE: usage??

	protected:
		pointer _ptr;

	public:
		Iterator(pointer ptr): _ptr(ptr) {}
		Iterator(const Iterator& other): _ptr(other._ptr) {}
		~Iterator() {}

		Iterator& operator=(const Iterator& other)
		{
			_ptr = other._ptr;
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