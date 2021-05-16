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

// https://leetcode.com/problems/flood-fill/

// Input
// [[1,1,1],[1,1,0],[1,0,1]]
// sr = 1, sc = 1, newColor = 2

// Output
// [[2,2,2],[2,2,0],[2,0,1]]

class FloodFill
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int w, h, parentColor;

    void fill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Base case
        if (sr < 0 || sc < 0 || sr > h - 1 || sc > w - 1)
        {
            return;
        }

        if (image[sr][sc] != parentColor)
        {
            return;
        }

        // Setting to new color
        image[sr][sc] = newColor;

        // Recursion
        for (int i = 0; i < 4; i++)
        {
            fill(image, sr + dy[i], sc + dx[i], newColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor)
        {
            return image;
        }
        h = image.size();
        w = image[0].size();
        parentColor = image[sr][sc];
        fill(image, sr, sc, newColor);
        return image;
    }
};

void solve()
{
    int w, h, sr, sc, c;
    cin >> w >> h >> sr >> sc >> c;

    vector<vector<int>> image;

    for (int i = 0; i < h; i++)
    {
        image.push_back({});
        for (int j = 0; j < w; j++)
        {
            int cell;
            cin >> cell;
            image[i].push_back(cell);
        }
    }

    FloodFill f;
    f.floodFill(image, sr, sc, c);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
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