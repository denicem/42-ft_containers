#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>

namespace ft {

template < class T1, class T2 >
struct pair {
		typedef	T1								first_type;
		typedef T2								second_type;
		typedef pair<first_type, second_type>	value_type;

		first_type	first;
		second_type	second;

		pair(): first(first_type()), second(second_type()) {}
		template < class U1, class U2 >
		pair(const pair<U1, U2>& pr): first(pr.first), second(pr.second) {}
		pair(const first_type& a, const second_type& b): first(a), second(b) {}
		~pair() {}

		pair& operator=(const pair& pr) {
			if (this != &pr) {
				this->first = pr.first;
				this->second = pr.second;
			}
			return (*this);
		}
	friend std::ostream& operator<<(std::ostream& stream, const pair& pr) {
		stream << pr.first << ": " << pr.second;
		return (stream);
	}
};

template < class T1, class T2 >
pair<T1, T2> make_pair(T1 x, T2 y) { return pair<T1, T2>(x, y); }

template <class T1, class T2>  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return ((lhs.first == rhs.first) && (lhs.second == rhs.second)); }
template <class T1, class T2>  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); }
template <class T1, class T2>  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return ((lhs.first < rhs.first) && (lhs.second < rhs.second)); }
template <class T1, class T2>  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); }
template <class T1, class T2>  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (rhs < lhs); }
template <class T1, class T2>  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs < rhs); }

} // END NAMESPACE FT

#endif
