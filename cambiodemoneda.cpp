#include <iostream>
#include <map>
#include <vector>
using namespace std;


map<int, int> mo = { {1,200},{2,100}, {3,50}, {4,20}, {5,10}, {6,5}, {7,2}, {8,1} };
vector<int> cambio(int m) {
	vector<int> vc;
	while (m != 0) {
		int r = 0;
		for (auto e : mo) {
			if (e.second > r && e.second <= m) {
				r = e.second;
			}
		}
		vc.push_back(r);
		m -= r;
	}
	return vc;
}

int main() {
	vector<int> vc = cambio(389);
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << " ";
	}
	cout << endl;
}
