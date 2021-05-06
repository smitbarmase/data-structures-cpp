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
int ans = 0, DONE;

// The most optimized way to solve n queen problem!
void n_queen(int rowMask, int ld, int rd)
{
    if (rowMask == DONE)
    {
        ans++;
        return;
    }
    int safe = DONE & (~(rowMask | ld | rd));
    while (safe)
    {
        int p = safe & (-safe);
        safe = safe - p;
        n_queen(rowMask | p, (ld | p) << 1, (rd | p) >> 1);
    }
}

void solve()
{
    cin >> n;
    DONE = ((1 << n) - 1);
    n_queen(0, 0, 0);
    cout << ans << endl;
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