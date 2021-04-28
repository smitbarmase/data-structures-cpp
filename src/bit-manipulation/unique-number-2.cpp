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

// Unique Number 2.
// Given list of numbers, every number occurs twice except two. Find those two numbers.
// Linear time. Constant space.

// Input
// 1
// 8
// 2 3 4 3 5 2 4 7

// Output
// 5 7

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans ^= arr[i];
    }

    // ans = a ^ b

    int temp = ans, count = 0;
    while (!(temp & 1))
    {
        temp = temp >> 1;
        count++;
    }

    // count = number of shift for lsb 1

    int b = 0;
    for (int i = 0; i < n; i++)
    {
        int temp2 = arr[i];
        temp2 = temp2 >> count;
        // checking every number with same shift, for 1
        if (temp2 & 1)
        {
            b ^= arr[i];
        }
    }

    // b = second number found!

    int a = ans ^ b;

    // a = a ^ b ^ b;
    // first number found!

    cout << a << " " << b << endl;
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