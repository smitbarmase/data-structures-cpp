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

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void add_edge(T a, T b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }

    void bfs(T src)
    {
        map<T, int> dist;
        queue<T> q;

        for (auto n : l)
        {
            dist[n.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            T data = q.front();
            q.pop();
            for (auto n : l[data])
            {
                if (dist[n] == INT_MAX)
                {
                    q.push(n);
                    dist[n] = dist[data] + 1;
                }
            }
        }

        for (auto n : l)
        {
            cout << "Distance of " << n.first << " is " << dist[n.first] << endl;
        }
    }
};

void solve()
{
    Graph<int> g;
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.bfs(0);
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