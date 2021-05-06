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

bool is_valid(int n, int (*matrix)[50], int i, int j)
{
    // Is top column clear
    for (int x = i; x >= 0; x--)
    {
        if (matrix[x][j] != 0)
        {
            return false;
        }
    }

    // Is top left diagonal clear
    for (int x = i, y = j; x >= 0 && y >= 0; x--, y--)
    {
        if (matrix[x][y] != 0)
        {
            return false;
        }
    }

    // Is top right diagonal clear
    for (int x = i, y = j; x >= 0 && y <= n - 1; x--, y++)
    {
        if (matrix[x][y] != 0)
        {
            return false;
        }
    }

    return true;
}

void n_queen(int n, int (*matrix)[50], int i)
{
    // Base case
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Recursive case
    for (int j = 0; j < n; j++)
    {
        if (is_valid(n, matrix, i, j))
        {
            // Placing the queen
            matrix[i][j] = 1;
            n_queen(n, matrix, i + 1);
            // Reverting the queen
            matrix[i][j] = 0;
        }
    }
}

// Let i denote row and j denote column.
// Let y denote row and x denote column.

void solve()
{
    int n;
    cin >> n;
    int matrix[50][50];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    n_queen(n, matrix, 0);
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