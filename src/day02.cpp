#include "io.h"
#include "test.h"
#include <algorithm>

namespace {
	int64_t paper(int64_t dx, int64_t dy, int64_t dz)
	{
		const auto xy = dx * dy;
		const auto yz = dy * dz;
		const auto zx = dz * dx;
		return 2 * xy + 2 * yz + 2 * zx + std::min(std::min(xy, yz), zx);
	}

	int64_t paper(const std::vector<std::vector<int64_t>>& boxes)
	{
		int64_t sum = 0;
		for (const auto& box : boxes)
			sum += paper(box[0], box[1], box[2]);
		return sum;
	}
	
	int64_t ribbon(int64_t dx, int64_t dy, int64_t dz)
	{
		const auto xy = 2 * (dx + dy);
		const auto yz = 2 * (dy + dz);
		const auto zx = 2 * (dz + dx);
		return dx * dy * dz + std::min(std::min(xy, yz), zx);
	}

	int64_t ribbon(const std::vector<std::vector<int64_t>>& boxes)
	{
		int64_t sum = 0;
		for (const auto& box : boxes)
			sum += ribbon(box[0], box[1], box[2]);
		return sum;
	}
}

int main(int argc, char* argv[])
{
	test::equals(paper(2, 3, 4), 58);
	test::equals(paper(1, 1, 10), 43);
	test::equals(ribbon(2, 3, 4), 34);
	test::equals(ribbon(1, 1, 10), 14);


	const auto input = io::readLinesOfIntegers("day02_input.txt", "x");
	std::cout << "Part 1: " << paper(input) << "\n";
	std::cout << "Part 2: " << ribbon(input) << "\n";
	std::cin.get();
}