#include <iostream>
using namespace std;

#define MAX 53
long long comb[MAX][MAX];

void pascal() {
	for (int i = 0; i < MAX; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	pascal();

	long long result = 0;
	int sing = 1;
	for (int i = 1; i <= n/4; i++) {
		result += sing * comb[13][i] * comb[52 - 4 * i][n - 4 * i];
		sing *= -1;
	}
	result %= 10007;
	cout << result;
}