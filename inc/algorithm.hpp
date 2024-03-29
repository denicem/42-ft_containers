#ifndef FT_ALGORITHM_HPP
#define FT_ALGORITHM_HPP

namespace ft {

template < class T >
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

/* true if all the elements in the range [first1,last1) compare equal to those of the range starting at first2, and false otherwise.*/
template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 ) {
	while (first1 != last1) {
		if (!(*first1 == *first2))
			return (false);
		++first1; ++first2;
	}
	return (true);
}
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
	while (first1 != last1) {
		if (!pred(*first1 == *first2))
			return (false);
		++first1; ++first2;
	}
	return (true);
}

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
	while (first1 != last1) {
		if (first2 == last2 || *first2 < *first1) return (false);
		else if (*first1 < *first2) return (true);
		++first1; ++first2;
	}
	return (first2 != last2);
}
template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
	while (first1 != last1) {
		if (comp(first2 == last2 || *first2 < *first1)) return (false);
		else if (comp(*first1 < *first2)) return (true);
		++first1; ++first2;
	}
	return (first2 != last2);
}

} // END NAMESPACE FT

#endif
