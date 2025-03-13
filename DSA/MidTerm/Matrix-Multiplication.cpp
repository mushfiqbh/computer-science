#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row1, col1, row2, col2;
    cout << "Enter first Matrix row & col" << endl;
    cin >> row1 >> col1;
    cout << "Enter 2nd Matrix row & col" << endl;
    cin >> row2 >> col2;

    if (col1 != row2) {
        cout << "Matrix Multiplication is not possible" << endl;
        return 0;
    }

    int mat1[row1][col1];
    int mat2[row2][col2];
    int result[row1][col2]; // (M x N) * (N x P) = (M x P)

    cout << "Enter elements of the first Matrix:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter elements of the second Matrix:" << endl;
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> mat2[i][j];
        }
    }

    // Calculation Process
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout << "Result of Multiplication:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}