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

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
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

// https://codeforces.com/problemset/problem/1244/C

// Input:
// 30 60 3 1

// Output:
// 17 9 4

void solve()
{
    int n, p, w, d;
    cin >> n >> p >> w >> d;

    int g = gcd(w, d);

    if (p % g != 0)
    {
        cout << -1 << endl;
        return;
    }

    pair<int, int> ans = extended_euclidean(w, d);

    int t = (-d * ans.second);

    // NOT A CORRECT WAY

    if (t <= w * ans.first)
    {
        ans.first -= t / w;
        ans.second += t / d;

        ans.first *= p / g;
        ans.second *= p / g;

        int z = n - ans.first - ans.second;

        cout << ans.first << " " << ans.second << " " << z << endl;
        return;
    }

    cout << -1 << endl;
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