#include <iostream>
using namespace std;

class Vector {
public:
	int tam;
	Vector(int t) : tam(t) {}
	void insert(int v);
	void print();
private:
	int elementos = 0;
	int* arr = new int[tam];
	void ExpandOrColapse(int newtam);
};


void Vector::ExpandOrColapse(int newtam) {
	int* arrnew = new int[newtam];
	for (int i = 0; i < tam; i++) {
		arrnew[i] = arr[i];
	}
	tam = newtam;
	int* temp = arr;
	arr = arrnew;
	delete temp;
}

void Vector::insert(int v) {
	if (elementos == tam) {
		ExpandOrColapse(tam * 2);
	}
	arr[elementos] = v;
	elementos++;
}

void Vector::print() {
	for (int i = 0; i < elementos; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	Vector vec(10);
	for (int i = 0; i < 10; i++) {
		vec.insert(i);
	}
	vec.print();
	for (int i = 10; i < 15; i++) {
		vec.insert(i);
	}
	vec.print();

}
