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

// Input:
// 1
// 4 4
// 1 1 1 1
// 1 0 1 1
// 1 1 0 1
// 1 1 1 1

void solve()
{
    int n, m;
    cin >> n >> m;
    int grid[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ways[n][m];

    memset(ways, 0, sizeof ways);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                ways[i][j] = 1;
            }
            else if (i == 0)
            {
                if (grid[i][j])
                {
                    ways[i][j] = 1;
                }
                else
                {
                    break;
                }
            }
            else if (j == 0)
            {
                if (grid[i][j])
                {
                    ways[i][j] = 1;
                }
                else
                {
                    break;
                }
            }
            else if (j > 0 && i > 0)
            {
                if (grid[i][j])
                {
                    ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
                }
                else
                {
                    ways[i][j] = 0;
                }
            }
        }
    }

    cout << ways[n - 1][m - 1] << endl;
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