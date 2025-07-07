#include <iostream>
using namespace std;

bool isNotPrime[1001];

void Eratosthenes() {
    isNotPrime[0] = true;
    isNotPrime[1] = true;

    for (int i = 2; i * i < 1001; i++) {
        if (!isNotPrime[i]) {
            for (int j = i * i; j < 1001; j += i) {
                isNotPrime[j] = true;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    Eratosthenes();
    while (t--) {
        int k;
        cin >> k;

        if (k == 7) cout << 2 << ' ' << 2 << ' ' << 3;
        else {
            k -= 3;
            for (int i = 2; i < k; i++) {
                if (!isNotPrime[i] && !isNotPrime[k - i]) {
                    cout << min(3, i) << ' ' << max(3, i) << ' ' << k - i;
                    break;
                }
            }
        }
        cout << '\n';
    }
}