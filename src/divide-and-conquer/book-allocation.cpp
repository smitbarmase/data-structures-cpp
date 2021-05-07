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

// Book allocation problem

// Given n diffrent books and m students
// Books are arraged in ascending order of pages
// Every student is assigned to read some consecutive books
// Assign books in such a way, maximum number of pages assigned to student is minimum

// Input:
// 1
// 4 2
// 12 34 67 90

// Output:
// 113

bool is_possible_to_allocate(int *arr, int n, int s, int current_min)
{
    int student_required = 1;
    int pages_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > current_min)
        {
            return false;
        }
        if (pages_count + arr[i] > current_min)
        {
            student_required++;
            pages_count = arr[i];
            if (student_required > s)
            {
                return false;
            }
        }
        else
        {
            pages_count += arr[i];
        }
    }
    return true;
}

int find_maximum_pages(int *arr, int n, int s)
{
    // No of books less than students
    if (n < s)
    {
        return -1;
    }

    // Total number of pages
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // Start pages and end pages
    int l = 0;
    int r = sum;

    int ans = LONG_LONG_MAX;
    while (l <= r)
    {
        int m = l + ((r - l) / 2);
        bool possible = is_possible_to_allocate(arr, n, s, m);
        if (possible)
        {
            ans = min(ans, m);
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    int n, s;
    cin >> n >> s;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << find_maximum_pages(arr, n, s) << endl;
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