/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:17:12 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/17 03:59:08 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include "iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
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
		// typedef ft::Iterator<const value_type>				const_iterator;
		// reverse_iterator;
		// const_reverse_iterator;
		
	/*
	** --------------------------- MEMBER VARIABLES ---------------------------
	*/
	private:
		pointer		_data;
		size_type	_size;
		size_type	_cap;

	/*
	** ---------------------------- PRIVATE METHODS ----------------------------
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
	** ---------------------------- MEMBER FUNCTIONS ---------------------------
	** ----------------------- CONSTRUCTORS & DESTRUCTOR -----------------------
	*/
	public:
		// default constructor
		explicit vector(const allocator_type& alloc = allocator_type())
		{
			std::cout << "default constructor.\n";
			this->_data = NULL;
			this->_cap = 0;
			this->_size = 0;
		}

		// fill constructor
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			std::cout << "size constructor.\n";
			this->_cap = n;
			this->_realloc(n);

			for (size_type i = 0; i < n; i++)
				this->_data[i] = val;
			this->_size = n;
		}

		// range constructor
		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {}

		// copy constructor
		// vector(const vector& x) {}

		// destructor
		~vector()
		{
			delete[] this->_data;
		}

		// assignment operator
		// vector& operator=(const vector& x) {}

	/*
	** ----------------------- ITERATORS -----------------------
	*/
	public:
		iterator begin() { return (iterator(_data)); }
		// const_iterator begin() const {}
		iterator end() { return (iterator(_data + _size)); }
		// const_iterator end() const {}
		// reverse_iterator rbegin() {}
		// const_reverse_iterator rbegin() const {}
		// reverse_iterator rend() {}
		// const_reverse_iterator rend() const {}
		// const_iterator cbegin() const noexcept {}
		// const_iterator cend() const noexcept {}
		// const_reverse_iterator crbegin() const noexcept {}
		// const_reverse_iterator crend() const noexcept {}

	/*
	** ----------------------- CAPACITY -----------------------
	*/
	public:
		size_type size() const { return (this->_size); }
		// size_type max_size() const {}
		// void resize (size_type n, value_type val = value_type()) {}
		size_type capacity() const { return (this->_cap); }
		// bool empty() const {}
		// void reserve(size_type n) {}
		// void shrink_to_fit();

	/*
	** ----------------------- ELEMENT ACCESS -----------------------
	*/
	public:
		reference operator[](size_type idx) { return (this->_data[idx]); }
		const_reference operator[](size_type idx) const { return (this->_data[idx]); }
		reference at(size_type idx) { return (this->_data[idx]); }
		const_reference at(size_type idx) const { return (this->_data[idx]); }
		// reference front() {}
		// const_reference front() const {}
		// reference back() {}
		// const_reference back() const {}
		// value_type* data() noexcept {}
		// const value_type& data() const noexcept {}

	/*
	** ----------------------- MODIFIERS -----------------------
	*/
	public:
		// range assign
		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last) {}
		// fill assign
		// void assign(size_type n, const value_type& val) {}

		//void push_back(const value_type& val)
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

		// insert single element
		// iterator insert(iterator pos, const value_type& val) {}
		// insert fill
		// void insert(iterator pos, size_type n, const value_type& val) {}
		// insert range
		// template <class InputIterator>
		// void insert(iterator pos, InputIterator first, InputIterator last) {}

		// iterator erase(iterator pos) {}
		// iterator erase(iterator first, iterator last) {}
		// void swap(vector& x) {}

		void clear()
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_data[i].~T();
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
}

#endif
