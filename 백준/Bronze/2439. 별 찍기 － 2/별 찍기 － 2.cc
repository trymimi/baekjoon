#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n - i) cout << ' ';
            else cout << "*";
        }
        cout << '\n';
    }
}