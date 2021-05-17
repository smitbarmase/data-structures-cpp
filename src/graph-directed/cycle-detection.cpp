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

    bool cycle_helper(T node, map<T, int> &visited, map<T, int> &path)
    {
        visited[node] = 1;
        path[node] = 1;
        for (auto child : l[node])
        {
            if (path[child])
            {
                return true;
            }
            else if (!visited[child])
            {
                bool cycle = cycle_helper(child, visited, path);
                if (cycle)
                {
                    return true;
                }
            }
        }
        path[node] = 0;
        return false;
    }

    bool have_cycle(T src)
    {
        map<T, int> visited, path;
        return cycle_helper(src, visited, path);
    }
};

void solve()
{
    Graph<int> g;
    g.add_edge(1, 2);
    g.add_edge(2, 5);
    g.add_edge(5, 4);
    g.add_edge(4, 6);
    g.add_edge(6, 7);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(6, 3); // edge adds cycle
    cout << g.have_cycle(1) << endl;
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