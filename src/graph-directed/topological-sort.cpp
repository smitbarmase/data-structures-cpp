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
    }

    void dfs_helper(T node, map<T, int> &visited, list<T> &ordered)
    {
        visited[node] = 1;
        for (auto child : l[node])
        {
            if (!visited[child])
            {
                dfs_helper(child, visited, ordered);
            }
        }
        ordered.push_front(node);
    }

    void topological_sort()
    {
        map<T, int> visited;
        list<T> ordered;

        for (pair<T, list<T>> p : l)
        {
            T node = p.first;
            if (!visited[node])
            {
                dfs_helper(node, visited, ordered);
            }
        }

        // output
        for (auto node : ordered)
        {
            cout << node << " ";
        }
    }
};

void solve()
{
    Graph<string> g;
    g.add_edge("A", "C");
    g.add_edge("B", "C");
    g.add_edge("C", "D");
    g.add_edge("B", "E");
    g.add_edge("E", "D");
    g.topological_sort();
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