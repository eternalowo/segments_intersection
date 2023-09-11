#ifndef VECTOR3D_H_
#define VECTOR3D_H_

#include <vector>
#include <cmath>
#include <iostream>

namespace AnGeom {

	const double EPS = 1.0e-6;

	class Vector3D {

		double X, Y, Z;

	public:

		Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {};

		inline double x() const { return X; };
		inline double y() const { return Y; };
		inline double z() const { return Z; };

		inline double get_length() const {
			// Returns length of vector
			return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
		};

		Vector3D operator*(const Vector3D& vec) const {
			// Cross product operator
			double x = (Y * vec.z() - vec.y() * Z);
			double y = -(X * vec.z() - vec.x() * Z);
			double z = (X * vec.y() - vec.x() * Y);

			return Vector3D(x, y, z);
		};

		Vector3D operator-(const Vector3D& vec) const {

			double x = vec.x() - X;
			double y = vec.y() - Y;
			double z = vec.z() - Y;

			return Vector3D(x, y, z);

		};

		bool operator==(const Vector3D& vec) const {
			return (abs(X - vec.x()) < EPS && abs(Y - vec.y()) < EPS && abs(Z - vec.z()) < EPS);
		};

		friend std::ostream& operator<< (std::ostream& out, const Vector3D& vec) {
			out << "(" << vec.x() << ", " << vec.y() << ", " << vec.z() << ")";
			return out;
		};
	};

}; // namespace AnGeom

#endif