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

string a, b;
int n, m;

int dp[3001][3001];

string get_lcs(int len)
{
    string lcs;
    int i = 0, j = 0;
    while (len)
    {
        if (a[i] == b[j])
        {
            lcs += a[i];
            i++;
            j++;
            len--;
        }
        else
        {
            if (dp[i + 1][j] > dp[i][j + 1])
                i++;
            else
                j++;
        }
    }
    return lcs;
}

int lcs_length(int i, int j, int k)
{
    if (i == n or j == m)
    {
        return k;
    }
    if (dp[i][j] != -1)
    {
        return k + dp[i][j];
    }
    int res = max(lcs_length(i + 1, j, k), lcs_length(i, j + 1, k));
    if (a[i] == b[j])
    {
        res = max(res, lcs_length(i + 1, j + 1, k + 1));
    }
    return dp[i][j] = res;
}

void solve()
{
    cin >> a >> b;
    n = a.size();
    m = b.size();

    memset(dp, -1, sizeof dp);

    int len = lcs_length(0, 0, 0);
    cout << get_lcs(len) << endl;
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

    solve();
    return 0;
}