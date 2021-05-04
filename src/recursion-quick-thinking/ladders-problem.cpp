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

// Number of ways to reach, n steps by jumping max k steps at a time

int ways_to_jump(int n, int k)
{
    // Base case
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }

    // Recursive case
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += ways_to_jump(n - i, k);
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << ways_to_jump(n, k) << endl;
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