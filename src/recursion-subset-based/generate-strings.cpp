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

void generate_strings(int *arr, int n, char *out, int j)
{
    // base case
    if (n == 0)
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // recursive case
    int digit;
    // single letter
    digit = arr[0];
    out[j] = 'A' - 1 + digit;
    generate_strings(arr + 1, n - 1, out, j + 1);

    // double letter
    if (n >= 2)
    {
        digit = arr[0] * 10 + arr[1];
        if (digit <= 26)
        {
            out[j] = 'A' - 1 + digit;
            generate_strings(arr + 2, n - 2, out, j + 1);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    char output[100];

    generate_strings(arr, n, output, 0);
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