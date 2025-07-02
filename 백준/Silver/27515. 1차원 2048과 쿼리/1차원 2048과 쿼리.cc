#include <iostream>
#include <cmath>
using namespace std;

int num[64];
int temp[64];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        char op;
        long long x;
        cin >> op >> x;
        if (x != 0) {
            int a = log2(x);
            if (op == '-') num[a]--;
            else num[a]++;
        }

        for (int i = 0; i < 63; i++) temp[i] = num[i];
        for (int i = 0; i < 63; i++) {
            int p = temp[i] / 2;
            temp[i + 1] += p;
            temp[i] %= 2;
        }

        int maxK = -1;
        for (int i = 63; i >= 0; i--) {
            if (temp[i]) {
                maxK = i;
                break;
            }
        }
        if (maxK == -1) cout << 0 << '\n';
        else cout << (1LL << maxK) << '\n';
    }
}