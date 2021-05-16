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

// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

// Input
// 2
// 5 3
// 0 1
// 2 3
// 0 4
// 4 1
// 0 2

// Output
// 6
// 5

class Graph
{
    map<int, list<int>> l;

    int dfs(int src, map<int, int> &visited)
    {
        stack<int> s;
        int count = 0;

        s.push(src);
        visited[src] = 1;

        while (!s.empty())
        {
            int data = s.top();
            count += 1;
            s.pop();
            for (auto n : l[data])
            {
                if (!visited[n])
                {
                    s.push(n);
                    visited[n] = 1;
                }
            }
        }
        return count;
    }

public:
    void add_edge(int a, int b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }

    int possible_diffrent_pairs(int n)
    {
        map<int, int> visited;
        int ans = n * (n - 1) / 2;
        for (auto p : l)
        {
            int node = p.first;
            if (!visited[node])
            {
                int num = dfs(node, visited);
                ans -= num * (num - 1) / 2;
            }
        }
        return ans;
    }
};

void solve()
{
    int n, np;
    vector<pair<int, int>> astronaut;
    cin >> n >> np;
    for (int i = 0; i < np; i++)
    {
        int a, b;
        cin >> a >> b;
        astronaut.push_back({a, b});
    }

    Graph g;
    for (int i = 0; i < n; i++)
    {
        g.add_edge(i, i);
    }
    for (auto p : astronaut)
    {
        g.add_edge(p.first, p.second);
    }
    cout << g.possible_diffrent_pairs(n) << endl;
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