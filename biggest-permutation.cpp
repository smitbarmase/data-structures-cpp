#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    vector<string> arr = {"98", "9", "82", "969", "8"};
    sort(arr.begin(), arr.end(), cmp);
    string result;
    for (string str : arr)
    {
        result += str;
    }
    cout << result << endl;
    return 0;
}