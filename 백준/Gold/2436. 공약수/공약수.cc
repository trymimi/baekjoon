#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int g, l;
    cin >> g >> l;

    int m = g + l;
    pair<int, int> result = { g, l };
    for (int i = 2; i * i <= l / g; i++) {
        if (l % i != 0) continue;
        int b = l / i;
        int a = g * i;
        if (gcd(a, b) == g && m > a + b) {
            m = a + b;
            result = { a, b };
        }
    }

    cout << result.first << ' ' << result.second;
}