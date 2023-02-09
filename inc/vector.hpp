/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:17:12 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/09 23:47:54 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

// TODO understand type_traits, enable_if and is_integral better
// TODO rewrite realloc() - use std::allocator
// TODO rewrite destructor - use std::allocator
// TODO rewrite clear() - use destroy() from std::allocator

// TODO implement reverse_iterator
// TODO: understand iterator_traits

// TODO rewrite push_back()
// TODO rewrite assign()
// TODO rewrite insert()

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {

	/*
	** ----------------------- MEMBER TYPES -----------------------
	*/
	public:
		typedef Alloc										allocator_type;
		typedef typename allocator_type::value_type			value_type;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type; // TODO: from iterator_traits<iterator>
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef ft::Iterator<value_type>					iterator;
		typedef ft::Iterator<const value_type>				const_iterator;
		typedef ft::ReverseIterator<iterator>				reverse_iterator;
		typedef ft::ReverseIterator<const_iterator>		const_reverse_iterator;
		
	/*
	** --------------------------- MEMBER VARIABLES ---------------------------
	*/
	private:
		allocator_type	_alloc;
		size_type	_cap;
		size_type	_size;
		pointer		_data;

	/*
	** ---------------------------- PRIVATE METHODS ----------------------------
	*/
	private:
		void _realloc(size_type new_cap) {
			// if (new_cap > this->max_size()) // NOTE: protection? 
			// 	throw std::bad_alloc();
			size_type old_cap = this->_cap;

			T* newData = (this->_alloc).allocate(new_cap);

			if (new_cap < this->_size)
				this->_size = new_cap;
			for (size_type i = 0; i < this->_size; i++)
				(this->_alloc).construct(newData + i, this->_data[i]);
			this->_cap = new_cap;

			iterator it = this->begin();
			iterator ite = this->end();
			if (this->_data) {
				for (; it != ite; ++it)
					(this->_alloc).destroy(&(*it));
				(this->_alloc).deallocate(this->_data, old_cap);
			}

			this->_data = newData;
		}

	/*
	** ---------------------------- MEMBER FUNCTIONS ---------------------------
	** ----------------------- CONSTRUCTORS & DESTRUCTOR -----------------------
	*/
	public:
		// default constructor
		explicit vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _cap(0), _size(0), _data(NULL) {
			// std::cout << "default constructor." << std::endl;
		}

		// fill constructor
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _cap(n), _size(0), _data(NULL) {
			// std::cout << "fill constructor." << std::endl;
			this->_data = (this->_alloc).allocate(this->_cap);

			for (size_type i = 0; i < this->_cap; ++i) {
				(this->_alloc).construct(this->_data + this->_size, val);
				++this->_size;
			}
		}

		// range constructor
		template < class InputIterator >
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if< !ft::is_integral< InputIterator >::value >::type* = NULL)
			: _alloc(alloc), _cap(0), _size(0), _data(NULL)
		{
			this->assign(first, last);
		}

		// copy constructor
		vector(const vector& x): _alloc(x._alloc), _cap(x._cap), _size(0), _data(NULL) {
			// std::cout << "copy constructor." << std::endl;
			this->_data = (this->_alloc).allocate(this->_cap);

			for (size_type i = 0; i < x._size; ++i) {
				(this->_alloc).construct(this->_data + this->_size, x[i]);
				++this->_size;
			}
		}

		// destructor
		~vector() {
			this->clear();
			if (this->_data)
				(this->_alloc).deallocate(this->_data, this->_cap);
			this->_data = NULL;
			this->_cap = 0;
		}

		// assignment operator
		vector& operator=(const vector& x) {
			if (this != &x) {
				this->clear();
				this->_alloc = x._alloc;
				if (x._size > this->_cap)
					this->_realloc(x._size);
				for (size_type i = 0; i < x._size; ++i)
					(this->_alloc).construct(this->_data + i, x[i]);
				this->_size = x._size;
			}
			return (*this);
		}

	/*
	** ----------------------- ITERATORS -----------------------
	*/
	public:
		iterator begin() { return (iterator(_data)); }
		const_iterator begin() const { return (const_iterator(_data)); }
		iterator end() { return (iterator(_data + _size)); }
		const_iterator end() const { return (const_iterator(_data + _size)); }
		reverse_iterator rbegin() { return (reverse_iterator(end())); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }
		reverse_iterator rend() { return (reverse_iterator(begin())); }
		const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); }
		const_iterator cbegin() const { return (const_iterator(_data)); }
		const_iterator cend() const { return (const_iterator(_data + _size)); }
		const_reverse_iterator crbegin() const { return (const_reverse_iterator(end())); }
		const_reverse_iterator crend() const { return (const_reverse_iterator(begin())); }

	/*
	** ----------------------- CAPACITY -----------------------
	*/
	public:
		size_type size() const { return (this->_size); }
		size_type max_size() const { return ((this->_alloc).max_size());}
		// size_type max_size() const {return ft::min<size_type>(this->_alloc.max_size(), std::numeric_limits<difference_type>::max()); }

		void resize (size_type n, value_type val = value_type()) {
			if (n < this->_size) {
				while (this->_size > n)
					this->pop_back();
			}
			else if (n > this->_size) {
				if (n > this->_cap)
					this->_realloc(n);
				while (this->_size < n)
					this->push_back(val);
			}
		}

		size_type capacity() const { return (this->_cap); }
		bool empty() const { return (!this->_size); }

		void reserve(size_type n) {
			if (n > this->max_size())
				throw std::length_error("ft::length_error");
			if (n > this->_cap)
				this->_realloc(n);
		}

	/*
	** ----------------------- ELEMENT ACCESS -----------------------
	*/
	public:
		reference operator[](size_type idx) { return (this->_data[idx]); }
		const_reference operator[](size_type idx) const { return (this->_data[idx]); }
		reference at(size_type idx) { if (idx >= this->_size)  throw std::out_of_range("ft::out_of_range"); return (this->_data[idx]); }
		const_reference at(size_type idx) const { if (idx >= this->_size)  throw std::out_of_range("ft::out_of_range"); return (this->_data[idx]); }
		reference front() { return (*(this->_data)); }
		const_reference front() const { return (*(this->_data)); }
		reference back() { return (this->_data[this->_size - 1]); }
		const_reference back() const { return (this->_data[this->_size - 1]); }
		pointer data() { return (this->_data); }
		const_pointer data() const { return (this->_data); }

	/*
	** ----------------------- MODIFIERS -----------------------
	*/
	public:
		// range assign
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value >::type* = NULL) {
			this->clear();
			for (; first != last; ++first)
				this->push_back(*first);
		}

		// fill assign
		void assign(size_type n, const value_type& val) {
			this->clear();
			if (n > this->_cap)
				this->reserve(n);
			for (size_type i = 0; i < n; ++i)
				this->push_back(val);
		}

		void push_back(const_reference value) {
			if (this->_size >= this->_cap)
				this->reserve( this->capacity() ? this->_cap * 2 : 2 ); // NOTE: whats the optimal amount?!?
			(this->_alloc).construct(this->_data + this->_size, value);
			++this->_size;
		}

		void pop_back() {
			if (this->_size > 0) {
				--this->_size;
				(this->_alloc).destroy(this->_data + this->_size);
			}
		}

	// private:
	// 	void _insert_construct_end(size_type curr, size_type n) {
	// 		for (size_type last_el = this->_size - 1; last_el >= curr; --last_el) {
	// 			size_type new_last_el = last_el + n;
	// 			// (this->_alloc).construct(this->_data + new_last_el, this->_data[last_el]);
	// 			this->_data[new_last_el] = this->_data[last_el];
	// 			// (this->_alloc).destroy(this->_data + last_el);
	// 			if (!last_el)
	// 				break ;
	// 		}
	// 	}
	public:

	// insert single element
	iterator insert(iterator pos, const_reference val) {
		size_type res = pos - begin();
		this->insert(pos, 1, val);
		return (iterator(this->_data + res));
	}

	// insert fill
	void insert(iterator pos, size_type n, const_reference val) {
		size_type index = pos - this->begin();
		if (n) {
			if (this->size() + n > this->capacity())
				reserve(this->size() + n);
			for (size_type i = this->_size; i > index; i--) {
				this->_alloc.construct(this->_data + i + n - 1, *(this->_data + i -1));
				this->_alloc.destroy(this->_data + i - 1);
			}
			for (size_type i = 0; i < n; i++) {
				this->_alloc.construct(this->_data + index + i, val);
				this->_size++;
			}
		}
	}

	// insert range
	template <class InputIterator>
	void insert(iterator pos, InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value >::type* = NULL) {
		for (; first != last; ++first, ++pos)
			pos = insert(pos, *first);
	}

		iterator erase(iterator pos) {
			iterator res = pos;
			while (pos + 1 != end()) {
				*pos = *(pos + 1);
				++pos;
			}
			this->pop_back();
			return (res);
		}

		iterator erase(iterator first, iterator last) {
			size_type n = last - first;
			iterator it;

			for (it = first ; (it + n) < end(); ++it)
				*it = *(it + n);
			for (; it < end(); ++it)
				this->_alloc.destroy(it.base());
			this->_size -= n;
			return (first);
		}

		void swap(vector& x) {
			allocator_type	tmp_alloc = this->_alloc;
			size_type	tmp_cap = this->_cap;
			size_type	tmp_size = this->_size;
			pointer		tmp_data = this->_data;

			this->_alloc = x._alloc;
			this->_cap = x._cap;
			this->_size = x._size;
			this->_data = x._data;

			x._alloc = tmp_alloc;
			x._cap = tmp_cap;
			x._size = tmp_size;
			x._data = tmp_data;
		}

		void clear() {
			iterator it = this->begin();
			iterator ite = this->end();
			for (; it != ite; ++it)
				(this->_alloc).destroy(&(*it));
			this->_size = 0;
		}

	/*
	** ----------------------- ALLOCATOR -----------------------
	*/
	public:
		allocator_type get_allocator() const { return (this->_alloc); }

}; // END class vector
/*
** ----------------------- NON-MEMBER FUNCS OVERLOADS -----------------------
*/

// ----------------------- RELATIONAL OPERATORS -----------------------

template <class T, class Alloc>  
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	if (lhs.size() == rhs.size()) // NOTE: check sizes, then compare
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	return false;
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(rhs < lhs);
}

template <class T, class Alloc>
bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(lhs < rhs);
}

// ----------------------- -------------------- -----------------------

template <class T, class Alloc>
void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) { x.swap(y); }

} // END namespace ft

#endif
