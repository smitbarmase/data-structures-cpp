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

// Find gcd of a and b
// a < 10^12
// b < 10^250

// First number is integer, second is string

// Input:
// 1
// 1221
// 1234567891011121314151617181920212223242526272829

// Output:
// 3

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int big_gcd(int a, string b)
{
    int res = 0;

    //b will be 0 <= b < a
    for (int i = 0; i < b.size(); i++)
    {
        res *= 10;
        res += b[i] - '0';
        res %= a;
    }

    return gcd(a, res);
}

void solve()
{
    int a;
    string b;
    cin >> a >> b;

    cout << big_gcd(a, b) << endl;
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