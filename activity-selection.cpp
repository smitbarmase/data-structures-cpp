#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n;
        pair<int, int> arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            arr[i] = make_pair(a, b);
        }
        sort(arr, arr + n, cmp);

        int chosen = 0;
        cout << "Selected activies: " << endl;
        cout << arr[0].first << " " << arr[0].second << endl;
        for (int i = 1; i < n; i++)
        {
            if (arr[i].first >= arr[chosen].second)
            {
                cout << arr[i].first << " " << arr[i].second << endl;
                chosen = i;
            }
        }
    }
    return 0;
}
