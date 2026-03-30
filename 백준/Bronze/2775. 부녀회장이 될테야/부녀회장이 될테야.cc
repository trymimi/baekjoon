#include <iostream>
using namespace std;

int arr[15];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;

	while (t--) {
		int k, n;
		cin >> k >> n;

		for (int i = 0; i <= 14; i++) arr[i] = i + 1;

		for (int i = 0; i < k; i++) {
			for (int j = 1; j < n; j++) {
				arr[j] += arr[j - 1];
			}
		}

		cout << arr[n-1] << '\n';
	}

	return 0;
}