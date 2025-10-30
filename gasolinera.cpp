#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> gasolinera(int L, int R, vector<int> gasolineras) {
	vector<int> v;
	int ac = 0;
	while (ac + R < L) {

		int masproximo = 0;
		int diffac = INT_MAX;
		bool determ = false;
		for (int i = 0; i < gasolineras.size(); i++) {
			int diff = abs(ac + R - gasolineras[i]);
			if (diff < diffac && gasolineras[i] <= ac + R && gasolineras[i] > ac) {
				masproximo = gasolineras[i];
				diffac = diff;
				determ = true;
			}
		}
		if (determ == false) {
			cout << "invalido" << endl;
			return v;
		}
		ac += masproximo;
		v.push_back(masproximo);
	}
	return v;
}

int main() {
	vector<int> gasolineras = { 10, 25, 35, 55, 75 };
	vector<int> vc = gasolinera(100, 40, gasolineras);
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << " ";
	}
	cout << endl;

	vector<int> gasolineras2 = { 20, 55 };
	vector<int> vc2 = gasolinera(80, 30, gasolineras2);
	for (int i = 0; i < vc2.size(); i++) {
		cout << vc2[i] << " ";
	}
	cout << endl;
}
