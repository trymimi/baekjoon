#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int a, b, c;
	cin >> a >> b >> c;

	cout << a + b - c << '\n';
	if (b / 1000) b += a * 10000;
	else if (b / 100) b += a * 1000;
	else if (b / 10) b += a * 100;
	else b += a * 10;
	cout << b - c;
}