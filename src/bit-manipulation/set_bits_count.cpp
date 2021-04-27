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

int set_bits_count(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += n & 1;
        n = n >> 1;
    }
    return ans;
}

int set_bits_count_quick(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    // input: n = 13, binary = 1101
    // output: 3

    // We have 3 methods to do this
    cout << set_bits_count(n) << endl;       // O(log(n))
    cout << set_bits_count_quick(n) << endl; // O(set bits)
    cout << __builtin_popcount(n) << endl;
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