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

void build_tree(int *arr, int l, int r, int index, int *tree)
{
    if (l == r)
    {
        tree[index] = arr[l];
        return;
    }

    int m = l + ((r - l) / 2);
    build_tree(arr, l, m, 2 * index, tree);
    build_tree(arr, m + 1, r, 2 * index + 1, tree);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

void solve()
{
    int arr[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(arr) / sizeof(int);

    int *tree = new int[4 * n + 1];
    build_tree(arr, 0, n - 1, 1, tree);

    for (int i = 1; i <= 13; i++)
    {
        cout << tree[i] << " ";
    }
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