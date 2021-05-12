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

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

void solve()
{
    int n, d, f, D, F;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> f;
        v.push_back({d, f});
    }

    cin >> D >> F;

    // sort cities
    sort(v.begin(), v.end(), compare);

    // change to distance from truck
    for (int i = 0; i < n; i++)
    {
        v[i].first = D - v[i].first;
    }

    int count = 0;
    priority_queue<int> p;

    bool failed = false;

    for (int i = 0; i < n; i++)
    {
        int diff = i == 0 ? v[i].first : v[i].first - v[i - 1].first;
        // we can reach to this city with fuel we have
        if (F >= diff)
        {
            // consume the fuel by travelling
            F -= diff;
            // add station fuel to priority queue
            p.push(v[i].second);
        }
        else // we can't reach this city
        {
            // means we need fuel from past stations
            while (!p.empty() && F < diff)
            {
                int fuel = p.top();
                p.pop();
                F += fuel;
                count++;
            }

            if (F < diff)
            {
                // We are not successful to fill the truck for this city
                failed = true;
                break;
            }
            else
            {
                // We are successful, now move on to next city
                F -= diff;
                p.push(v[i].second);
            }
        }
    }

    if (failed)
    {
        cout << -1 << endl;
        return;
    }

    int diff = D - v[n - 1].first;

    // We are at the last city
    if (F >= diff)
    {
        // we have fuel to reach goal
        cout << count << endl;
    }
    else
    {
        // we need fuel from past
        while (!p.empty() && F < diff)
        {
            int fuel = p.top();
            p.pop();
            F += fuel;
            count++;
        }
        if (F < diff)
        {
            // We are not successful to fill the truck for goal
            cout << -1 << endl;
        }
        else
        {
            // We are successful
            cout << count << endl;
        }
    }
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