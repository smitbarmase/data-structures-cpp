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

void move(int n, char src, char helper, char dest)
{
    // Base case
    if (n == 0)
    {
        return;
    }
    // Recursive case
    move(n - 1, src, dest, helper);
    cout << "Shift " << n << " from " << src << " to " << dest << endl;
    move(n - 1, helper, src, dest);
}

void solve()
{
    int n;
    cin >> n;
    move(3, 'A', 'B', 'C');
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