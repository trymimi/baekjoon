#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> word;

void stackout() {
	while (!word.empty()) {
		cout << word.top();
		word.pop();
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	int len = s.length();

	for (int i = 0; i < len; i++) {
		if (s[i] == '<') {
			stackout();
			while (s[i] != '>') {
				cout << s[i];
				i++;
			}
			cout << s[i];
			continue;
		}

		if (s[i] == ' ') {
			stackout();
			cout << ' ';
			i++;
		}

		word.push(s[i]);
	}

	stackout();

	return 0;
}