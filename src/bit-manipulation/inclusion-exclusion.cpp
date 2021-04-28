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

// Inclusion exclusion
// Given array of n numbers, find how many numbers less than k, are divisible by any of them.
// Given n and k, and array of numbers on next line.

// Input
// 3 1000
// 2 3 5

// Output
// 734

// Calculation
// (1000/2) + (1000/3) + (1000/5) - (1000/2*3) - (1000/5*3) - (1000/5*2) + (1000/3*5*2) = 734

void subset(int i, int arr[], int n, int k, int &result)
{
    int j = 0, count = 0;
    while (i > 0)
    {
        if (i & 1)
        {
            // do something with arr[j]
            count++;
            k /= arr[j];
        }
        j++;
        i = i >> 1;
    }

    if (count > 0)
    {
        if (count & 1)
        {
            // odd
            result += k;
        }
        else
        {
            // even
            result -= k;
        }
    }
}

void solve()
{
    int n, k, result = 0;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // possible subsets of numbers
    for (int i = 0; i < (1 << n); i++)
    {
        subset(i, arr, n, k, result);
    }

    cout << result << endl;
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