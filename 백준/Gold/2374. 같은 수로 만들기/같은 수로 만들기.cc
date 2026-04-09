#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
stack<int> t;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	while (n--) {
		int k; cin >> k;
		if (!s.empty() && s.top() == k) continue;
		s.push(k);
	}

	long long cnt = 0;

	while (!s.empty()) {
		int temp = s.top();
		s.pop();
		if (!s.empty() && s.top() > temp) {
			cnt += s.top() - temp;
			while (!t.empty() && t.top() <= s.top()) t.pop();
		}
		else t.push(temp);
	}

	while (!t.empty()) {
		int temp = t.top();
		t.pop();
		if (!t.empty() && t.top() > temp) {
			cnt += t.top() - temp;
		}
	}

	cout << cnt;

	return 0;
}