/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:43:36 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/03 16:29:13 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
#define ITERATOR_H

#include "iterator_traits.hpp"

#include <iostream>

namespace ft {

template < typename Iter >
class Iterator {
	public:
		/*
		** ----------------------- MEMBER TYPES -----------------------
		*/
		typedef random_access_iterator_tag	iterator_category;
		typedef Iter							iter_type;
		typedef std::ptrdiff_t					difference_type;
		typedef iter_type*						pointer;
		typedef const iter_type*				const_pointer;
		typedef iter_type&						reference;
		typedef const iter_type&				const_reference;

	protected:
		/*
		** ----------------------- MEMBER VARIABLES -----------------------
		*/
		pointer _ptr;

	public:
		/*
		** ----------------------- CONSTRUCTORS & DESTRUCTOR -----------------------
		*/
		Iterator(pointer ptr = NULL): _ptr(ptr) {  }
		// explicit Iterator(iter_type it): _ptr(it) { "initialization constructor" << std::endl; }
		template< typename T1 >
		Iterator(const Iterator<T1>& other): _ptr(other.base()) { std::cout << "copy constructor" << std::endl; }
		~Iterator() {}

	public:
		/*
		** ---------------------------- MEMBER FUNCTIONS ---------------------------
		*/
		pointer base() const { return (this->_ptr); }

		Iterator& operator=(const Iterator& other) {
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}
		template< typename T1 >
		Iterator& operator=(const Iterator<T1>& other) {
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}
		Iterator& operator=(pointer ptr) {
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
		Iterator& operator++() {
			_ptr++;
			return (*this);
		}
		Iterator operator++(int) {
			Iterator old = *this;
			_ptr++;

			return (old);
		}
		Iterator& operator--() {
			_ptr--;
			return (*this);
		}
		Iterator operator--(int) {
			Iterator old = *this;
			_ptr--;

			return (old);
		}

		Iterator& operator+=(const difference_type& n) {
			this->_ptr += n;
			return (*this);
		}
		Iterator operator+(const difference_type& n) const {
			Iterator tmp(*this);
			tmp += n;
			return (tmp);
		}
		Iterator& operator-=(const difference_type& n) {
			this->_ptr -= n;
			return (*this);
		}
		Iterator operator-(const difference_type& n) const {
			Iterator tmp(*this);
			tmp -= n;
			return (tmp);
		}
};

/*
** ---------------------------- NON-MEMBER FUNCTIONS ---------------------------
** ---------------------------- NON-MEMBER OPERATORS ---------------------------
*/

// ---------------------------- RELATIONAL OPERATORS ---------------------------
template< class Iter1, class Iter2 >
bool operator==(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs) { return (lhs.base() == rhs.base()); }
template< class Iter1, class Iter2 >
bool operator!=(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs) { return (lhs.base() != rhs.base()); }
template< class Iter1, class Iter2 >
bool operator<(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs) { return (lhs.base() < rhs.base()); }
template< class Iter1, class Iter2 >
bool operator<=(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs) { return (lhs.base() <= rhs.base()); }
template< class Iter1, class Iter2 >
bool operator>(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs) { return (lhs.base() > rhs.base()); }
template< class Iter1, class Iter2 >
bool operator>=(const Iterator<Iter1>& lhs, const Iterator<Iter2>& rhs) { return (lhs.base() >= rhs.base()); }

// ---------------------------- ARITHMETIC OPERATORS ---------------------------
template< class Iter>
Iterator<Iter> operator+(typename Iterator<Iter>::difference_type n, const Iterator<Iter>& it) {
	Iterator<Iter> tmp(it);
	tmp += n;
	return (tmp);
}

template< class Iter >
typename Iterator<Iter>::difference_type operator-(const Iterator<Iter>& lhs, const Iterator<Iter>& rhs) { return (lhs.base() - rhs.base()); }

} // END NAMESPACE FT

#endif
