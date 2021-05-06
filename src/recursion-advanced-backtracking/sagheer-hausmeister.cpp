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

// https://codeforces.com/problemset/problem/812/B

// Input:
// 3
// 2 2
// 0010
// 0100
// 3 4
// 001000
// 000010
// 000010
// 4 3
// 01110
// 01110
// 01110
// 01110

// Output:
// 5
// 12
// 18

int find_path(int *ld, int *rd, int &m, int i, bool left)
{
    // Base case
    if (i == 0)
    {
        if (left)
        {
            return ld[i];
        }
        return rd[i];
    }

    // Recursive case
    // If going up from left
    if (left)
    {
        int left_to_left = (2 * ld[i]) + find_path(ld, rd, m, i - 1, true); // 8 + 2 = 10
        int left_to_right = m + 1 + find_path(ld, rd, m, i - 1, false);     // 5 + 3 = 8
        return 1 + min(left_to_left, left_to_right);                        // 1 + min(8, 10) = 9
    }
    // If going up from right
    int right_to_left = m + 1 + find_path(ld, rd, m, i - 1, true);         // 5 + 2 = 7
    int right_to_right = (2 * rd[i]) + find_path(ld, rd, m, i - 1, false); // 2 + 3 = 5
    return 1 + min(right_to_left, right_to_right);                         // 1 + min(7, 5) = 6
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string matrix[101];
    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i];
    }

    int ld[n], rd[n];

    // Generating prefix distance of last room in each row
    for (int i = 0; i < n; i++)
    {
        int first_digit_from_right = 0;
        int last_digit_from_left = 0;

        int num = (int)bitset<16>(matrix[i]).to_ulong();
        while (num > 0)
        {
            first_digit_from_right++;
            num = num >> 1;
        }
        num = (int)bitset<16>(matrix[i]).to_ulong();
        while (!(num & 1))
        {
            last_digit_from_left++;
            num = num >> 1;
        }
        rd[i] = first_digit_from_right - 1;
        ld[i] = m + 1 - last_digit_from_left;
    }

    // Dry run for:
    // 3 4
    // 001000
    // 000010
    // 000010
    // Should return 12

    // Ground floor
    int left_to_left = (2 * ld[n - 1]) + find_path(ld, rd, m, n - 2, true); // 8 + 9 = 17
    int left_to_right = m + 1 + find_path(ld, rd, m, n - 2, false);         // 5 + 6 = 11

    cout << 1 + min(left_to_left, left_to_right) << endl; // 1 + min(17, 11) = 12
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