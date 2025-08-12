#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;

	int arr[6];
	for (int i = 0; i < 6; i++)
		cin >> arr[i];

	int t, p; cin >> t >> p;

	int tans = 0;
	for (int i = 0; i < 6; i++)
		tans += (arr[i] + t - 1) / t;

	cout << tans << '\n';
	cout << n / p << ' ' << n - n / p * p;
}