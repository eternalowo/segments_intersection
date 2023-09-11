#ifndef SEGMENT3D_H_
#define SEGMENT3D_H_

#include "Vector3D.h"

namespace AnGeom {

	class Segment3D {

		Vector3D _start, _end;

	public:

		Segment3D(Vector3D& start, Vector3D& end) : _start(start), _end(end) {};

		inline std::pair<Vector3D, Vector3D> get_pos() const {
			// Returns start and end points of segment
			return std::make_pair(_start, _end);
		};

		inline bool is_point() const {
			// Checks if segment start and end are equal
			return _start == _end;
		};

		Vector3D get_vector() const {
			// Returns direction vector of segment
			double x = _end.x() - _start.x();
			double y = _end.y() - _start.y();
			double z = _end.z() - _start.z();

			return Vector3D(x, y, z);
		};
		
		bool operator==(const Segment3D& seg) {
			return ((_start == seg.get_pos().first
				&& _end == seg.get_pos().second) ||
				(_end == seg.get_pos().first
				&& _start == seg.get_pos().second));
		};

		friend std::ostream& operator<<(std::ostream& out, const Segment3D& seg) {
			out << seg.get_pos().first << " --- " << seg.get_pos().second;
			return out;
		};
	};

}; // namespace AnGeom
#endif