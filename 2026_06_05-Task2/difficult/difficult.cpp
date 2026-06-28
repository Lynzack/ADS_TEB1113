#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define N 5

int findMaxValue(int mat[N][N]) {
    // Stores the maximum value found so far
    int max_diff = INT_MIN;

    // max_mat[i][j] will store the maximum element in the submatrix
    // from mat[i][j] to mat[N-1][N-1]
    int max_mat[N][N];

    // The last element of max_mat will be the same as mat
    max_mat[N-1][N-1] = mat[N-1][N-1];

    // Preprocess the last row
    int max_val = mat[N-1][N-1];
    for (int j = N - 2; j >= 0; j--) {
        if (mat[N-1][j] > max_val) {
            max_val = mat[N-1][j];
        }
        max_mat[N-1][j] = max_val;
    }

    // Preprocess the last column
    max_val = mat[N-1][N-1];
    for (int i = N - 2; i >= 0; i--) {
        if (mat[i][N-1] > max_val) {
            max_val = mat[i][N-1];
        }
        max_mat[i][N-1] = max_val;
    }

    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 2; j >= 0; j--) {
            // Check if the current choice gives a spectacular maximum difference
            int current_max_reformed = max(max_mat[i+1][j+1], max(max_mat[i+1][j], max_mat[i][j+1]));
            
            if (current_max_reformed - mat[i][j] > max_diff) {
                max_diff = current_max_reformed - mat[i][j];
            }

            // Fixed the typo here: changed max_max_reformed to current_max_reformed
            max_mat[i][j] = max(mat[i][j], current_max_reformed);
        }
    }

    return max_diff;
}

int main() {
    int mat[N][N] = {
        { 1, 2, -1, -4, -20 },
        { -8, -3, 4, 2, 1 },
        { 3, 8, 6, 1, 3 },
        { -4, -1, 1, 7, -6 },
        { 0, -4, 10, -5, 1 }
    };

    cout << "Maximum value is " << findMaxValue(mat) << endl;

    return 0;
}