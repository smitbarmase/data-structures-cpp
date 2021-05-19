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

// https://codeforces.com/problemset/problem/682/D

int n, m, k;
string a, b;

int dp[1005][1005][12][2];

int get_alyona_a_number(int i, int j, int rem, int con)
{
    if (i == n || j == m)
    {
        return ((rem == 0) ? 0 : INT_MIN);
    }
    if (rem == 0)
    {
        return 0;
    }
    if (dp[i][j][rem][con] != -1)
    {
        return dp[i][j][rem][con];
    }
    int res = INT_MIN;
    res = max(res, get_alyona_a_number(i + 1, j, rem - con, 0));
    res = max(res, get_alyona_a_number(i, j + 1, rem - con, 0));
    if (a[i] == b[j])
    {
        res = max(res, 1 + get_alyona_a_number(i + 1, j + 1, rem, 1));
        res = max(res, 1 + get_alyona_a_number(i + 1, j + 1, rem - 1, 0));
    }
    return dp[i][j][rem][con] = res;
}

void solve()
{
    cin >> n >> m >> k;
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << get_alyona_a_number(0, 0, k, 0) << endl;
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