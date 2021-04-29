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

// Divisible subarrays
// Given array of N numbers, return how many subarrays can be formed
// if sum of all the elements in it, is divisible by N.

// Input
// 2 <- t
// 5
// 1 1 1 1 1
// 5
// 1 3 2 6 4

// Output
// 1
// 3

int arr[100005], freq[100005];

void solve()
{
    int n;
    cin >> n;
    memset(freq, 0, sizeof(freq));

    freq[0] = 1; // Initial count for zero.

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        sum %= n;
        sum = (sum + n) % n; // To prevent negative.
        freq[sum]++;         // Map count for every bucket.
    }

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += freq[i] * (freq[i] - 1) / 2;
    }
    cout << total << endl;
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