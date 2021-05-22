#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int arr[102], dp[102];

    memset(arr, 0, sizeof arr);
    memset(dp, 0, sizeof dp);

    int n, k;
    cin >> n >> k;

    // incase k is greater than n
    k = min(n - 1, k);

    // get k - 1 elements
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    // process elements from 0 to k - 1
    dp[0] = 0;
    for (int i = 1; i < k; i++)
    {
        dp[i] = INT_MAX;
        for (int j = i - 1; j >= 0; j--)
        {
            dp[i] = min(dp[i], abs(arr[i] - arr[j]) + dp[j]);
        }
    }

    // process elements from k to n - 1
    for (int i = k; i < n; i++)
    {
        int cur;
        cin >> cur;
        int res = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            res = min(res, abs(cur - arr[j]) + dp[j]);
        }
        // shift dp and elements array
        for (int i = 0; i < k - 1; i++)
        {
            dp[i] = dp[i + 1];
            arr[i] = arr[i + 1];
        }
        dp[k - 1] = res;
        arr[k - 1] = cur;
    }

    cout << dp[k - 1] << endl;
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

    solve();

    return 0;
}