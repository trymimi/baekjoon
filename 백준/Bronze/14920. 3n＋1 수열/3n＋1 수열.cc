#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, count = 1;
	cin >> n;

	while (n > 1) {
		if (n % 2 == 0) {
			n /= 2;
			count++;
		}
		else {
			n = 3 * n + 1;
			count++;
		}
	}
	cout << count;
}