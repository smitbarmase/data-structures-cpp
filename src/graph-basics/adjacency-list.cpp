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
    unordered_map<string, list<pair<string, int>>> l;

public:
    void add_edge(string a, string b, bool bidir, int cost)
    {
        l[a].push_back({b, cost});
        if (bidir)
        {
            l[b].push_back({a, cost});
        }
    }

    void print()
    {
        for (auto p : l)
        {
            cout << p.first << " -> ";
            for (pair<string, int> node : p.second)
            {
                cout << "(" << node.first << ", " << node.second << ") ";
            }
            cout << endl;
        }
    }
};

void solve()
{
    Graph g;
    g.add_edge("A", "B", true, 2);
    g.add_edge("B", "C", true, 4);
    g.add_edge("A", "C", true, 6);
    g.add_edge("C", "D", false, 2);
    g.print();
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