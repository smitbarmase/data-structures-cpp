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

int dist(const pair<int, int> &p)
{
    return p.first * p.first + p.second * p.second;
}

void solve()
{
    priority_queue<int> p;
    int n, k;
    cin >> n >> k;
    while (n--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            if (p.size() < k)
            {
                p.push(dist({x, y}));
            }
            else
            {
                if (dist({x, y}) < p.top())
                {
                    p.push(dist({x, y}));
                    p.pop();
                }
            }
        }
        else
        {
            cout << p.top() << endl;
        }
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

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}