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

int get_gcd(int a, int b)
{
    return b == 0 ? a : get_gcd(b, a % b);
}

pair<int, int> extended_euclidean(int a, int b)
{
    if (b == 0)
    {
        return {1, 0};
    }

    pair<int, int> res = extended_euclidean(b, a % b);
    int x = res.second;
    int y = res.first - (a / b) * res.second;

    return {x, y};
}

int inverse_modulo(int a, int m)
{
    pair<int, int> res = extended_euclidean(a, m);
    return (res.first + m) % m;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    if (get_gcd(a, b) == 1)
    {
        // Inverse modulo exists
        cout << inverse_modulo(a, b) << endl;
        return;
    }

    cout << "Not exist" << endl;
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