#include <bits/stdc++.h>
using namespace std;

int n;
void printsol(vector<vector<int>> board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool issafe(int row, int col, vector<bool> rows, vector<bool> left_diagonals, vector<bool> right_diagonals)
{
    if (rows[row] == true || left_diagonals[col + row] == true || right_diagonals[col - row + n - 1] == true)
        return false;

    return true;
}

bool solve(vector<vector<int>> &board, int col, vector<bool> rows, vector<bool> left_diagonals, vector<bool> right_diagonals)
{
    if (col >= n)
        return true; // base condition : if all the queens are placed

    for (int i = 0; i < n; i++)
    {
        if (issafe(i, col, rows, left_diagonals, right_diagonals) == true)
        {
            rows[i] = true;
            left_diagonals[i + col] = true;
            right_diagonals[col - i + n - 1] = true;
            board[i][col] = 1;

            // recur to place rest of the queens
            if (solve(board, col + 1, rows, left_diagonals, right_diagonals) == true)
                return true;

            // back tracking
            rows[i] = false;
            left_diagonals[i + col] = false;
            right_diagonals[col - i + n - 1] = false;
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{

    cout << "Enter the number of board for the chess : " << endl;
    cin >> n;

    //  create a board of n*n size
    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<bool> rows(n, false);
    vector<bool> left_diagonals(2 * n - 1, false);
    vector<bool> right_diagonals(2 * n - 1, false);

    bool ans = solve(board, 0, rows, left_diagonals, right_diagonals);
    if (ans == true)
        printsol(board);
    else
        cout << "solution does not exist" << endl;
    return 0;
}