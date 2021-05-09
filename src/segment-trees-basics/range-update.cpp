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

int query(int *tree, int ss, int se, int qs, int qe, int index)
{
    // Complete overlap
    if (ss >= qs and se <= qe)
    {
        return tree[index];
    }

    // No overlap
    if (qe < ss || se < qs)
    {
        return LONG_LONG_MAX;
    }

    // Partial overlap
    int m = ss + ((se - ss) / 2);
    int left = query(tree, ss, m, qs, qe, 2 * index);
    int right = query(tree, m + 1, se, qs, qe, 2 * index + 1);
    return min(left, right);
}

void range_update(int *tree, int ss, int se, int index, int increment, int l, int r)
{
    // If does not lie in range
    if (r < ss || l > se)
    {
        return;
    }

    // Leaf node
    if (ss == se)
    {
        tree[index] += increment;
        return;
    }

    int mid = ss + ((se - ss) / 2);
    range_update(tree, ss, mid, 2 * index, increment, l, r);
    range_update(tree, mid + 1, se, 2 * index + 1, increment, l, r);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

void solve()
{
    int arr[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(arr) / sizeof(int);

    int *tree = new int[4 * n + 1];
    build_tree(arr, 0, n - 1, 1, tree);

    range_update(tree, 0, n - 1, 1, +10, 3, 5);

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(tree, 0, n - 1, l, r, 1) << endl;
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