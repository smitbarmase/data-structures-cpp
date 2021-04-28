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

// Power optimization.
// Instead of doing a * a * a for n times.
// We do it in O(log(n)) and not in O(n).

//  We convert n into binary. And multiply and shift a as per that.

int power_optimization(int a, int n)
{
    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans *= a;
        }
        n = n >> 1;
        a *= a;
    }
    return ans;
}

void solve()
{
    int a, n;
    cin >> a >> n;
    cout << power_optimization(a, n) << endl;
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