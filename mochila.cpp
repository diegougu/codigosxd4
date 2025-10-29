#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


struct BenterP {
	int i;
	float bsp;
};

bool Greatbsp(BenterP a, BenterP b) {
	return a.bsp > b.bsp;
}

float mochila(float m, vector<float> p, vector<float> b, vector<float>& x) {
	vector<BenterP> vc(p.size());
	for (int i = 0; i < vc.size(); i++) {
		vc[i].i = i;
		vc[i].bsp = b[i] / p[i];
	}

	float totalp = 0;
	float totalb = 0;

	sort(vc.begin(), vc.end(), Greatbsp);

	for (auto e : vc) {
		if (totalp + p[e.i] <= m) {
			totalp += p[e.i];
			totalb += b[e.i];
			x[e.i] = 1;
		}
		else {
			float ope = (m - totalp) / p[e.i];
			totalp = m;
			totalb += b[e.i] * ope;
			x[e.i] = ope;
		}
	}
	return totalb;
	
}



int main() {
	float M = 20;
	vector<float> b = { 25,24,15 };
	vector<float> p = { 18,15,10 };
	vector<float> x(b.size());
	float bTotal = mochila(M, p, b, x);
	for (auto it : x) {
		cout << it << " ";
	}

}
