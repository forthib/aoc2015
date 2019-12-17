#include "io.h"

int main(int argc, char* argv[])
{
	const size_t i = 2978 - 1;
	const size_t j = 3083 - 1;
	const size_t n = (i + j) * (i + j + 1) / 2 + j;

	size_t value = 20151125;
	for (size_t k = 0; k < n; ++k) {
		value = (value * 252533) % 33554393;
	}
	std::cout << "Part 1: " << value << "\n";

	std::cin.get();
}