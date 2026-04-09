#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int cnt = 0;
	int time = 0;
	while (n--) {
		int t; cin >> t;
		if (time + t > 30) {
			if (30 - time >= (t + 1) / 2) cnt++;
			time = 0;
		}
		else {
			time += t;
			cnt++;
		}
		time %= 30;
	}

	cout << cnt;

	return 0;
}