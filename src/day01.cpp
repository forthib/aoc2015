#include "io.h"

int main(int argc, char* argv[])
{
	const auto input = io::readLineOfChars("day01_input.txt");
	const auto up    = std::count(input.begin(), input.end(), '(');
	const auto down  = std::count(input.begin(), input.end(), ')');
	std::cout << "Part 1: " << static_cast<int64_t>(up - down) << "\n";

	int64_t floor = 0;
	for (size_t i = 0; i < input.size(); ++i) {
		if (input[i] == '(')
			++floor;
		if (input[i] == ')')
			--floor;
		if (floor == -1) {
			std::cout << "Part 2: " << i + 1 << "\n";
			break;
		}
	}

	std::cin.get();
}