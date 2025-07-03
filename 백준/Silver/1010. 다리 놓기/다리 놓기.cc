#include <iostream>
using namespace std;

int brige(int n, int m) {
    long long result = 1;
    int r = min(n, m - n);
    for (int i = 0; i < r; i++) {
        result *= (m - i);
        result /= (i + 1);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n == m || n  == 0) {
            cout << 1 << '\n';
        }
        else {
            cout << brige(n, m) << '\n';
        }
    }
}