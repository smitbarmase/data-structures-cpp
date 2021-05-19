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

// n is even

int play_optimal(int i, int j, int *arr, int dp[][100])
{
    // base case
    if (i >= j)
    {
        return 0;
    }
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }
    // recurisive case
    // minimize next chance, becuase opponent played optimally

    // Opponent picks left in second iteration
    int player_left_opponent_left = play_optimal(i + 2, j, arr, dp);
    // Opponent picks right in second iteration
    int player_left_opponent_right = play_optimal(i + 1, j - 1, arr, dp);
    // Player picks left, in first iteration
    int player_left = arr[i] + min(player_left_opponent_left, player_left_opponent_right);

    // Opponent picks left in second iteration
    int player_right_opponent_left = play_optimal(i + 1, j - 1, arr, dp);
    // Opponent picks right in second iteration
    int player_right_opponent_right = play_optimal(i, j - 2, arr, dp);
    // Player picks right, in first iteration
    int player_right = arr[j] + min(player_right_opponent_left, player_right_opponent_right);

    return dp[i][j] = max(player_left, player_right);
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

    int dp[100][100] = {0};

    cout << play_optimal(0, n - 1, arr, dp) << endl;
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