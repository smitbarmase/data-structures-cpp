#include <iostream>
using namespace std;

int binary_to_int(int n)
{
    int sum = 0;
    for (int i = 1; n != 0; i *= 2)
    {
        if (n % 10)
            sum += i;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << "Defined function: " << binary_to_int(n) << endl;
    cout << "In-built function: " << stoi(to_string(n), 0, 2) << endl;
    return 0;
}