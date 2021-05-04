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

// Problem:
// Given a wall of sie 4 x N
// Tile of size (1, 4) and (4, 1)
// How many ways you can build the wall?

int ways_to_tile(int n)
{
    // Base case
    if (n <= 0)
    {
        return 0;
    }

    if (n <= 3)
    {
        return 1;
    }

    // Recursive case
    return ways_to_tile(n - 1) + ways_to_tile(n - 4);
}

void solve()
{
    int n;
    cin >> n;
    cout << ways_to_tile(4) << endl;
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