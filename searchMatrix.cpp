#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ini = 0;
        int fin = matrix[0].size() - 1;
        while (fin >= 0 && ini <= matrix.size() - 1) {
            if (matrix[ini][fin] == target) {
                return true;
            }
            else if (target < matrix[ini][fin]) {
                fin--;
            }
            else if (target > matrix[ini][fin]) {
                ini++;
            }
            
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matriz = { {1,1}
    };
    Solution s;
    cout << s.searchMatrix(matriz, 2) << endl;
}
