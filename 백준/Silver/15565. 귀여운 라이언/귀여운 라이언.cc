#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k; cin >> n >> k;

    bool doll[1000001] = { 0 };
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (t == 1) doll[i] = true;
    }

    int result = n + 1;
    int i = 1, j = 0;
    int cnt = 0;
    while (j < n || cnt >= k) {
        if (cnt < k) {
            j++;
            cnt += doll[j];
        }
        else if (cnt > k) {
            cnt -= doll[i];
            i++;
        }
        else {
            result = min(result, j - i + 1);
            cnt -= doll[i];
            i++;
        }
    }

    if (result == n + 1) cout << -1;
    else cout << result;
}