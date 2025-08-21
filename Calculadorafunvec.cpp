#include <iostream>
#include <vector>
using namespace std;

float Addition(float a, float b) {
	return a + b;
}

float Subtraction(float a, float b) {
	return a - b;
}

float Multiplication(float a, float b) {
	return a * b;
}

float Division(float a, float b) {
	try {
		if (b == 0.0) {
			throw std::runtime_error("esta mal xd");
		}
		return a / b;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main() {
	typedef float (*lpfnOperation)(float, float);
	lpfnOperation vpf[4] = { &::Addition, &::Subtraction,
	&::Multiplication, &::Division };



	float a, b, c; int opt;
	cin >> a >> b;
	cin >> opt;
	c = (*vpf[opt])(a, b);
	cout << c << endl;

}
