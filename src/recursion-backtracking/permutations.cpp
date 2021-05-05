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

void permutations(char *str, int i)
{
    // Base case
    if (str[i] == '\0')
    {
        cout << str << endl;
        return;
    }

    // Recursive case
    for (int j = i; str[j] != '\0'; j++)
    {
        swap(str[i], str[j]);
        permutations(str, i + 1);
        // Reswap to mantain order of printing (Optional)
        swap(str[j], str[i]);
    }
}

void solve()
{
    char str[10];
    cin >> str;
    permutations(str, 0);
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