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

void solve()
{
    int h, w;
    cin >> h >> w;
    string grid[1001];
    for (int i = 0; i < h; i++)
    {
        cin >> grid[i];
    }

    int dp[1001][1001];

    memset(dp, 0, sizeof dp);

    // top left corner
    dp[0][0] = 0;

    // left most
    for (int i = 1; i < h; i++)
    {
        if (grid[i][0] == '.')
        {
            dp[i][0] = 1;
        }
        else
        {
            break;
        }
    }

    // top most
    for (int j = 1; j < w; j++)
    {
        if (grid[0][j] == '.')
        {
            dp[0][j] = 1;
        }
        else
        {
            break;
        }
    }

    // remaining
    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
        {
            if (grid[i][j] == '.')
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= 1000000007;
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;
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

    solve();
    return 0;
}