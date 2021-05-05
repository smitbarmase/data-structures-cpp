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

// All possible strings can made with number

// Input:
// 1
// 2
// 2 3

// Output:
// AD
// AE
// AF
// BD
// BE
// BF
// CD
// CE
// CF

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void map_number(int *arr, int n, char *output, int j)
{
    // base case
    if (n == 0)
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }

    // recursive case
    int current = arr[0];
    for (int k = 0; keypad[current][k] != '\0'; k++)
    {
        output[j] = keypad[current][k];
        map_number(arr + 1, n - 1, output, j + 1);
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

    map_number(arr, n, output, 0);
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