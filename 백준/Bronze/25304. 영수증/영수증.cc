#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, n, a, b, sum = 0;
	cin >> x >> n;
	while (n--) {
		cin >> a >> b;
		sum += a * b;
	}
	if (sum == x) cout << "Yes";
	else cout << "No";
}