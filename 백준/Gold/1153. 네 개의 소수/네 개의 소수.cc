#include <iostream>
using namespace std;

#define MAX 1000001
bool isNotPrime[MAX];
void eratos() {
	isNotPrime[0] = isNotPrime[1] = true;
	for (int i = 2; i * i < MAX; i++) {
		if (!isNotPrime[i]) {
			for (int j = i + i; j < MAX; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
}

void goldbach(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (!isNotPrime[i] && !isNotPrime[n - i]) {
			cout << i << ' ' << n - i;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// 에라토스테네스의 체
	eratos();

	// 8 미만은 불가능
	if (n < 8) {
		cout << -1;
		return 0;
	}

	// 홀수일 때
	if (n % 2 == 1) {
		n -= 5;	// 3 빼면 짝수. 2 빼도 골드바흐 성립
		cout << 2 << ' ' << 3 << ' ';
	}
	// 짝수일 때
	else {
		n -= 4;	// 2를 두번 빼도 골드바흐 성립
		cout << 2 << ' ' << 2 << ' ';
	}

	goldbach(n);
	return 0;
}