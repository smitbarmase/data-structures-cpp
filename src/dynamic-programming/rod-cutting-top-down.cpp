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

int max_profit(int n, int *arr, int *dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int profit = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int current = arr[i - 1] + max_profit(n - i, arr, dp);
        profit = max(profit, current);
    }
    return dp[n] = profit;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int dp[100] = {0};

    cout << max_profit(n, arr, dp) << endl;
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