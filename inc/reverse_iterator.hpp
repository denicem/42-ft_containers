/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:42:35 by dmontema          #+#    #+#             */
/*   Updated: 2022/11/02 22:48:13 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
#define ITERATOR_H

#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft
{
	template < typename Iter >
	class ReverseIterator
	{
	public:
		/*
		** ----------------------- MEMBER TYPES -----------------------
		*/
		// typedef random_access_iterator_tag	iterator_category;
		// typedef Iter							iter_type;
		// typedef std::ptrdiff_t					difference_type;
		// typedef iter_type*						pointer;
		// typedef const iter_type*				const_pointer;
		// typedef iter_type&						reference;
		// typedef const iter_type&				const_reference;
		typedef Iter							iter_type;
		typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type value_type;
		typedef typename iterator_traits<iterator_type>::difference_type difference_type;
		typedef typename iterator_traits<iterator_type>::pointer pointer;
		typedef typename iterator_traits<iterator_type>::reference reference;

	protected:
		/*
		** ----------------------- MEMBER VARIABLES -----------------------
		*/
		pointer _ptr;

	public:
		/*
		** ----------------------- CONSTRUCTORS & DESTRUCTOR -----------------------
		*/
		ReverseIterator(pointer ptr = NULL): _ptr(ptr) { }
		explicit ReverseIterator(value_type x): _ptr(x) { } // NOTE: still in need?
		template< typename T1 >
		ReverseIterator(const ReverseIterator<T1>& other): _ptr(other.base()) { }
		~ReverseIterator() {}

	public:
		/*
		** ---------------------------- MEMBER FUNCTIONS ---------------------------
		*/
		pointer base() const { return this->_ptr; }

		ReverseIterator& operator=(const ReverseIterator& other)
		{
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}
		template< typename T1 >
		ReverseIterator& operator=(const ReverseIterator<T1>& other)
		{
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}
		ReverseIterator& operator=(pointer ptr)
		{
			this->_ptr = ptr;
			return (*this);
		}

	public:
		/*
		** ---------------------------- ACCESS OPERATORS ---------------------------
		*/
		pointer operator->() { return (_ptr); }
		reference operator*() { return (*_ptr); }
		reference operator[](int idx) { return (*(_ptr + idx)); }

	public:
		/*
		** ---------------------------- INC/DEC OPERATORS ---------------------------
		*/
		ReverseIterator& operator++()
		{
			_ptr--;
			return (*this);
		}
		ReverseIterator operator++(int)
		{
			ReverseIterator old = *this;
			_ptr--;

			return (old);
		}
		ReverseIterator& operator--()
		{
			_ptr++;
			return (*this);
		}
		ReverseIterator operator--(int)
		{
			ReverseIterator old = *this;
			_ptr++;

			return (old);
		}

		ReverseIterator& operator+=(const difference_type& n)
		{
			this->_ptr -= n;
			return (*this);
		}
		ReverseIterator operator+(const difference_type& n) const
		{
			ReverseIterator tmp(*this);
			tmp -= n;
			return (tmp);
		}
		ReverseIterator& operator-=(const difference_type& n)
		{
			this->_ptr += n;
			return (*this);
		}
		ReverseIterator operator-(const difference_type& n) const
		{
			ReverseIterator tmp(*this);
			tmp += n;
			return (tmp);
		}
	};
}


#endif