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

// https://www.spoj.com/problems/MIXTURES/

int sum_smoke(int i, int j, int *arr)
{
    int sum = 0;
    for (int k = i; k <= j; k++)
    {
        sum += arr[k];
        sum %= 100;
    }
    return sum;
}

void solve()
{
    int n;
    while (cin >> n)
    {
        int arr[n];
        int dp[102][102] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1; i < n; i++)
        {
            int r = 0, c = i;
            while (c < n)
            {
                dp[r][c] = INT_MAX;
                for (int k = r; k < c; k++)
                {
                    // making two partion from r to k and k + 1 to c
                    int first = dp[r][k];
                    int second = dp[k + 1][c];
                    int self = sum_smoke(r, k, arr) * sum_smoke(k + 1, c, arr);
                    dp[r][c] = min(dp[r][c], first + second + self);
                }
                r++, c++;
            }
        }

        cout << dp[0][n - 1] << endl;
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

    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}