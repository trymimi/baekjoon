#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	string s; cin >> s;

	int alpha[26];
	for (int i = 0; i < 26; i++) alpha[i] = -1;

	int idx = 0;
	for (char c : s) {
		int a = c - 'a';
		if (alpha[a] == -1) alpha[a] = idx;
		idx++;
	}

	for (int i : alpha) cout << i << ' ';
}