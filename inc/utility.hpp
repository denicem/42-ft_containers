#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft {

template < class T, class V>
class pair {
	public:
	/*
	** ----------------------- MEMBER TYPES -----------------------
	*/
		typedef	T								first_type;
		typedef V								second_type;
		typedef pair<first_type, second_type>	value_type;

		T first;
		V second;

		pair(): first(first_type()), second(second_type()) {}
		pair(const value_type& pr): first(pr.first), second(pr.second) {}
		pair(const first_type& a, const second_type& b): first(a), second(b) {}

};

} // END NAMESPACE FT

#endif
