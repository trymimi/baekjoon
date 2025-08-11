#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	while (true) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 0) break;

		if (a > b) swap(a, b);
		if (b > c) swap(b, c);
		if (c * c == a * a + b * b) cout << "right" << '\n';
		else  cout << "wrong" << '\n';
	}
}