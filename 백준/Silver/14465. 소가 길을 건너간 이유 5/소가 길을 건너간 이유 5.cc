#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k, b; cin >> n >> k >> b;

    bool blink[100001] = { 0 };

    while (b--) {
        int temp; cin >> temp;
        blink[temp] = true;
    }

    int cnt = 0;
    for (int i = 1; i <= k; i++) if (blink[i]) cnt++;

    int result = cnt;
    for (int i = 1; i + k <= n; i++) {
        if (blink[i]) cnt--;
        if (blink[i + k]) cnt++;

        result = min(result, cnt);
    }

    cout << result;
}