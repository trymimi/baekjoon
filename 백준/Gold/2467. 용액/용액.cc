#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    int arr[100001];
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int i = 1, j = n;
    int min = abs(arr[i] + arr[j]);
    pair<int, int> result = { arr[i], arr[j] };
    while (j > i) {
        int temp = arr[i] + arr[j];
        if (min > abs(temp)) {
            result = { arr[i], arr[j] };
            min = abs(temp);
        }
        if (temp < 0) i++;
        else j--;
    }

    cout << result.first << ' ' << result.second;
}