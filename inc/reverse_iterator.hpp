/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:42:35 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/27 18:02:19 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H

#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft {

template < typename Iter >
class ReverseIterator {
	public:
		/*
		** ----------------------- MEMBER TYPES -----------------------
		*/
		typedef Iter							iter_type;
		typedef typename iterator_traits<iter_type>::iterator_category iterator_category;
		typedef typename iterator_traits<iter_type>::value_type value_type;
		typedef typename iterator_traits<iter_type>::difference_type difference_type;
		typedef typename iterator_traits<iter_type>::pointer pointer;
		typedef typename iterator_traits<iter_type>::reference reference;

	protected:
		/*
		** ----------------------- MEMBER VARIABLES -----------------------
		*/
		iter_type _ptr;

	public:
		/*
		** ----------------------- CONSTRUCTORS & DESTRUCTOR -----------------------
		*/
		ReverseIterator(iter_type ptr = NULL): _ptr(ptr) {}
		template< typename T1 >
		ReverseIterator(const ReverseIterator<T1>& other): _ptr(other.base()) {}
		~ReverseIterator() {}

	public:
		/*
		** ---------------------------- MEMBER FUNCTIONS ---------------------------
		*/
		iter_type base() const { return (this->_ptr); }

	public:
		/*
		** ---------------------------- ACCESS OPERATORS ---------------------------
		*/
		pointer operator->() const {return &(operator*());}
		reference operator*() const { iter_type tmp = this->base(); return *(--tmp); }
		reference operator[](difference_type idx) const { return (*(*this + idx)); }

	public:
		/*
		** ---------------------------- INC/DEC OPERATORS ---------------------------
		*/
		ReverseIterator& operator++() {
			--this->_ptr;
			return (*this);
		}
		ReverseIterator operator++(int) {
			ReverseIterator old = *this;
			--this->_ptr;

			return (old);
		}
		ReverseIterator& operator--() {
			++this->_ptr;
			return (*this);
		}
		ReverseIterator operator--(int) {
			ReverseIterator old = *this;
			++this->_ptr;

			return (old);
		}
		ReverseIterator& operator+=(const difference_type& n) {
			this->_ptr -= n;
			return (*this);
		}
		ReverseIterator operator+(const difference_type& n) const {
			return (ReverseIterator(this->_ptr - n));
		}
		ReverseIterator& operator-=(const difference_type& n) {
			this->_ptr += n;
			return (*this);
		}
		ReverseIterator operator-(const difference_type& n) const {
			return (ReverseIterator(this->_ptr + n));
		}
};

/*
** ---------------------------- NON-MEMBER FUNCTIONS ---------------------------
** ---------------------------- NON-MEMBER OPERATORS ---------------------------
*/

// ---------------------------- RELATIONAL OPERATORS ---------------------------
template< class Iter1, class Iter2 >
bool operator==(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs) { return (lhs.base() == rhs.base()); }
template< class Iter1, class Iter2 >
bool operator!=(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs) { return (lhs.base() != rhs.base()); }
template< class Iter1, class Iter2 >
bool operator<(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs) { return (lhs.base() > rhs.base()); }
template< class Iter1, class Iter2 >
bool operator<=(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs) { return (lhs.base() >= rhs.base()); }
template< class Iter1, class Iter2 >
bool operator>(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs) { return (lhs.base() < rhs.base()); }
template< class Iter1, class Iter2 >
bool operator>=(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs) { return (lhs.base() <= rhs.base()); }

// ---------------------------- ARITHMETIC OPERATORS ---------------------------
template< class Iter>
ReverseIterator<Iter> operator+(typename ReverseIterator<Iter>::difference_type n, const ReverseIterator<Iter>& it) {
	return (ReverseIterator<Iter>(it.base() - n));
}

template< class Iter >
typename ReverseIterator<Iter>::difference_type operator-(const ReverseIterator<Iter>& lhs, const ReverseIterator<Iter>& rhs) { return (rhs.base() - lhs.base()); }

} // END NAMESPACE FT

#endif
