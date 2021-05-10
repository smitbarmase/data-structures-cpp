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

// https://www.spoj.com/problems/BALIFE/

void solve()
{
    while (1)
    {
        int n;
        cin >> n;

        if (n == -1)
        {
            break;
        }

        int arr[n];
        int load = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            load += arr[i];
        }

        if (load % n != 0)
        {
            cout << -1 << endl;
            continue;
        }

        // load on each
        load /= n;

        int diff = 0, max_load = 0;
        for (int i = 0; i < n; i++)
        {
            diff += arr[i] - load;
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }
        cout << max_load << endl;
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