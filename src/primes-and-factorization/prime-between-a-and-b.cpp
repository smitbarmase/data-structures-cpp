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

// Numbers of prime between a and b.

void prime_sieve(int *arr)
{
    // 1 denotes prime, 0 denotes not prime.
    // Consider all are primes from 2.
    for (int i = 3; i <= 1000000; i += 2)
    {
        arr[i] = 1;
    }

    for (int i = 3; i <= 1000000; i += 2)
    {
        if (arr[i] == 1)
        {
            // Optimization start from prime square.
            for (int j = i * i; j <= 1000000; j += i)
            {
                arr[j] = 0;
            }
        }
    }
    arr[2] = 1;
    arr[0] = arr[1] = 0;
}

// Input
// 2
// 1 10
// 11 20

// Output
// 4
// 4

int arr[1000005] = {0};
int sum[1000005] = {0};

void solve()
{
    prime_sieve(arr);

    for (int i = 1; i <= 1000000; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << endl;
    }
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