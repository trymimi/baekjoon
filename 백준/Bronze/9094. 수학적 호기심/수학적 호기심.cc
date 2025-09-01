#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int sum = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((i * i + j * j + m) % (i * j) == 0) sum++;
			}
		}
		cout << sum << '\n';
	}
}