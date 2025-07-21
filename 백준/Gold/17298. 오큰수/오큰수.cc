#include <iostream>
using namespace std;

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
    for (int i = n - 1; i >= 0; i--) {
        // 최대값보다도 클 때
        if (arr[i] >= m) {
            result[i] = -1;
            m = arr[i];
        }
        else {
            for (int j = i + 1; j < n; j++) {
                // 가까운 수가 클 때
                if (arr[j] > arr[i]) {
                    result[i] = arr[j];
                    break;
                }
                // 가까운 수의 오큰수가 클 때
                else if (result[j] > arr[i]) {
                    result[i] = result[j];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) cout << result[i] << ' ';
}