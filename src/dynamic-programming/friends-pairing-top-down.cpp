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

int num_of_ways(int n, int *dp)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    // memoization
    if (dp[n] != 0)
    {
        return dp[n];
    }
    // recursive case
    return dp[n] = num_of_ways(n - 1, dp) + ((n - 1) * num_of_ways(n - 2, dp));
}

void solve()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << num_of_ways(n, dp) << endl;
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