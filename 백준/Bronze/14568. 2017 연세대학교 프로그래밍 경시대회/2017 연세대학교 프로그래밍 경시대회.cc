#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, count = 0;
    cin >> n;

    while (true) {
        n -= 2;
        if (n <= 3) break;

        for (int B = 1; n >= 2 * B + 2; B++) count++;
    }

    cout << count;

    return 0;
}