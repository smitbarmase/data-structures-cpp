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

bitset<10000005> b;

void sieve()
{
    b.set(); // set all

    b[0] = b[1] = 0;

    for (int i = 2; i <= 10000000; i++)
    {
        if (b[i])
        {
            for (int j = i * i; j <= 10000000; j += i)
            {
                b[j] = 0;
            }
        }
    }
}

// Input
// 3
// 5915587277
// 1500450271
// 1500450270

// Output
// yes
// yes
// no

void solve()
{
    int n;
    cin >> n;

    if (n <= 10000000)
    {
        b[n] == 1 ? cout << "yes" << endl : cout << "no" << endl;
        return;
    }

    for (int i = 0; i * i <= n; i++)
    {
        if (b[i] && (n % i == 0))
        {
            cout << "no" << endl;
            return;
        }
    }

    cout << "yes" << endl;
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

    // Calling sieve here
    sieve();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}