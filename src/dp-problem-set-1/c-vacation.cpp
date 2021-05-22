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
    int arr[100002][3];
    int dp[2][3];

    memset(arr, 0, sizeof arr);
    memset(dp, 0, sizeof dp);

    int n;
    cin >> n;

    // take input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    // fill last row of dp
    dp[1][0] = arr[n - 1][0];
    dp[1][1] = arr[n - 1][1];
    dp[1][2] = arr[n - 1][2];

    for (int i = n - 2; i >= 0; i--)
    {
        // fill 0th index
        dp[0][0] = arr[i][0] + max(dp[1][1], dp[1][2]);

        // fill 1th index
        dp[0][1] = arr[i][1] + max(dp[1][0], dp[1][2]);

        // fill 2th index
        dp[0][2] = arr[i][2] + max(dp[1][0], dp[1][1]);

        // shift the dp
        dp[1][0] = dp[0][0];
        dp[1][1] = dp[0][1];
        dp[1][2] = dp[0][2];
    }

    cout << max(dp[1][2], max(dp[1][0], dp[1][1])) << endl;
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