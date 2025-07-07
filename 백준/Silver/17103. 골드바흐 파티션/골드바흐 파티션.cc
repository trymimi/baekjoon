#include <iostream>
using namespace std;

#define MAX 1000001

bool isNotPrime[MAX];

void Eratosthenes() {
    isNotPrime[0] = true;
    isNotPrime[1] = true;

    for (int i = 2; i * i < MAX; i++) {
        if (!isNotPrime[i]) {
            for (int j = i * i; j < MAX; j += i) {
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
        int n;
        cin >> n;

        int cnt = 0;
        for (int i = 2; i <= n / 2; i++) {
            if (!isNotPrime[i] && !isNotPrime[n - i]) cnt++;
        }
        cout << cnt << '\n';
    }
}