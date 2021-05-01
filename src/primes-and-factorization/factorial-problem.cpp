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

// Find maximum value of x such that
// n! % k^x = 0

// Input
// 3
// 5 2
// 1000 2
// 5 7

// Output
// 3
// 994
// 0

void solve()
{
    int n, k;
    cin >> n >> k;

    int ans = 1000000;

    // n! / k^x

    // (p1^c1 p2^c3..)(more terms in numerator)/(p1^occ1*x p2^occ2*x p3^occ3*x...)

    // This means
    // c1 >= x * occ1
    // c1 / occ1 >= x

    // Same for all p1, p2,...etc

    // x = min(c1 / occ1, c2 / occ2,...)

    // Find prime factors of k
    for (int i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            // Number of occurance of a prime number
            int occ = 0;
            while (k % i == 0)
            {
                k /= i;
                occ++;
            }

            // Finding number in factorial
            // Using, [n/p] + [n/p^2] + ...so on
            int count = 0;
            int p = i;
            while (n >= p)
            {
                count += n / p;
                p *= i;
            }

            // Now min of count/occurance
            ans = min(ans, count / occ);
        }
    }

    // Corner case if last prime is remaining
    // Occurance will be 1
    // We have to count in n!
    if (k > 1)
    {
        int count = 0;
        int p = k;
        while (n >= p)
        {
            count += n / p;
            p *= k;
        }
        ans = min(ans, count);
    }

    // In case there are no common factor in n! and k
    if (ans == 1000000)
    {
        ans = 0;
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

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}