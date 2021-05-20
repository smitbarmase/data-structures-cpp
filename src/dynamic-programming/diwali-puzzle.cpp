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
#define mod 1000003
#define inf 1e18

int n, k;
int dp[1002][1002][2];

int get_possible(int i, int sum, int prev)
{
    if (i == 0)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }
    // memoization
    if (dp[i][sum][prev] != -1)
    {
        return dp[i][sum][prev];
    }
    int ways = 0;
    // current = 1
    ways += get_possible(i - 1, sum + prev, 1);
    // current = 0
    ways += get_possible(i - 1, sum, 0);
    ways %= mod;
    return dp[i][sum][prev] = ways;
}

void solve()
{
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    cout << get_possible(n, 0, 0) << endl;
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