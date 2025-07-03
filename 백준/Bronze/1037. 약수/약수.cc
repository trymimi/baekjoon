#include <iostream>
#include <algorithm>
using namespace std;

int num[51];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    cout << num[0] * num[n - 1];
}