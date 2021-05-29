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

int dp[100001];

class Graph
{
    int n;
    list<int> *l;

public:
    Graph(int n)
    {
        l = new list<int>[n + 1];
        this->n = n;
    }

    void add_edge(int a, int b)
    {
        l[a].push_back(b);
    }

    int get_max_path_node(int i)
    {
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int len = 0;
        for (auto node : l[i])
        {
            len = max(len, 1 + get_max_path_node(node));
        }
        return dp[i] = len;
    }

    int get_max_path()
    {
        int path = 0;
        for (int i = 1; i <= n; i++)
        {
            path = max(path, get_max_path_node(i));
        }
        return path;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }

    memset(dp, -1, sizeof dp);

    cout << g.get_max_path() << endl;
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