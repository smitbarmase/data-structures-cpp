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

int binary_search(int *arr, int l, int r, int s)
{
    // base case
    if (l == r)
    {
        return s == arr[l] ? l : -1;
    }
    // recursive case
    int m = (l + r) / 2;
    if (s == arr[m])
    {
        return m;
    }
    else if (s < arr[m])
    {
        return binary_search(arr, 0, m, s);
    }
    return binary_search(arr, m + 1, r, s);
}

void solve()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << binary_search(arr, 0, n - 1, s) << endl;
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