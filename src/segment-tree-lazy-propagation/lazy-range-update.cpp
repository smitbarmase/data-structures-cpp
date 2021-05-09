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

int lazy[10000] = {0};

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

void lazy_range_update(int *tree, int ss, int se, int l, int r, int index, int increment)
{
    // Resolve the value if exist
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index];
        // Not a leaf node
        if (ss != se)
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        // Clearing current lazy value
        lazy[index] = 0;
    }

    // No overlap
    if (r < ss || l > se)
    {
        return;
    }

    // Complete overlap
    if (ss >= l && se <= r)
    {
        tree[index] += increment;
        // Create lazy value for children node
        if (ss != se)
        {
            lazy[2 * index] += increment;
            lazy[2 * index + 1] += increment;
        }
        return;
    }

    // Partial overlap
    int mid = ss + ((se - ss) / 2);
    lazy_range_update(tree, ss, mid, l, r, 2 * index, increment);
    lazy_range_update(tree, mid + 1, se, l, r, 2 * index + 1, increment);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

void solve()
{
    int arr[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(arr) / sizeof(int);

    int *tree = new int[4 * n + 1];
    build_tree(arr, 0, n - 1, 1, tree);

    // tree, ss, se, l, r, index, increment
    lazy_range_update(tree, 0, n - 1, 3, 5, 1, +10);
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