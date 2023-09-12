#include "AnGeom.h"

namespace AnGeom {

	const double INF = std::numeric_limits<double>::infinity();

	// Calculates 2x2 determinant
	inline double det2x2(double a, double b, double c, double d) { return a * d - c * b; };

	inline double dot_product(const Vector3D& first, const Vector3D& second) {
		// Returns dot product of two 3D vectors
		return (first.x() * second.x())
			+ (first.y() * second.y())
			+ (first.z() * second.z());
	};

	bool is_connected(const Segment3D& first, const Segment3D& second) {
		// Checking if ends of both segments is connected
		if (first.get_pos().first == second.get_pos().first
			|| first.get_pos().first == second.get_pos().second
			|| first.get_pos().second == second.get_pos().first
			|| first.get_pos().second == second.get_pos().second)
			return true;

		return false;
	}

	bool is_collinear(const Vector3D& first, const Vector3D& second) {
		// Checking vectors for collinearity
		return (((abs(first.x() / second.x() - first.y() / second.y())) < EPS)
			&& ((abs(first.y() / second.y() - first.z() / second.z())) < EPS));
	};

	Vector3D connection_point(const Segment3D& first, const Segment3D& second) {
		// Returns the connection point of the ends of the segments

		if (first.get_pos().first == second.get_pos().first)
			return first.get_pos().first;
		else if (first.get_pos().first == second.get_pos().second)
			return first.get_pos().first;
		else if (first.get_pos().second == second.get_pos().first)
			return first.get_pos().second;
		else if (first.get_pos().second == second.get_pos().second)
			return first.get_pos().second;

		return Vector3D(INF, INF, INF);
	}

	bool is_point_on_segment(const Vector3D& point, const Segment3D& segment) {

		// Checking if point lies on segment using dot product
		Vector3D vec1 = segment.get_pos().second - segment.get_pos().first;
		Vector3D vec2 = point - segment.get_pos().first;

		double dot = dot_product(vec1, vec2);
		double len_mult = vec1.get_length() * vec2.get_length();

		if (abs(len_mult - dot) < EPS && (vec2.get_length() < vec1.get_length()))
			return true;

		return false;
	};

	bool is_on_one_plain(const Segment3D& first, const Segment3D& second) {
		// Checking if both segments belong to one plane using triple scalar product

		Vector3D first_vec = first.get_pos().second - first.get_pos().first;
		Vector3D second_vec = first.get_pos().second - second.get_pos().first;
		Vector3D normal = first_vec * second_vec;
		if (normal == Vector3D(0.0, 0.0, 0.0))
			return true;
		return (abs(dot_product(normal, first.get_pos().second - second.get_pos().second)) < EPS);
	};

	Vector3D intersect(Segment3D& first, Segment3D& second) {
		// Function that finds intersection point of two segments.
		// If the segments do not intersect, or have an infinite
		// number of intersection points returns Vector3D(INF, INF, INF)

		// Checking if segments are equal
		if (first == second)
			return Vector3D(INF, INF, INF);
		// Checking if first segment is a point and if it lies on the second segment
		if (first.is_point())
			return is_point_on_segment(first.get_pos().first, second) ? first.get_pos().first : Vector3D(INF, INF, INF);
		// Checking if second segment is a point and if it lies on the first segment
		else if (second.is_point())
			return is_point_on_segment(second.get_pos().first, first) ? second.get_pos().first : Vector3D(INF, INF, INF);
		// Checking if segments has connection point 
		if (is_connected(first, second))
			return connection_point(first, second);;
		// Checking if direction vectors are collinear
		if (is_collinear(first.get_vector(), second.get_vector()))
			return Vector3D(INF, INF, INF);
		// Checking if segments belong to one plain
		if (is_on_one_plain(first, second)) {
			double u = -1, v = -1;

			Vector3D A = first.get_pos().first, B = first.get_pos().second,
				C = second.get_pos().first, D = second.get_pos().second;
			Vector3D v1 = first.get_vector(), v2 = second.get_vector();

			// Solving system of linear equations using Cramer's rule
			u = det2x2(D.y() - B.y(), D.y() - C.y(), D.z() - B.z(), D.z() - C.z())
				/ det2x2(A.y() - B.y(), D.y() - C.y(), A.z() - B.z(), D.z() - C.z());
			v = det2x2(A.y() - B.y(), D.y() - B.y(), A.z() - B.z(), D.z() - B.z())
				/ det2x2(A.y() - B.y(), D.y() - C.y(), A.z() - B.z(), D.z() - C.z());

			if (std::isnan(u) || std::isnan(v)) {
				u = det2x2(D.x() - B.x(), D.x() - C.x(), D.z() - B.z(), D.z() - C.z())
					/ det2x2(A.x() - B.x(), D.x() - C.x(), A.z() - B.z(), D.z() - C.z());
				v = det2x2(A.x() - B.x(), D.x() - B.x(), A.z() - B.z(), D.z() - B.z())
					/ det2x2(A.x() - B.x(), D.x() - C.x(), A.z() - B.z(), D.z() - C.z());
			}

			else if (std::isnan(u) || std::isnan(v)) {
				u = det2x2(D.x() - B.x(), D.x() - C.x(), D.y() - B.y(), D.y() - C.y())
					/ det2x2(A.x() - B.x(), D.x() - C.x(), A.y() - B.y(), D.y() - C.y());
				v = det2x2(A.x() - B.x(), D.x() - B.x(), A.y() - B.y(), D.y() - B.y())
					/ det2x2(A.x() - B.x(), D.x() - C.x(), A.y() - B.y(), D.y() - C.y());
			}

			if ((u > EPS && u < 1.0 + EPS) && (v > EPS && v < 1.0 + EPS))
				return Vector3D(u * (A.x() - B.x()) + B.x(), u * (A.y() - B.y()) + B.y(), u * (A.z() - B.z()) + B.z());
			
			double x = (A.x() * v1.y() * v2.x() - C.x() * v2.y() * v1.x() - A.y() * v1.x() * v2.x() + C.y() * v1.x() * v2.x())
				/ (v1.y() * v2.x() - v2.y() * v1.x());

			double y = (A.y() * v1.x() * v2.y() - C.y() * v2.x() * v1.y() - A.x() * v1.y() * v2.y() + C.x() * v1.y() * v2.y())
				/ (v1.x() * v2.y() - v2.x() * v1.y());

			double z = (A.z() * v1.y() * v2.z() - C.z() * v2.y() * v1.z() - A.y() * v1.z() * v2.z() + C.y() * v1.z() * v2.z())
				/ (v1.y() * v2.z() - v2.y() * v1.z());

			if (!std::isnan(x))
				u = (x - B.x()) / (A.x() - B.x());
			else if (!std::isnan(y))
				u = (y - B.y()) / (A.y() - B.y());
			else if (!std::isnan(z))
				u = (z - B.z()) / (A.z() - B.z());

			if (u > EPS && u < 1.0 + EPS)
				return Vector3D(u * (A.x() - B.x()) + B.x(), u * (A.y() - B.y()) + B.y(), u * (A.z() - B.z()) + B.z());
		}
		return Vector3D(INF, INF, INF);
	};

}; // namespace AnGeom
