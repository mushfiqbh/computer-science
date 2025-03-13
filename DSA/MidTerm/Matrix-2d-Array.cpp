#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;
    int arr[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Row sum
    for (int i = 0; i < row; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < col; j++)
        {
            row_sum += arr[i][j];
        }
        cout << "sum of row " << i + 1 << " is" << " " << row_sum << endl;
    }

    // column sum
    for (int i = 0; i < col; i++)
    {
        int col_sum = 0;
        for (int j = 0; j < row; j++)
        {
            col_sum += arr[j][i];
        }
        cout << "sum of column " << i + 1 << " is" << " " << col_sum << endl;
    }

    // checking identity matrix
    int flag = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j && arr[i][j] != 1)
            {
                flag = 0;
                break;
            }
            else if (i != j && arr[i][j] != 0)
            {
                flag = 0;
                break;
            }
            if (flag == 0)
                break; // main loop break
        }
    }

    if (flag)
        cout << "Identt" << endl;
    else
        cout << "Not Identt" << endl;
}

void transposer(int arr[][3], int row)
{
    int tArr[3][row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tArr[i][j] = arr[j][i];
        }
    }
    print_array(tArr, row);

    return 0;
}

void input_array(int (*arr)[3], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void print_array(int (*arr)[3], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
