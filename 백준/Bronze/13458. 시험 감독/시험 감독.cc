#include <iostream>
using namespace std;

int a[1000001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	int b, c; cin >> b >> c;

	long long result = 0;
	for (int i = 0; i < n; i++) {
		long long sum = 0, temp = a[i];
		sum += 1;
		temp -= b;
		if (temp < 0) temp = 0;
		sum += (temp - 1 + c) / c;

		result += sum;
	}

	cout << result;
}