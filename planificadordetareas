#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool cless(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

vector<pair<int, int>> planificador(vector<int> b, vector<int> d, int m) {
	map<int, int, greater<int>> maph;
	for (int i = 0; i < b.size(); i++) {
		maph.insert({ b[i], d[i]});
	}

	vector<pair<int, int>> v;

	for (auto e : maph) {

		vector<pair<int, int>> save = v;
		v.push_back(e);
		sort(v.begin(), v.end(), cless);
		for (int i = 0; i < v.size(); i++) {
			if (v[i].second < i + 1) {
				v = save;
				break;
			}
		}

	}
	return v;
}

int main() {
	vector<int> b = { 20, 15, 10, 7, 5, 3 };
	vector<int> d = { 3, 1, 1, 3, 1, 3 };
	vector<pair<int, int>> x = planificador(b, d, 6);
	for (auto e : x) {
		cout << e.first << "," << e.second << " ";
	}
}
