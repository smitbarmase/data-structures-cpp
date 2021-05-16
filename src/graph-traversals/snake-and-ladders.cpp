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

    int get_distance(T src, T dest)
    {
        map<T, int> dist;
        map<T, T> parent;
        queue<T> q;

        for (auto n : l)
        {
            dist[n.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

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
                    parent[n] = data;
                }
            }
        }

        T temp = dest;
        while (temp != src)
        {
            cout << temp << " <- ";
            temp = parent[temp];
        }
        cout << src << endl;

        return dist[dest];
    }
};

void solve()
{
    int board[50] = {0};

    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;
    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];
            if (j <= 36)
            {
                g.add_edge(i, j);
            }
        }
    }

    g.add_edge(36, 36);

    cout << g.get_distance(0, 36) << endl;
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