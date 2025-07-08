#include <iostream>
using namespace std;

int mixture[15][15];
void MakeMixture() {
	for (int i = 0; i < 15; i++) mixture[0][i] = mixture[i][0] = 1;
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			mixture[i][j] = mixture[i - 1][j] + mixture[i][j - 1];
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, k;
	cin >> n >> m >> k;

	MakeMixture();

	if (!k) cout << mixture[n - 1][m - 1];
	else {
		int r = (k - 1)/ m + 1;
		int c = (k - 1) % m + 1;
		int sum = mixture[r - 1][c - 1];
		sum *= mixture[n - r][m - c];
		cout << sum;
	}
}