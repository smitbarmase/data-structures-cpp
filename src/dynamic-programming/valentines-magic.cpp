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

int n, m, a[5005], b[5005], dp[5005][5005];

int make_pairing(int i, int j)
{
    if (i == n)
    {
        return 0;
    }
    if (j == m)
    {
        return INT_MAX;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // we pair boy with a girl
    int x = abs(a[i] - b[j]) + make_pairing(i + 1, j + 1);

    // we skip pairing, and move to the next girl
    int y = make_pairing(i, j + 1);

    // boy must be paired
    return dp[i][j] = min(x, y);
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << make_pairing(0, 0) << endl;
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