#include <iostream>
using namespace std;

void insert(int value, int& pos, int& tam, int* vec) {
	if (pos == tam) {
		return;
	}
	vec[pos] = value;
	pos++;
}

void print(int pos, int* vec) {
	for (int i = 0; i < pos; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main() {
	int pos = 0;
	int tam;
	cout << "ingresa el tamaño del vector: ";
	cin >> tam;
	cout << endl;
	int* vec = new int[tam];
	for (int i = 0; i < 10; i++) {
		insert(i, pos, tam, vec);
	}
	print(pos, vec);
}
