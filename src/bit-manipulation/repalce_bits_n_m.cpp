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

int clear_range_i_to_j(int n, int i, int j)
{
    return n & ((~0 << (j + 1)) | ((1 << i) - 1));
}

void solve()
{
    int n, m, i, j;
    cin >> n >> m;
    cin >> i >> j;

    int result = clear_range_i_to_j(n, i, j) | (m << i);
    cout << result << endl;

    // input: n = 15, m = 2, i = 1, j = 3
    // output: 5
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