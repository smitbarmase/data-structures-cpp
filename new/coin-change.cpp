#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a <= b;
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(coins) / sizeof(int);

    int coin;
    cin >> coin;

    while (coin)
    {
        auto it = upper_bound(coins, coins + n, coin);
        int result = coins[it - coins - 1];
        cout << result << " ";
        coin -= result;
    }

    cout << endl;

    return 0;
}