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

void merge(int *arr, int l, int r)
{
    int m = l + ((r - l) / 2);

    int i = l;
    int j = m + 1;
    int k = l;

    int temp[100];

    // Sorting using two pointer
    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Putting remaining elements in array
    while (i <= m)
    {
        temp[k++] = arr[i++];
    }
    while (j <= r)
    {
        temp[k++] = arr[j++];
    }

    // Copying sorted array in original one
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }
}

void merge_sort(int *arr, int l, int r)
{
    // Base case
    if (l >= r)
    {
        return;
    }

    // Divide
    int m = l + ((r - l) / 2);
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    // Merging
    merge(arr, l, r);
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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