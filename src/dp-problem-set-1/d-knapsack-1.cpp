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

class Item
{
public:
    int v;
    int w;
};

void solve()
{
    int n, w;
    cin >> n >> w;

    Item items[n];

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].w >> items[i].v;
    }

    int dp[w + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = w; j >= 0; j--)
        {
            if (j >= items[i].w)
            {
                dp[j] = max(dp[j], items[i].v + dp[j - items[i].w]);
            }
            else
            {
                break;
            }
        }
    }

    cout << dp[w] << endl;
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