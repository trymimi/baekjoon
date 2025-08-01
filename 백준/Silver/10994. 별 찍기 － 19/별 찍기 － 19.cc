#include <iostream>
using namespace std;

bool arr[401][401];

void star(int n) {
    int st = 200 - 2 * (n - 1);
    int en = 200 + 2 * (n - 1);

    for (int i = st; i <= en; i++) {
        arr[en][i] = true;
        arr[st][i] = true;
        arr[i][en] = true;
        arr[i][st] = true;
    }

    if (n > 1) star(--n);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;

    star(n);
    
    int st = 200 - 2 * (n - 1);
    int en = 200 + 2 * (n - 1);

    for (int i = st; i <= en; i++) {
        for (int j = st; j <= en; j++) {
            if (!arr[i][j]) cout << ' ';
            else cout << "*";
        }
        if (i != en) cout << '\n';
    }
}