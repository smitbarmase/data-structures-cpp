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

vector<int> sieve(int *arr, int N)
{
    vector<int> primes;
    // 1 denotes prime, 0 denotes not prime.
    // Consider all are primes from 2.
    for (int i = 3; i <= N; i += 2)
    {
        arr[i] = 1;
    }

    primes.push_back(2);

    for (int i = 3; i <= N; i += 2)
    {
        if (arr[i] == 1)
        {
            primes.push_back(i);
            // Optimization start from prime square.
            for (int j = i * i; j <= N; j += i)
            {
                arr[j] = 0;
            }
        }
    }
    arr[2] = 1;
    arr[0] = arr[1] = 0;

    return primes;
}

void solve(vector<int> &primes)
{
    int n;
    cin >> n;

    int ans = 1;

    for (int i = 0; i < primes.size(); i++)
    {
        if (n % primes[i] == 0)
        {
            int count = 0;
            while (n % primes[i] == 0)
            {
                count++;
                n = n / primes[i];
            }
            ans *= (count + 1);
        }
    }

    if (n != 1)
    {
        ans *= 2;
    }

    cout << ans << endl;
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

    const int N = 100000;
    int arr[N] = {0};

    // Pre-computing primes
    vector<int> primes = sieve(arr, 100000);

    int t;
    cin >> t;
    while (t--)
    {
        solve(primes);
    }
    return 0;
}