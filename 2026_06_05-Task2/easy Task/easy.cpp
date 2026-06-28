#include <iostream>
#include <vector>
#include <algorithm>

// Using the standard namespace
using namespace std;

void sortMatrixStrictly(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return;

    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<int> flattened;
    flattened.reserve(m * n); 
    
    for (const auto& row : matrix) {
        for (int val : row) {
            flattened.push_back(val);
        }
    }

    // No need for std::sort, just sort
    sort(flattened.begin(), flattened.end());

    int index = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = flattened[index++];
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " "; // No need for std::cout
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> matrix = {
        {5, 4, 7},
        {1, 3, 8},
        {2, 9, 6}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    sortMatrixStrictly(matrix);

    cout << "\nStrictly Sorted Matrix:\n";
    printMatrix(matrix);

    return 0;
}