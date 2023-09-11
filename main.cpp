#include <chrono>

#include "AnGeom.h"

int main() {

	auto A = AnGeom::Vector3D(1, 1, 0.43);
	auto B = AnGeom::Vector3D(4, 4, 4);
	auto C = AnGeom::Vector3D(2, 2, 0);
	auto D = AnGeom::Vector3D(-4, -4, 8.543);

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
