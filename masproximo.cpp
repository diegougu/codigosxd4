#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std; 

vector<int> masproximo(vector<vector<int>> grafo, int ini) {
    vector<int> r;
    unordered_set<int> us;
    us.insert(ini);
    r.push_back(ini);
    int i = ini - 1;
    while (r.size() != grafo[ini - 1].size()) {
        int ariless = INT_MAX;
        int node;
        for (int e = 0; e < grafo[i].size(); e++) {
            auto ite = us.find(e + 1);
            if (grafo[i][e] != 0 && grafo[i][e] < ariless && ite == us.end()) {
                ariless = grafo[i][e];
                node = e + 1;
            }
        }
        r.push_back(node);
        us.insert(node);
        i = node - 1;
    }
    return r;
}

int main() {
    vector<vector<int>> grafo = {
        //   1   2   3   4   5
        {   0, 10, 55, 25, 45 }, // 1
        {  10,  0, 20, 25, 40 }, // 2
        {  55, 20,  0, 15, 30 }, // 3
        {  25, 25, 15,  0, 50 }, // 4
        {  45, 40, 30, 50,  0 }  // 5
    };

    vector<int> v = masproximo(grafo, 5);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
