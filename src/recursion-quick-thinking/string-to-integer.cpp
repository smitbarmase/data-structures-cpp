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

int string_to_integer(string str)
{
    // Base case
    if (str == "")
    {
        return 0;
    }
    // Recursive case
    int n = str.length();
    int last = str[n - 1] - '0';
    int remaining = string_to_integer(str.substr(0, n - 1));
    return (remaining * 10) + last;
}

void solve()
{
    string str;
    cin >> str;
    cout << string_to_integer(str) << endl;
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