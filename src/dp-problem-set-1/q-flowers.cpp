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

struct flower
{
    int h;
    int b;
};

int solve_flowers(vector<flower> &v, int n)
{
    vector<int> dp(n + 1);
    map<int, int> valid;
    // store beauty of first element
    dp[1] = v[1].b;
    valid[v[1].h] = dp[1];
    int ans = dp[1];
    // interate to further element
    for (int i = 2; i <= n; i++)
    {
        dp[i] = v[i].b;
        // for every element, check if adding beauty make sense
        // also, you should add with beaty until height is less than current one
        auto it = valid.lower_bound(v[i].h + 1);
        if (it != valid.begin())
        {
            it--;
            dp[i] += it->second;
        }
        valid[v[i].h] = dp[i];
        it = valid.upper_bound(v[i].h);
        while (it != valid.end() && it->second <= dp[i])
        {
            auto temp = it;
            temp++;
            valid.erase(it);
            it = temp;
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<flower> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i].h;
    for (int i = 1; i <= n; i++)
        cin >> v[i].b;
    cout << solve_flowers(v, n) << endl;
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