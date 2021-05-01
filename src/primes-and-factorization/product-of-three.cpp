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

//https://codeforces.com/problemset/problem/1294/C

// Input
// 5
// 64
// 32
// 97
// 2
// 12345

// Output
// YES
// 2 4 8
// NO
// NO
// NO
// YES
// 3 5 823

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> factors;

    int k = n;
    for (int i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            int count = 0;
            while (k % i == 0)
            {
                k /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }

    if (k > 1)
    {
        factors.push_back({k, 1});
    }

    // 2^2 * 3^2

    // Case 1: We get more than or equal 3 distinct prime factors
    if (factors.size() >= 3)
    {
        cout << "YES" << endl;
        cout << pow(factors[0].first, factors[0].second) << " ";
        cout << pow(factors[1].first, factors[1].second) << " ";
        int mult = 1;
        for (int i = 2; i < factors.size(); i++)
        {
            mult *= pow(factors[i].first, factors[i].second);
        }
        cout << mult << endl;
        return;
    }

    // Case 2: We get only two distinct prime factor
    if (factors.size() == 2)
    {
        int third = n / (factors[0].first * factors[1].first);

        if (third != factors[0].first && third != factors[1].first && third != 1)
        {
            cout << "YES" << endl;
            cout << factors[0].first << " ";
            cout << factors[1].first << " ";
            cout << third << endl;
            return;
        }
    }

    //  Case: We got only one prime factor
    if (factors[0].second >= 6)
    {
        cout << "YES" << endl;
        cout << factors[0].first << " ";
        cout << factors[0].first * factors[0].first << " ";
        cout << pow(factors[0].first, factors[0].second - 3) << endl;
        return;
    }

    cout << "NO" << endl;
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