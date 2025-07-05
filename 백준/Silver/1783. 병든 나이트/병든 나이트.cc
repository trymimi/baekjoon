#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, result;
    cin >> n >> m;

    if (n == 1) result = 1;
    else if (n == 2) {
        result = min((m + 1) / 2, 4);
    }
    else {
        if (m <= 5) result = min(m, 4);
        else result = m - 2;
    }
    cout << result;
}