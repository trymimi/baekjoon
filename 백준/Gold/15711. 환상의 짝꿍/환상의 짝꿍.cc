#include <iostream>
#include <vector>
using namespace std;

#define MAX 2000001
bool isNotPrime[MAX];
vector<int> Prime;

void eratos() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i < MAX; i++) {   // 1LL 붙이면 longlong타입으로 오버플로우안남
        if (!isNotPrime[i]) {
            Prime.push_back(i);
            for (long long j = 1LL * i * i; j < MAX; j += i) {
                isNotPrime[j] = true;
            }
        }
    }
}

bool prime(long long n) {
    if (n < MAX) return !isNotPrime[n];
    for (int i = 0; i < Prime.size() && 1LL * Prime[i] * Prime[i] <= n; i++) {
        if (n % Prime[i] == 0) return false;
    }
    return true;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    eratos();
    while (t--) {
        long long a, b, c;
        cin >> a >> b;
        c = a + b;

        string s = "NO";
        if ((c > 2 && c % 2 == 0) || prime(c - 2)) s = "YES";
        cout << s << '\n';
    }
}