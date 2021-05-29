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
int arr[402];
int pre[402];
int dp[402][402];

// from 1 to n
int slimes(int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int sum = pre[j] - pre[i - 1];
    int res = LONG_LONG_MAX;
    for (int k = i; k < j; k++)
    {
        res = min(res, sum + slimes(i, k) + slimes(k + 1, j));
    }
    return dp[i][j] = res;
}

void solve()
{
    cin >> n;
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }

    memset(dp, -1, sizeof dp);

    cout << slimes(1, n) << endl;
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