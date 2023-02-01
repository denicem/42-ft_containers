#ifndef VECT3_HPP
#define VECT3_HPP

#include <ostream>

struct Vect3 {
	int x, y, z;

	Vect3(int x, int y, int z): x(x), y(y), z(z) {}

	friend std::ostream& operator<<(std::ostream& stream, vect3& v3) {
		stream << "[" << v3.x << " " << v3.y << " " << v3.z << "]";
		return (stream);
	}
};

#endif
