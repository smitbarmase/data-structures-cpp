#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int arr[3], dp[3];

    memset(arr, 0, sizeof arr);
    memset(dp, 0, sizeof dp);

    int n;
    cin >> n;

    if (n == 0 || n == 1)
    {
        cout << 0 << endl;
        return;
    }

    cin >> arr[0];
    cin >> arr[1];

    if (n == 2)
    {
        cout << abs(arr[0] - arr[1]) << endl;
        return;
    }

    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);

    for (int i = 2; i < n; i++)
    {
        cin >> arr[2];
        int a = abs(arr[2] - arr[1]) + dp[1];
        int b = abs(arr[2] - arr[0]) + dp[0];
        dp[2] = min(a, b);

        arr[0] = arr[1];
        arr[1] = arr[2];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }

    cout << dp[1] << endl;
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