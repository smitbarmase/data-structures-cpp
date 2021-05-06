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

// Now valid checking will be O(1)
bitset<40> col, d1, d2;

void n_queen(int n, int (*matrix)[20], int i, int &count)
{
    // Base case
    if (i == n)
    {
        count++;
        return;
    }

    // Recursive case
    for (int j = 0; j < n; j++)
    {
        if (!col[j] && !d1[i + j] && !d2[i - j + n - 1])
        {
            col[j] = d1[i + j] = d2[i - j + n - 1] = 1;
            n_queen(n, matrix, i + 1, count);
            col[j] = d1[i + j] = d2[i - j + n - 1] = 0;
        }
    }
}

// Let i denote row and j denote column.

void solve()
{
    int n;
    cin >> n;
    int matrix[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }

    int count = 0;
    n_queen(n, matrix, 0, count);
    cout << count << endl;
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