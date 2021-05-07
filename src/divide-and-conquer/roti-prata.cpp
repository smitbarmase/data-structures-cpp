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

// https://www.spoj.com/problems/PRATA/

bool possible_to_make_in_time(int *arr, int n, int needed_roti, int time_bound)
{
    int roti_count = 0;
    for (int i = 0; i < n; i++)
    {
        int time = 0;
        int mult = 1;
        int current_roti_count = 0;
        while (time + (arr[i] * mult) <= time_bound)
        {
            time += arr[i] * mult;
            mult++;
            current_roti_count++;
        }
        roti_count += current_roti_count;
    }
    if (roti_count >= needed_roti)
    {
        return true;
    }
    return false;
}

int find_minimum_time(int *arr, int n, int num_roti)
{
    int l = 0;
    int r = 10000000;

    int ans = LONG_LONG_MAX;
    while (l <= r)
    {
        int mid = l + ((r - l) / 2);
        bool can_make = possible_to_make_in_time(arr, n, num_roti, mid);
        if (can_make)
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    int r, n;
    cin >> r >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << find_minimum_time(arr, n, r) << endl;
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