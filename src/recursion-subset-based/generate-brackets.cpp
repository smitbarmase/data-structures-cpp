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

// Input:
// 4

// Output:
// (((())))
// ((()()))
// ((())())
// ((()))()
// (()(()))
// (()()())
// (()())()
// (())(())
// (())()()
// ()((()))
// ()(()())
// ()(())()
// ()()(())
// ()()()()

void generate_brackets(string str, int open, int close, int n)
{
    // Base case
    if (open == n && close == n)
    {
        cout << str << endl;
        return;
    }

    // Recursive case
    if (open < n)
    {
        generate_brackets(str + '(', open + 1, close, n);
    }
    if (open > close)
    {
        generate_brackets(str + ')', open, close + 1, n);
    }
}

void solve()
{
    int n;
    cin >> n;
    generate_brackets("", 0, 0, n);
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