#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ini = 0;
        int fin = matrix[0].size() - 1;
        while (fin >= 0 && ini <= matrix[0].size() - 1) {
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
    vector<vector<int>> matriz = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    Solution s;
    cout << s.searchMatrix(matriz, 5) << endl;
    cout << s.searchMatrix(matriz, 20) << endl;
}
