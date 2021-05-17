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

    void topological_sort()
    {
        map<T, int> freq;

        // Create freq table for indegree
        for (pair<T, list<T>> p : l)
        {
            for (T node : p.second)
            {
                freq[node] += 1;
            }
        }

        queue<T> q;

        // push nodes with zero
        for (auto p : l)
        {
            if (!freq[p.first])
            {
                q.push(p.first);
            }
        }

        while (!q.empty())
        {
            T data = q.front();
            cout << data << " ";
            q.pop();
            for (auto child : l[data])
            {
                freq[child] -= 1;
                if (freq[child] == 0)
                {
                    q.push(child);
                }
            }
        }
    }
};

void solve()
{
    Graph<string> g;
    g.add_edge("A", "C");
    g.add_edge("B", "D");
    g.add_edge("C", "E");
    g.add_edge("D", "E");
    g.add_edge("C", "I");
    g.add_edge("E", "I");
    g.add_edge("F", "B");
    g.add_edge("F", "G");
    g.add_edge("E", "G");
    g.add_edge("H", "G");
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