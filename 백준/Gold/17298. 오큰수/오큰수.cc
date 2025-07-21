#include <iostream>
#include <stack>
using namespace std;

int r[1000001];
int arr[1000001];
int result[1000001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    int m = 0;
    int size = 0;
    for (int i = n - 1; i >= 0; i--) {
        int a = arr[i];
        r[n - 1 - i] = a;

        if (a >= m) {
            result[size++] = -1;
            m = a;
        }
        else {
            for (int j = n - i - 2; j >= 0; j--) {
                if (r[j] > a) {
                    result[size++] = r[j];
                    break;
                }
                else if (result[size - 1] > a) {
                    result[size++] = result[size - 1];
                    break;
                }
            }
        }
    }

    for (int i = size - 1; i >= 0; i--) cout << result[i] << ' ';
}