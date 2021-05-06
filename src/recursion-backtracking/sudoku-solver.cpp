#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pq priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18

bool is_valid(int (*matrix)[9], int i, int j, int num)
{
    // Check row
    for (int x = 0; x < 9; x++)
    {
        if (matrix[j][x] == num)
        {
            return false;
        }
    }

    // Check column
    for (int y = 0; y < 9; y++)
    {
        if (matrix[y][i] == num)
        {
            return false;
        }
    }

    // Check sub grid 3 x 3
    int si = (i / 3) * 3;
    int sj = (j / 3) * 3;
    for (int y = sj; y < sj + 3; y++)
    {
        for (int x = si; x < si + 3; x++)
        {
            if (matrix[y][x] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int (*matrix)[9], int i, int j)
{
    // Base case
    // If we reached later last row
    if (j == 9)
    {
        return true;
    }

    // Recursive case
    // If we passed last column
    if (i == 9)
    {
        return solve_sudoku(matrix, 0, j + 1);
    }

    if (matrix[j][i] != 0)
    {
        // Move on
        return solve_sudoku(matrix, i + 1, j);
    }

    // Put valid number
    for (int num = 1; num <= 9; num++)
    {
        if (is_valid(matrix, i, j, num))
        {
            matrix[j][i] = num;
            bool possible = solve_sudoku(matrix, i + 1, j);
            if (possible)
            {
                return true;
            }
        }
    }
    matrix[j][i] = 0;
    return false;
}

void solve()
{
    int matrix[9][9];

    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            cin >> matrix[j][i];
        }
    }

    bool possible = solve_sudoku(matrix, 0, 0);

    if (possible)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int i = 0; i < 9; i++)
            {
                cout << matrix[j][i] << " ";
            }
            cout << endl;
        }
        return;
    }

    cout << "Not possible." << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}