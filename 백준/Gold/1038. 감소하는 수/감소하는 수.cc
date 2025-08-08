#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> num;

void decre(int l, long long val) {
	num.push_back(val);
	// 원래 값에 10을 곱하고 1의 자리에 숫자 추가
	for (int i = 0; i < l; i++) {
		decre(i, val * 10 + i);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n; cin >> n;
	// 예외 처리
	if (n > 1022) {
		cout << -1;
		return 0;
	}
	// 1023개의 감소 수 넣기
	num.push_back(0);
	for (int i = 1; i <= 9; i++) {
		decre(i, i);
	}
	// 정렬 및 출력
	sort(num.begin(), num.end());
	cout << num[n];
}