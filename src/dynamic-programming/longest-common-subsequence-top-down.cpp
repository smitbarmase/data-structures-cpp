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

string longest_common_subseqence(int i, int j, string &a, string &b, string dp[][100])
{
    // base case
    if (i == a.length() || j == b.length())
    {
        return "";
    }
    // memoization
    if (dp[i][j] != "")
    {
        return dp[i][j];
    }
    // recursive case
    if (a[i] == b[j])
    {
        return dp[i][j] = a[i] + longest_common_subseqence(i + 1, j + 1, a, b, dp);
    }
    string first = longest_common_subseqence(i + 1, j, a, b, dp);
    string second = longest_common_subseqence(i, j + 1, a, b, dp);
    dp[i][j] = first.length() > second.length() ? first : second;
    return dp[i][j];
}

void solve()
{
    string a, b;
    cin >> a >> b;
    string dp[100][100] = {""};
    cout << longest_common_subseqence(0, 0, a, b, dp) << endl;
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