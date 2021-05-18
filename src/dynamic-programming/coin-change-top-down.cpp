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

int coin_change(int n, int *coins, int size, int *dp)
{
    // base
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    // recursive
    int ans = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        int remain = n - coins[i];
        if (remain >= 0)
        {
            ans = min(ans, coin_change(remain, coins, size, dp));
        }
    }
    dp[n] = 1 + ans;
    return dp[n];
}

void solve()
{
    int n;
    cin >> n;
    int dp[10001] = {0};
    int coins[] = {1, 7, 10};
    int size = sizeof(coins) / sizeof(coins[0]);
    cout << coin_change(n, coins, size, dp) << endl;
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