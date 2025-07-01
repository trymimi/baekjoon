#include <iostream>
using namespace std;

int arr[50];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    if (n == 1) {
        cout << "A";
        return 0;
    }
    if (n == 2) {
        if (arr[0] == arr[1]) cout << arr[0];
        else cout << "A";
        return 0;
    }

    for (int a = -200; a <= 200; a++) {
        int b = arr[1] - arr[0] * a;

        bool pass = true;
        for (int i = 2; i < n; i++) {
            if (arr[i] != arr[i - 1] * a + b) {
                pass = false;
                break;
            }
        }
        if (pass) {
            cout << arr[n - 1] * a + b;
            return 0;
        }
    }

    cout << "B";
    return 0;
}