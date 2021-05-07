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

float square_root(int n)
{
    int l = 0;
    int r = n;
    float ans = -1;
    while (l <= r)
    {
        int m = l + ((r - l) / 2);
        int square = m * m;
        if (square == n)
        {
            return m;
        }
        else if (square > n)
        {
            r = m - 1;
        }
        else
        {
            ans = m;
            l = m + 1;
        }
    }

    // Floating part
    float p = 0.1;
    int accurate_upto = 5; // Above 5 things will mess up
    while (accurate_upto)
    {
        while (ans * ans <= n)
        {
            ans += p;
        }
        ans -= p;
        p /= 10;
        accurate_upto--;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    cout << square_root(n) << endl;
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