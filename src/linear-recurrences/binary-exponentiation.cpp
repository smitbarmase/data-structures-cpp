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

// O(logN)
int pow(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }

    int sub_pow = pow(a, n / 2);

    if (n & 1)
    {
        // odd
        return a * sub_pow * sub_pow;
    }
    // even
    return sub_pow * sub_pow;
}

void solve()
{
    int a, n;
    cin >> a >> n;
    cout << pow(a, n) << endl;
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