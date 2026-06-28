#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate180(vector<vector<int>>& mat) {
    int n = mat.size();
    
    // Iterate through the rows up to the middle
    for (int i = 0; i < (n + 1) / 2; ++i) {
        // For the middle row (if n is odd), we only need to loop through half the columns
        int max_cols = (i == n - 1 - i) ? n / 2 : n;
        
        for (int j = 0; j < max_cols; ++j) {
            // Swap the element with its diagonally opposite counterpart
            swap(mat[i][j], mat[n - 1 - i][n - 1 - j]);
        }
    }
}

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(mat);

    rotate180(mat);

    cout << "\nMatrix Rotated by 180 Degrees:\n";
    printMatrix(mat);

    return 0;
};