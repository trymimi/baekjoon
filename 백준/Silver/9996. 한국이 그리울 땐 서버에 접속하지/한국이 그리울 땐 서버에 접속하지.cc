#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	
	string pattern; cin >> pattern;

	while (n--) {
		string s; cin >> s;
		deque <char> word;
		for (char c : s) word.push_back(c);

		bool isDA = true;
		int i = 0;
		while (isDA && pattern[i] != '*') {
			if (word.empty() || word.front() != pattern[i]) {
				isDA = false;
				break;
			}

			word.pop_front();
			i++;
		}

		i = pattern.length() - 1;
		while (isDA && pattern[i] != '*') {
			if (word.empty() || word.back() != pattern[i]) {
				isDA = false;
				break;
			}

			word.pop_back();
			i--;
		}

		if (isDA) cout << "DA" << '\n';
		else cout << "NE" << '\n';
	}

	return 0;
}