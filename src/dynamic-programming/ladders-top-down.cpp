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

// Time O(n * k)
// Space O(n)

int num_of_ways(int n, int k, int *dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int total = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            total += num_of_ways(n - i, k, dp);
        }
    }
    return dp[n] = total;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int dp[100] = {0};

    cout << num_of_ways(n, k, dp) << endl;
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