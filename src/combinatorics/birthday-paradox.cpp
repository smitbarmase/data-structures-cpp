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

// Minimum number of people in a room so that,
// two people have 50% probability of having same birthday.

// Output: 23

void solve()
{
    float x = 1.0f;
    // x denotes the probability of 2 people having same birthday

    float current = 365;
    float total = 365;

    float people = 0;

    float probability = 0.5f;

    if (probability == 1.0)
    {
        cout << 366 << endl;
        return;
    }

    while (x > 1 - probability)
    {
        x *= current / total;
        current--;
        people++;
    }

    cout << people << endl;
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