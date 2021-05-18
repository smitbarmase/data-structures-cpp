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

// Time O(n + k)
// Space O(n)

void solve()
{
    int n, k;
    cin >> n >> k;

    int dp[100] = {0};

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }

    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }

    cout << dp[n] << endl;
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