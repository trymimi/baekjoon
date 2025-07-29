#include <iostream>
#include <algorithm>
using namespace std;

int H[100001];
int P[100001];
int S[100001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == 'H') H[i] = 1;
        else if (c == 'P') P[i] = 1;
        else S[i] = 1;
        H[i] += H[i - 1];
        P[i] += P[i - 1];
        S[i] += S[i - 1];
    }

    int win = 0;
    for (int i = 0; i < n; i++) {
        int bH = H[n] - H[i];
        int bP = P[n] - P[i];
        int bS = S[n] - S[i];
        int fWin = max({ H[i], P[i], S[i] });
        int bWin = max({ bH, bP, bS });
        win = max({ win, fWin + bWin });
    }
    cout << win;
}