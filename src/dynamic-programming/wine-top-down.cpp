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

int profit(int i, int j, int y, int *arr, int dp[][100])
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }
    int first = (y * arr[i]) + profit(i + 1, j, y + 1, arr, dp);
    int second = (y * arr[j]) + profit(i, j - 1, y + 1, arr, dp);
    return dp[i][j] = max(first, second);
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

    int dp[100][100] = {0};

    cout << profit(0, n - 1, 1, arr, dp) << endl;
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