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

bool cmp_x(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

bool cmp_y(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void solve()
{
    int w, h, n;
    cin >> w >> h >> n;

    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    pair<int, int> arr[n];

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x;
        cin >> y;
        arr[i] = {x, y};
    }

    sort(arr, arr + n, cmp_x);
    // first tower
    int max_x = 0;
    max_x = max(max_x, arr[0].first - 1);
    // remaining tower
    for (int i = 1; i < n; i++)
    {
        int diff = arr[i].first - arr[i - 1].first - 1;
        max_x = max(max_x, diff);
    }
    // last tower
    max_x = max(max_x, w - arr[n - 1].first);

    sort(arr, arr + n, cmp_y);
    // first tower
    int max_y = 0;
    max_y = max(max_y, arr[0].second - 1);
    // remaining tower
    for (int i = 1; i < n; i++)
    {
        int diff = arr[i].second - arr[i - 1].second - 1;
        max_y = max(max_y, diff);
    }
    // last tower
    max_y = max(max_y, h - arr[n - 1].second);

    cout << max_x * max_y << endl;
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