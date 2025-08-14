#include <iostream>
using namespace std;

void resize(int& tam, int*& vec) {
	int* newvec = new int[tam * 2];
	for (int i = 0; i < tam; i++) {
		newvec[i] = vec[i];
	}
	delete[]vec;
	vec = newvec;
	tam = tam * 2;
}

void insert(int value, int& pos, int& tam, int*& vec) {
	if (pos == tam) {
		resize(tam, vec);
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
	cout << "resize: " << endl;
	for (int i = 10; i < 15; i++) {
		insert(i, pos, tam, vec);
	}
	print(pos, vec);
}
