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

// Binary search without recursion
// For recursion refer: recursion-basics

int first_occurrence(int *arr, int &n, int &x)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int m = s + ((e - s) / 2);
        if (arr[m] == x)
        {
            ans = m;
            e = m - 1;
        }
        else if (arr[m] < x)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}

int last_occurrence(int *arr, int &n, int &x)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int m = s + ((e - s) / 2);
        if (arr[m] == x)
        {
            ans = m;
            s = m + 1;
        }
        else if (arr[m] < x)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << first_occurrence(arr, n, x) << endl;
    cout << last_occurrence(arr, n, x) << endl;
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