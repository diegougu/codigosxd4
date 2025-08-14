#include <iostream>
using namespace std;

template <typename T>
class Vector {
public:
	int tam;
	Vector(int t) : tam(t) {}
	void insert(int v);
	void print();
private:
	int elementos = 0;
	T* arr = new T[tam];
	void resize(int newtam);
};

template <typename T>
void Vector<T>::resize(int newtam) {
	T* arrnew = new T[newtam];
	for (int i = 0; i < tam; i++) {
		arrnew[i] = arr[i];
	}
	tam = newtam;
	int* temp = arr;
	arr = arrnew;
	delete temp;
}

template <typename T>
void Vector<T>::insert(int v) {
	if (elementos == tam) {
		resize(tam * 2);
	}
	arr[elementos] = v;
	elementos++;
}

template <typename T>
void Vector<T>::print() {
	for (int i = 0; i < elementos; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	Vector<int> vec(10);
	for (int i = 0; i < 10; i++) {
		vec.insert(i);
	}
	vec.print();
	for (int i = 10; i < 15; i++) {
		vec.insert(i);
	}
	vec.print();

}
