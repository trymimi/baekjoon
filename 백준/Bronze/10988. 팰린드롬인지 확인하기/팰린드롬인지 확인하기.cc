#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int len = s.length();
	for (int i = 0; i < len /  2; i++) {
		if (s[i] != s[len - 1 - i]) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}