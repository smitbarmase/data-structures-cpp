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

// https://hack.codingblocks.com/app/contests/1338/793/problem

int n, g;
int arr[1001][1001];
int dp[1001][1001];

void solve()
{
    cin >> n >> g;
    memset(arr, 0, sizeof arr);
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < g; i++)
    {
        int x, y;
        cin >> x >> y;
        // 1-based indexing
        arr[x - 1][y - 1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1] + arr[i][j];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
            }
        }
    }

    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int first = dp[i - 1][j - 1];
            int second = dp[i - 1][n - 1] - dp[i - 1][j - 1];
            int third = dp[n - 1][j - 1] - dp[i - 1][j - 1];
            int fourth = dp[n - 1][n - 1] - first - second - third;
            int result = min(min(first, second), min(third, fourth));
            ans = max(ans, result);
        }
    }

    cout << ans;
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

    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}