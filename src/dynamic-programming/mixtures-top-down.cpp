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

// https://www.spoj.com/problems/MIXTURES/

int sum_smoke(int i, int j, int *arr)
{
    int sum = 0;
    for (int k = i; k <= j; k++)
    {
        sum += arr[k];
        sum %= 100;
    }
    return sum;
}

int get_smoke(int i, int j, int *arr, int dp[][102])
{
    // base case
    if (i == j)
    {
        return 0;
    }
    // memoization
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }
    // recursive case
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // making two partion from i to k and k + 1 to j
        int first = get_smoke(i, k, arr, dp);
        int second = get_smoke(k + 1, j, arr, dp);
        int self = sum_smoke(i, k, arr) * sum_smoke(k + 1, j, arr);
        dp[i][j] = min(dp[i][j], first + second + self);
    }
    return dp[i][j];
}

void solve()
{
    int n;
    while (cin >> n)
    {
        int arr[n];
        int dp[102][102] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << get_smoke(0, n - 1, arr, dp) << endl;
    }
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

    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}