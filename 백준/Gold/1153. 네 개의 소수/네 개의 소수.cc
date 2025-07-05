#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> sosu(n, 1);
	sosu[1] = 0;
	for (int i = 2; i < n; i++) {
		if (sosu[i]) {
			for (int j = i + i; j < n; j += i) {
				sosu[j] = 0;
			}
		}
	}

	if (n < 8) {
		cout << -1;
		return 0;
	}

	if (n == 8) {
		cout << 2 << ' ' << 2 << ' ' << 2 << ' ' << 2;
		return 0;
	}

	if (n % 2 == 1) {
		n -= 3;
		if (n < 6) {
			cout << -1;
			return 0;
		}
		if (n == 6) {
			cout << 2 << ' ' << 2 << ' ' << 2 << ' ' << 3;
			return 0;
		}
		int tmp;
		for (int i = 2; i <= n && sosu[i]; i++) {
			tmp = n - i;
			for (int j = 2; j * 2 <= tmp; j++) {
				if (sosu[j] && sosu[tmp - j]) {
					cout << 3 << ' ' << i << ' ' << j << ' ' << tmp - j;
					return 0;
				}
			}
		}

	}
	else {
		n -= 4;
		for (int i = 2; i <= n / 2; i++) {
			if (sosu[i] && sosu[n - i]) {
				cout << 2 << ' ' << 2 << ' ' << i << ' ' << n - i;
				return 0;
			}
		}
	}

	cout << -1;
	return 0;
}