
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

int all_occurence(int *arr, int i, int n, int k, int *idx, int j)
{
    if (n == i)
    {
        return j;
    }

    if (arr[i] == k)
    {
        idx[j] = i;
        return all_occurence(arr, i + 1, n, k, idx, j + 1);
    }
    return all_occurence(arr, i + 1, n, k, idx, j);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int idx[n];

    int j = all_occurence(arr, 0, n, k, idx, 0);

    for (int i = 0; i < j; i++)
    {
        cout << idx[i] << " ";
    }
    cout << endl;
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