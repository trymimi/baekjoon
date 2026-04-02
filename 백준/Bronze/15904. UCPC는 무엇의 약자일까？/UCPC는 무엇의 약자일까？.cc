#include <iostream>
#include <string>
using namespace std;

char ucpc[4] = { 'U', 'C', 'P', 'C' };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	string s; 
	getline(cin, s);

	int  i = 0;
	for (char c : s) {
		if (c == ucpc[i]) i++;
		if (i == 4) break;
	}

	if (i == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";

	return 0;
}