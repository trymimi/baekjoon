#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int x; cin >> x;

    int cnt = 0;
    int i = 0, j = n - 1;
    while (j > i) {
        int sum = v[i] + v[j];
        if (sum == x) {
            i++;
            j--;
            cnt++;
        }
        else if (sum > x) j--;
        else i++;
    }

    cout << cnt;
}