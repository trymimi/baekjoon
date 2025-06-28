#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int bag[101];
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) bag[i] = i;

	int i, j;
	while (m--) {
		cin >> i >> j;
		swap(bag[i], bag[j]);
	}

	for (int i = 1; i <= n; i++) cout << bag[i] << ' ';
}