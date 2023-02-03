/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:17:12 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/03 22:34:55 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include "iterator.hpp"
#include "type_traits.hpp"

// TODO: understand type_traits, enable_if and is_integral better
// TODO rewrite realloc() - use std::allocator
// TODO rewrite destructor - use std::allocator
// TODO rewrite clear() - use destroy() from std::allocator

// TODO: implement reverse_iterator
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
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef ft::Iterator<value_type>					iterator;
		typedef ft::Iterator<const value_type>				const_iterator;
		// reverse_iterator;
		// const_reverse_iterator;
		
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
			size_type old_cap = this->_cap;

			T* newData = (this->_alloc).allocate(new_cap);

			if (new_cap < this->_size)
				this->_size = new_cap;
			for (size_type i = 0; i < this->_size; i++)
				(this->_alloc).construct(newData + i, this->_data[i]);
			this->_cap = new_cap;

			iterator it = this->begin();
			iterator ite = this->end();
			for (; it != ite; ++it)
				(this->_alloc).destroy(&(*it));
			if (this->_data)
				(this->_alloc).deallocate(this->_data, old_cap);

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
			// std::cout << "range constructor" << std::endl;

			for (InputIterator it = first; it != last; ++it)
				++this->_cap;
			this->_data = (this->_alloc).allocate(this->_cap);

			for (size_type i = 0; first != last && i < this->_cap; ++i, ++first) {
				(this->_alloc).construct(this->_data + this->_size, *first);
				++this->_size;
			}
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
		vector& operator=(const vector& x)
		{
			if (this->_size < x._size)
				_realloc(x._size);
			for (size_type i = 0; i < x._size; ++i)
			{
				this->_data[i] = x[i];
			}
			this->_size = x._size;
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
		// reverse_iterator rbegin() {}
		// const_reverse_iterator rbegin() const {}
		// reverse_iterator rend() {}
		// const_reverse_iterator rend() const {}
		const_iterator cbegin() const { return (const_iterator(_data)); }
		const_iterator cend() const { return (const_iterator(_data + _size)); }
		// const_reverse_iterator crbegin() const noexcept {}
		// const_reverse_iterator crend() const noexcept {}

	/*
	** ----------------------- CAPACITY -----------------------
	*/
	public:
		size_type size() const { return (this->_size); }
		size_type max_size() const { return ((this->_alloc).max_size());}

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

		void shrink_to_fit() { if (this->_cap > this->_size) this->_realloc(this->_size); }

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
		reference back() { return (*(this->_data + _size - 1)); }
		const_reference back() const { return (*(this->_data + _size) - 1); }
		pointer data() { return (this->_data); }
		const_pointer data() const { return (this->_data); }

	/*
	** ----------------------- MODIFIERS -----------------------
	*/
	public:
		// range assign
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value >::type* = NULL)
		{
			this->clear();
			difference_type iter_size = last - first;
			if ((size_type) iter_size > this->_cap)
				this->reserve(iter_size);
			for (; first != last; ++first)
				this->push_back(*first);
		}

		// fill assign
		void assign(size_type n, const value_type& val)
		{
			this->clear();
			if (n > this->_cap)
				this->reserve(n);
			for (size_type i = 0; i < n; ++i)
				this->push_back(val);
		}

		void push_back(const_reference value)
		{
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

	private:
		void _insert_construct_end(size_type curr, size_type n) {
			for (size_type last_el = this->_size - 1; last_el >= curr; --last_el) {
				size_type new_last_el = last_el + n;
				(this->_alloc).construct(this->_data + new_last_el, this->_data[last_el]);
				(this->_alloc).destroy(this->_data + last_el);
				if (!last_el)
					break ;
			}
		}
	public:
		// insert single element
		iterator insert(iterator pos, const value_type& val) {
			size_type res = pos - (this->begin());
			this->insert(pos, 1, val);
			return (iterator(this->_data + res));
		}
		// insert fill
		void insert(iterator pos, size_type n, const value_type& val) {
			size_type curr = pos - begin();
			std::cout << curr << std::endl;
			if (this->_size + n > this->_cap)
				_realloc(this->_size + n);
			this->_insert_construct_end(curr, n);
			for (size_type i = 0; i < n; ++i, ++curr)
				(this->_alloc).construct(this->_data + curr, val);
			this->_size += n;
		}
		// insert range
		template <class InputIterator>
		void insert(iterator pos, InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value >::type* = NULL)
		{
			size_type curr = pos - begin();
			size_type n = last - first;
			if (this->_size + n >= this->_cap)
				_realloc(this->_cap + n);
			this->_insert_construct_end(curr, n);
			for (; first != last; ++curr, ++first)
				(this->_alloc).construct(this->_data + curr, *first);
			this->_size += n;
		}

		void erase(iterator pos) // TODO: return type: iterator
		{
			// if (isOutOfBounds(pos))
			// 	throw std::out_of_range("Iterator out of bounds.");
			for (; pos != end(); ++pos)
			{
				if (pos + 1 != end())
					*pos = *(pos + 1);
			}
			--this->_size;
		}

		// iterator erase(iterator first, iterator last) {}

		// void swap(vector& x) {}

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
		// allocator_type get_allocator() const {}
	};
/*
** ----------------------- NON-MEMBER FUNCS OVERLOADS -----------------------
*/

// ----------------------- RELATIONAL OPERATORS -----------------------
// template <class T, class Alloc>
// bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {}
// template <class T, class Alloc>
// bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {}
// template <class T, class Alloc>
// bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {}
// template <class T, class Alloc>
// bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {}
// template <class T, class Alloc>
// bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {}
// template <class T, class Alloc>
// bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {}
// ----------------------- -------------------- -----------------------

// template <class T, class Alloc>
// void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {}

} // END NAMESPACE FT

#endif
