#ifndef ANGEOM_H_
#define ANGEOM_H_

#include "Segment3D.h"

namespace AnGeom {

	inline double det2x2(double a, double b, double c, double d);

	inline double dot_product(const Vector3D& first, const Vector3D& second);

	bool is_connected(const Segment3D& first, const Segment3D& second);

	bool is_collinear(const Vector3D& first, const Vector3D& second);

	Vector3D connection_point(const Segment3D& first, const Segment3D& second);

	bool is_point_on_segment(const Vector3D& point, const Segment3D& segment);

	bool is_on_one_plain(const Segment3D& first, const Segment3D& second);

	Vector3D intersect(Segment3D& first, Segment3D& second);

}; // namespace AnGeom

#endif