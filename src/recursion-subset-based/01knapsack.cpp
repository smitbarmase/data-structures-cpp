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

// 0 1 Knapsack

// Note:
// Fractional knapsack can be optimally solved by profit/weight, or with brute force recursion.
// But, 0 1 Knapsack need brute force recursion and dynamic programming to optimize it.

// Input:
// 2
// 4 6
// 1 2 3 5
// 40 20 35 100
// 3 3
// 1 3 2
// 2 36 30

// Output:
// 140
// 36

int knapsack(int *weights, int *prices, int n, int wc)
{
    // base case
    if (n == 0 || wc == 0)
    {
        return 0;
    }

    // recursive case
    int current_price = prices[n - 1];
    int current_weight = weights[n - 1];

    // Excuding current item
    int include = 0;
    int exclude = knapsack(weights, prices, n - 1, wc);
    if (current_weight <= wc)
    {
        // Incude current item, if we have capacity
        include = current_price + knapsack(weights, prices, n - 1, wc - current_weight);
    }
    // Use item which returns max profit, from both cases
    return max(include, exclude);
}

void solve()
{
    int n, wc;
    cin >> n >> wc;
    int weights[n];
    int prices[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    cout << knapsack(weights, prices, n, wc) << endl;
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