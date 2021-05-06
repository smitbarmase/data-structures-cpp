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

// https://codeforces.com/problemset/problem/812/B

// Input:
// 3
// 2 2
// 0010
// 0100
// 3 4
// 001000
// 000010
// 000010
// 4 3
// 01110
// 01110
// 01110
// 01110

// Output:
// 5
// 12
// 18

int ans;
int n, m;
int ld[20], rd[20];
string matrix[20];

void find_path(bool right, int i, int val)
{
    // Base case
    if (i == n - 1)
    {
        if (right)
        {
            ans = min(ans, val + rd[i]);
        }
        else
        {
            ans = min(ans, val + ld[i]);
        }
        return;
    }
    // Recursive case
    if (right)
    {
        find_path(0, i + 1, val + m + 2);
        find_path(1, i + 1, val + 2 * rd[i] + 1);
    }
    else
    {
        find_path(0, i + 1, val + 2 * ld[i] + 1);
        find_path(1, i + 1, val + m + 2);
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> matrix[i];
    }

    int tmp = -1;
    // Generating prefix distance  each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < matrix[i].length(); j++)
        {
            // last digit from left
            if (matrix[i][j] == '1')
            {
                ld[i] = max(j, ld[i]);
            }
            // first digit from right
            if (matrix[i][m + 1 - j] == '1')
            {
                rd[i] = max(rd[i], j);
            }
        }
        if (ld[i])
        {
            tmp = i;
        }
    }
    n = tmp + 1;
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (n == 1)
    {
        cout << ld[0] << endl;
        return;
    }

    // Ground floor
    ans = LONG_LONG_MAX;
    find_path(0, 1, 2 * ld[0] + 1);
    find_path(1, 1, m + 2);
    cout << ans << endl;
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