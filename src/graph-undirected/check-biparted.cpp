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
    int n;
    map<T, list<T>> l;

public:
    Graph(int n)
    {
        this->n = n;
    }

    void add_edge(T a, T b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }

    bool biparted_helper(T node, T parent, int *visited)
    {
        if (parent == -1)
        {
            visited[node] = 1;
        }
        else
        {
            visited[node] = visited[parent] == 1 ? 2 : 1;
        }

        for (auto child : l[node])
        {
            if (!visited[child])
            {
                bool biparted = biparted_helper(child, node, visited);
                if (!biparted)
                {
                    return false;
                }
            }
            else if (visited[child] == visited[node])
            {
                return false;
            }
        }
        return true;
    }

    bool is_biparted()
    {
        int *visited = new int[n]{0};
        return biparted_helper(0, -1, visited);
    }
};

void solve()
{
    Graph<int> g(6);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    // g.add_edge(3, 0);
    g.add_edge(3, 4);
    g.add_edge(3, 5);
    cout << g.is_biparted() << endl;
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