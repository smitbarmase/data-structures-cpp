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

int get_ways(const int n, const int m, int (*matrix)[50], int i, int j)
{
    // Base case
    // Boundaries
    if (i >= n || j >= m || i < 0 || j < 0)
    {
        return 0;
    }
    // Goal
    if (i == n - 1 && j == m - 1)
    {
        matrix[m - 1][n - 1] = 2;
        // Print
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cout << matrix[j][i] << " ";
            }
            cout << endl;
        }
        cout << endl;
        matrix[m - 1][n - 1] = 0;
        return 1;
    }
    // Block
    if (matrix[j][i] == 1)
    {
        return 0;
    }

    // Recursive case

    // Assume this is the path
    matrix[j][i] = 2;

    // Get number of ways
    int left = get_ways(n, m, matrix, i + 1, j);
    int down = get_ways(n, m, matrix, i, j + 1);
    int result = left + down;

    // Remove path while backtracking
    matrix[j][i] = 0;

    return result;
}

// Source => (0, 0)
// Destination => (n - 1, m - 1)
// Blocks denoted as 1, Free space denoted as 0

// Print all possible paths and count number of it.
// Use 2 for printing the path.

// Input:
// 1
// 4 4
// 0 0 0 0
// 0 0 1 0
// 1 0 0 0
// 0 0 1 0

// Output:
// 2 2 2 2
// 0 0 1 2
// 1 0 0 2
// 0 0 1 2

// 2 2 0 0
// 0 2 1 0
// 1 2 2 2
// 0 0 1 2

// 2 0 0 0
// 2 2 1 0
// 1 2 2 2
// 0 0 1 2

// 3

void solve()
{
    int n, m;
    cin >> n >> m;
    int matrix[50][50];

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> matrix[j][i];
        }
    }

    cout << get_ways(n, m, matrix, 0, 0) << endl;
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