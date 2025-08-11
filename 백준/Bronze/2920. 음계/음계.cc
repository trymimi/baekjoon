#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	bool as = true, de = true;
	int prev; cin >> prev;
	for (int i = 0; i < 7; i++) {
		int now; cin >> now;
		if (now > prev) de = false;
		if (now < prev) as = false;
		prev = now;
	}

	if (de) cout << "descending";
	else if (as) cout << "ascending";
	else cout << "mixed";
}