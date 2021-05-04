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

void generate_subsets(char *input, char *output, int i, int j)
{
    // Base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }

    // Recursive case
    // include current element
    output[j] = input[i];
    generate_subsets(input, output, i + 1, j + 1);
    // discard current element
    generate_subsets(input, output, i + 1, j);
}

void solve()
{
    char input[] = "abc";
    char output[10];

    //  cin >> input;

    generate_subsets(input, output, 0, 0);
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