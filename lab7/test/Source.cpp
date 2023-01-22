#include <fstream>

int main() {
	srand(time(NULL));
	std::ofstream out;
	out.open("D:\\nums.txt", std::ios::out);
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 3; j++) {
			out << rand() % 50 + 1 - 24 << " ";
		}
		out << '\n';
	}
}