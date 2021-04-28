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

// Unique Number 3.
// Given list of numbers, every number occurs three times except one. Find that number.
// Linear time. Constant space.

// Input
// 1
// 10
// 2 3 3 4 6 2 4 4 3 2

// Output
// 6

void solve()
{
    int n;
    cin >> n;

    int res[64] = {0};

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        int j = 0;
        while (num > 0)
        {
            res[j] += num & 1;
            num = num >> 1;
            j++;
        }
    }

    // counting 1s in col, and storing in certain position

    int ans = 0, p = 1;
    for (int i = 0; i < 64; i++)
    {
        res[i] %= 3; // modulo by 3 will, only keep 1 for that unique number

        // converting binary to decimal
        ans += res[i] * p;
        p = p << 1;
    }

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