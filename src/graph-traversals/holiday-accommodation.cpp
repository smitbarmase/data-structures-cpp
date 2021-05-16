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

// Input
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

// Output
// Case #1: 18
// Case #2: 62

class Graph
{
    int n;
    list<pair<int, int>> *l;

    int num_of_nodes(int node, bool *visited, int &ans)
    {
        visited[node] = 1;
        int count = 1;

        for (pair<int, int> p : l[node])
        {
            if (!visited[p.first])
            {
                int num = num_of_nodes(p.first, visited, ans);
                ans += min(num, n - num) * 2 * p.second;
                count += num;
            }
        }
        return count;
    }

public:
    Graph(int n)
    {
        l = new list<pair<int, int>>[n + 1];
        this->n = n;
    }

    void add_edge(int a, int b, int c)
    {
        l[a].push_back({b, c});
        l[b].push_back({a, c});
    }

    int get_max_travelled(int src)
    {
        bool *visited = new bool[n + 1]{0};
        int ans = 0;
        num_of_nodes(src, visited, ans);
        return ans;
    }
};

void solve(int case_num)
{
    int n;
    cin >> n;

    Graph g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    cout << "Case #" << case_num << ": " << g.get_max_travelled(1) << endl;
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
    int case_num = 1;
    while (t--)
    {
        solve(case_num);
        case_num++;
    }
    return 0;
}