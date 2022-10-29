/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:17:12 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/28 23:06:58 by dmontema         ###   ########.fr       */
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
		typedef Iterator<value_type>					iterator;
		typedef Iterator<const value_type>				const_iterator;
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
			(void) alloc;
			// std::cout << "default constructor.\n";
			this->_data = NULL;
			this->_cap = 0;
			this->_size = 0;
		}

		// fill constructor
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			(void) alloc;
			// std::cout << "size constructor.\n";
			this->_cap = n;
			this->_realloc(n);

			for (size_type i = 0; i < n; i++)
				this->_data[i] = val;
			this->_size = n;
		}

		// range constructor
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _data(NULL), _size(0), _cap(0)
		{
			(void) alloc;
			size_type i = 0;
			for (InputIterator it = first; it != last; ++it)
				i++;
			_realloc(i);
			while (first != last)
			{
				push_back(*first);
				first++;
			}
			_size = i;
		}

		// copy constructor
		vector(const vector& x): _data(NULL), _size(0), _cap(0)
		{
			_realloc(x._cap);
			for (size_type i = 0; i < x._size; ++i)
				push_back(x[i]);
			
		}

		// destructor
		~vector()
		{
			delete[] this->_data;
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
		// size_type max_size() const {}

		void resize (size_type n, value_type val = value_type())
		{
			if (n < this->_size)
			{
				this->_realloc(n);
				return ;
			}
			else if (n > this->_size)
			{
				size_type i = 0;
				for (; i < _size; ++i);
				for (; i < n; ++i)
					this->push_back(val);
			}
		}

		size_type capacity() const { return (this->_cap); }
		bool empty() const { return (!this->_size); }

		void reserve(size_type n)
		{
			if (n > this->_cap)
				this->_realloc(n);
		}

		void shrink_to_fit() { this->_realloc(this->_size); }

	/*
	** ----------------------- ELEMENT ACCESS -----------------------
	*/
	public:
		reference operator[](size_type idx) { return (this->_data[idx]); }
		const_reference operator[](size_type idx) const { return (this->_data[idx]); }
		reference at(size_type idx) { return (this->_data[idx]); }
		const_reference at(size_type idx) const { return (this->_data[idx]); }
		reference front() { return (*(this->_data)); }
		const_reference front() const { return (*(this->_data)); }
		reference back() { return (*(this->_data + _size)); }
		const_reference back() const { return (*(this->_data + _size)); }
		pointer data() { return (this->_data); }
		const value_type& data() const { return (this->_data); }

	/*
	** ----------------------- MODIFIERS -----------------------
	*/
	public:
		// range assign
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
			for (typename ft::vector<value_type>::iterator it = this->begin(); first != last && it != this->end(); it++, first++)
				*it = *first;
		}

		// fill assign
		void assign(size_type n, const value_type& val)
		{
			for (size_type i = 0; i < this->_size, i < n; i++)
				this->_data[i] = val;
		}

		//void push_back(const value_type& val)
		void push_back(const_reference value)
		{
			if (this->_cap == 0)
				this->_realloc(2);
			else if (this->_size >= this->_cap)
				this->_realloc(this->_cap * 2); // NOTE: still not sure how much the right amount is to reserve after cap is full
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

	private: // helper func for insert & erase methods
		bool isOutOfBounds(iterator pos)
		{
			difference_type diff = pos - begin();
			if (diff < 0 || static_cast<size_type>(diff) > this->_size)
				return (true);
			return (false);
		}
	public:
		// insert single element
		iterator insert(iterator pos, const value_type& val)
		{
			// if (isOutOfBounds(pos))
			// 	throw std::out_of_range("Iterator out of bounds.");
			
			size_type curr = static_cast<size_type>(pos - begin());
			if (this->_size >= this->_cap)
				this->_realloc(this->_cap * 2); // NOTE: still not sure how much the right amount is to reserve after cap is full
			for (size_type i = this->_size; i > curr; --i)
				this->_data[i] = this->_data[i - 1];
			this->_data[curr] = val;
			++this->_size;
			return iterator(this->_data + curr);
		}
		// insert fill
		void insert(iterator pos, size_type n, const value_type& val) // TODO: return type: iterator
		{
			if (isOutOfBounds(pos))
				throw std::out_of_range("Iterator out of bounds.");
			difference_type curr = pos - begin();
			if (this->_size + n >= this->_cap)
				_realloc(this->_cap + n); 
			size_type i = curr + n;
			for (size_type j = curr; j < this->_size; ++j)
			{
				this->_data[i] = this->_data[j];
				++i;
			}
			for (size_type i = 0; i < n; ++i, ++curr)
			{
				this->_data[curr] = val;
			}
			this->_size += n;
			
		}
		// insert range
		template <class InputIterator>
		void insert(iterator pos, InputIterator first, InputIterator last) // TODO: return type: iterator
		{
			if (isOutOfBounds(pos))
				throw std::out_of_range("Iterator out of bounds.");
			difference_type curr = pos - begin();
			size_type n = 0;
			for (InputIterator it = first; it != last; ++it, ++n);
			std::cout << "n = " << n << std::endl;
			if (this->_size + n >= this->_cap)
				_realloc(this->_cap + n);
			size_type i = curr + n;
			for (size_type j = curr; j < this->_size; ++j)
			{
				this->_data[i] = this->_data[j];
				++i;
			}
			for (size_type i = 0; i < n && first != last; ++i, ++curr, ++first)
			{
				this->_data[curr] = *first;
			}
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
