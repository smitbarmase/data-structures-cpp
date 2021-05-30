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

int n;
int arr[22][22];
int dp[22][(~(-1 << 21)) + 1];

int get_pairing(int i, int w)
{
    if (i == n)
    {
        if (w == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[i][w] != -1)
    {
        return dp[i][w];
    }
    int ways = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[i][j] && ((w >> j) & 1))
        {
            ways += get_pairing(i + 1, w & (~(1 << j)));
            ways %= 1000000007;
        }
    }
    return dp[i][w] = ways;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof dp);

    cout << get_pairing(0, ~(-1 << n)) << endl;
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