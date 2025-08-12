//Using backtracking algorithm Implement N-queens
//problem.

#include<iostream>
using namespace std;

int count = 0;

bool place(int row, int col, int n, int chess[][20]) {
    int r = row, c = col;
    while (r >= 0 && c >= 0) {
        if (chess[r][c] == 1)
            return false;
        r--; c--;
    }
    r = row; c = col;
    while (c >= 0) {
        if (chess[r][c] == 1)
            return false;
        c--;
    }
    r = row; c = col;
    while (c >= 0 && r<n) {
        if (chess[r][c] == 1)
            return false;
        r++; c--;
    }
    return true;
}

void nq(int col, int n, int chess[][20]) {
    if (col >= n) {
        count++;
        return;
    }
    for (int row = 0; row < n; row++) {
        if (place(row, col, n, chess)) {
            chess[row][col] = 1;
            nq(col + 1, n, chess);
            chess[row][col] = 0;
        }
    }
}

int main() {
    int n;
   cout << "Enter number of queens (chessboard will be n x n): ";
    cin >> n;
    int chess[20][20] = {0};
    nq(0, n, chess);
    cout <<"Total possible combination: "<< count<<endl<<endl;
    return 0;
}

//Result:
// Enter number of queens (chessboard will be n x n): 8
// Total possible combination: 92