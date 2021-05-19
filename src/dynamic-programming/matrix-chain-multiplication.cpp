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

// Input
// 3
// 5
// 40 20 30 10 30
// 5
// 10 20 30 40 30
// 3
// 10 20 30

// Output
// 26000
// 30000
// 6000

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int num = n - 1;
    int dp[100][100] = {0};

    for (int i = 1; i < num; i++)
    {
        int r = 0, c = i;
        while (c < num)
        {
            int val = INT_MAX;
            for (int k = r; k < c; k++)
            {
                int cost = arr[r] * arr[k + 1] * arr[c + 1];
                val = min(val, dp[r][k] + dp[k + 1][c] + cost);
            }
            dp[r][c] = val;
            r++, c++;
        }
    }
    cout << dp[0][num - 1] << endl;
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