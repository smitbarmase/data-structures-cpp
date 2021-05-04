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

// Number to words

// Input:
// 2048

// Output:
// two zero four eight

string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string number_to_words(int n)
{
    // Base case
    if (n == 0)
    {
        return "";
    }

    // Recursive case
    string remaining = number_to_words(n / 10);
    return remaining + words[n % 10] + " ";
}

void solve()
{
    int n;
    cin >> n;
    cout << number_to_words(n) << endl;
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