/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:43:36 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/25 17:37:23 by dmontema         ###   ########.fr       */
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
	// NOTE: 
	/*
	** ----------------------- MEMBER TYPES -----------------------
	*/
	public:
		typedef random_access_iterator_tag	iterator_category;
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
		// Iterator(const Iterator& other): _ptr(other._ptr) { } // NOTE: still in need?
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
		Iterator operator++(int)
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
		Iterator operator--(int)
		{
			Iterator old = *this;
			_ptr--;

			return (old);
		}

		Iterator& operator+=(const difference_type& n)
		{
			this->_ptr += n;
			return (*this);
		}
		Iterator operator+(const difference_type& n) const
		{
			Iterator tmp(*this);
			tmp += n;
			return (tmp);
		}
		Iterator& operator-=(const difference_type& n)
		{
			this->_ptr -= n;
			return (*this);
		}
		Iterator operator-(const difference_type& n) const
		{
			Iterator tmp(*this);
			tmp -= n;
			return (tmp);
		}

		// template< typename T1 >
		// bool operator==(const Iterator<T1>& other) const
		// {
		// 	return (_ptr == other.base());
		// }
		// template< typename T1 >
		// bool operator!=(const Iterator<T1>& other) const
		// {
		// 	return (_ptr != other.base());
		// }
		// template< typename T1 >
		// bool operator<(const Iterator<T1>& other) const
		// {
		// 	return (_ptr < other.base());
		// }
		// template< typename T1 >
		// bool operator<=(const Iterator<T1>& other) const
		// {
		// 	return (_ptr <= other.base());
		// }
		// template< typename T1 >
		// bool operator>(const Iterator<T1>& other) const
		// {
		// 	return (_ptr > other.base());
		// }
		// template< typename T1 >
		// bool operator>=(const Iterator<T1>& other) const
		// {
		// 	return (_ptr >= other.base());
		// }
	};

	template< class Iter1, class Iter2 >
	bool operator==(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template< class Iter1, class Iter2 >
	bool operator!=(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template< class Iter1, class Iter2 >
	bool operator<(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template< class Iter1, class Iter2 >
	bool operator<=(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template< class Iter1, class Iter2 >
	bool operator>(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template< class Iter1, class Iter2 >
	bool operator>=(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template< class Iter>
	Iterator<Iter> operator+(typename Iterator<Iter>::difference_type n, const Iterator<Iter>& it)
	{
			Iterator<Iter> tmp(it);
			tmp += n;
			return (tmp);
	}

	template< class Iter >
	typename Iterator<Iter>::difference_type operator-(const Iterator<Iter>& lhs, const Iterator<Iter>& rhs)
	{
		return (lhs.base() - rhs.base());
	}
}

#endif