#include <chrono>

#include "AnGeom.h"

int main() {

	auto A = AnGeom::Vector3D(0, 0, 0);
	auto B = AnGeom::Vector3D(3, 3, 3);
	auto C = AnGeom::Vector3D(4, 4, 4);
	auto D = AnGeom::Vector3D(5, 6, 6);

	auto AB = AnGeom::Segment3D(A, B);
	auto CD = AnGeom::Segment3D(C, D);

	auto t1 = std::chrono::high_resolution_clock::now();
	auto result = AnGeom::intersect(AB, CD);
	auto t2 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> time = (t2 - t1);

	std::cout << "Function work time measure: " << time.count() << std::endl;
	std::cout << result;
	return 0;
};
