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

// Binary search on rotated array

// Input:
// 9 8
// 7 8 9 1 2 3 4 5 6

// Output:
// 1

int search(int *arr, int n, int x)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + ((r - l) / 2);
        if (arr[m] == x)
        {
            // Element found!
            return m;
        }
        else if (arr[m] >= arr[l]) // [l, m] is sorted
        {
            if (arr[l] <= x && x < arr[m])
            {
                // Exist in left sorted part
                r = m - 1;
            }
            else
            {
                // Exist in right unsorted part
                l = m + 1;
            }
        }
        else
        {
            // [m, r] is sorted
            if (arr[m] < x && x <= arr[r])
            {
                // Exist in right sorted part
                l = m + 1;
            }
            else
            {
                // Exist in left unsorted part
                r = m - 1;
            }
        }
    }
    return -1;
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
    cout << search(arr, n, x) << endl;
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