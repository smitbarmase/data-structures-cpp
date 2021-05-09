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

// https://www.spoj.com/problems/BAISED/

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        cin >> arr[i];
    }

    // Can be solved using counting sort, but we don't know how high rank is.
    // It is not provided in question.
    // Let's use inbuilt sort

    sort(arr, arr + n);

    int diff = 0;
    for (int i = 1; i <= n; i++)
    {
        diff += abs(arr[i - 1] - i);
    }
    cout << diff << endl;
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