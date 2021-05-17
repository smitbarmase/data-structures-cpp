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

class Graph
{
    int n;
    map<int, list<int>> l;

public:
    Graph(int n)
    {
        this->n = n;
    }

    void add_edge(int a, int b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }

    int shortest_cycle(int src)
    {
        vector<int> visited(n, INT_MAX);
        queue<int> q;

        q.push(src);
        visited[src] = 0;

        int min_cycle = INT_MAX;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            for (auto child : l[current])
            {
                if (visited[child] == INT_MAX)
                {
                    q.push(child);
                    visited[child] = visited[current] + 1;
                }
                else if (visited[child] >= visited[current])
                {
                    min_cycle = min(min_cycle, visited[current] + visited[child] + 1);
                }
            }
        }

        if (min_cycle == INT_MAX)
        {
            return 0;
        }
        return min_cycle;
    }
};

void solve()
{
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0); // make cycle of length 4
    g.add_edge(3, 4);
    g.add_edge(4, 0); // make cycle of length 3
    cout << g.shortest_cycle(0) << endl;
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