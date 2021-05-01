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

// Input
// 2
// 1 10
// 3 5

// Output
// 2
// 3
// 5
// 7

// 3
// 5

const int N = 100000; // Size for sieve

int arr[N] = {0};
vector<int> primes;

void sieve()
{
    for (int i = 3; i < N; i += 2)
    {
        arr[i] = 1;
    }

    // Corner case add 2 in primes
    primes.push_back(2);

    // This will check all odd numbers for prime with optimization
    for (int i = 3; i < N; i += 2)
    {
        if (arr[i] == 1)
        {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
            {
                arr[j] = 0;
            }
        }
    }
}

void solve()
{
    int m, n;
    cin >> m >> n;

    bool seg_arr[n - m + 1];

    for (int i = 0; i <= n - m; i++)
    {
        seg_arr[i] = 0;
    }

    //        m                                   n
    // num:  99 100 101 102 103 104 105 106 107 108
    // i:     0   1   2   3   4   5   6   7   8   9

    for (auto x : primes)
    {
        if (x * x > n) {
            break;
        }

        int start = (m / x) * x;

        // primes not lies in segment sieve range
        if (x >= m and x <= n)
        {
            start = x * 2;
        }

        // mark all not primes
        for (int i = start; i <= n; i += x)
        {
            seg_arr[i - m] = 1;
        }
    }

    for (int i = m; i <= n; i++)
    {
        // print all primes and do not print 1, it's a corner case
        if (seg_arr[i - m] == 0 and i != 1)
        {
            cout << i << endl;
        }
    }
    cout << endl;
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

    // Creating sieve for all test cases

    sieve();

    while (t--)
    {
        solve();
    }
    return 0;
}