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

int get_bit(int n, int i)
{
    return (n & (1 << i)) > 0 ? 1 : 0;
}

int set_bit(int n, int i)
{
    return n | (1 << i);
}

int clear_bit(int n, int i)
{
    return n & ~(1 << i);
}

int update_bit(int n, int i, int v)
{
    return (n & ~(1 << i)) | (v << i);
}

int clear_last_i_bits(int n, int i)
{
    return n & (~0 << i);
}

int clear_range_i_to_j(int n, int i, int j)
{
    return n & ((~0 << (j + 1)) | ((1 << i) - 1));
}

void solve()
{
    cout << update_bit(13, 1, 1) << endl;
    // 1 1 0 1 = 13 => input
    // 1 1 1 1 = 15 => output

    cout << clear_range_i_to_j(31, 1, 3) << endl;
    // 0 1 1 1 1 1 = 31 => input
    // 0 1 0 0 0 1 = 17 => output
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