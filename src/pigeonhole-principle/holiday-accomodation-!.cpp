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

// https://www.spoj.com/problems/HOLI/

// Input:
// 2
// 4
// 1 2 3
// 2 3 2
// 4 3 2
// 6
// 1 2 3
// 2 3 4
// 2 4 1
// 4 5 8
// 5 6 5

// Output:
// Case #1: 18
// Case #2: 62

class Graph
{
    int V;
    list<pair<int, int>> *l;

    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w)
    {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    int dfs_helper(bool *visited, int *count, int &ans)
    {
    }

    int dfs()
    {
        bool *visited = new bool[V];
        int *count = new int[V];

        int ans = 0;

        l[1].

            dfs_helper(0, visited, count, ans) return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
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