#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t; cin >> t;

	while (t--) {
		int h, w, n; cin >> h >> w >> n;
		cout << ((n + h - 1) / h) + ((n - 1) % h + 1) * 100 << '\n';
	}
}