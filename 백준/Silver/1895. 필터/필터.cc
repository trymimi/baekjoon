#include <iostream>
#include <algorithm>
using namespace std;

int arr[40][40];
int temp[9];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int r, c, t;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> t;

	int result = 0;
	for (int i = 0; i < r - 2; i++) {
		for (int j = 0; j < c - 2; j++) {
			for (int a = i; a < i + 3; a++) {
				for (int b = j; b < j + 3; b++) {
					temp[(a - i) * 3 + b - j] = arr[a][b];
				}
			}
			sort(temp, temp + 9);
			if (temp[4] >= t) result++;
		}
	}

	cout << result;
}