#include <iostream>
#include <set>
#include <queue>
using namespace std;

int n, m;
int arr[301][301];
set<pair<int, int>> ice;

void bfs() {
	int year = 0;
	while (true) {
		// 빙산 녹음
		for (const auto& p : ice) {
			int f = p.first;
			int s = p.second;
			if (f > 0 && ice.find({ f - 1, s }) == ice.end()) {
				arr[f][s]--;
			}
			if (f < n - 1 && ice.find({ f + 1,s }) == ice.end()) {
				arr[f][s]--;
			}
			if (s > 0 && ice.find({ f, s - 1 }) == ice.end()) {
				arr[f][s]--;
			}
			if (s < m - 1 && ice.find({ f, s + 1 }) == ice.end()) {
				arr[f][s]--;
			}
			if (arr[f][s] < 0) arr[f][s] = 0;
		}

		year++;

		// ice 새로고침
		set<pair<int, int>> nextIce;
		for (auto& p : ice) {
			int f = p.first;
			int s = p.second;
			if (arr[f][s] > 0) nextIce.insert({ f, s });
		}
		ice = nextIce;

		// 다 녹았을 때
		if (ice.empty()) {
			cout << 0;
			break;
		}

		// 조각 검사
		set<pair<int, int>> c = ice;
		pair<int, int> st = *ice.begin();

		queue<pair<int, int>> q;
		q.push(st);
		c.erase(st);

		while (!q.empty()) {
			int f = q.front().first, s = q.front().second;
			q.pop();

			if (f > 0 && arr[f - 1][s] > 0 && c.erase({ f - 1, s })) q.push({ f - 1, s });
			if (f < n - 1 && arr[f + 1][s] > 0 && c.erase({ f + 1, s })) q.push({ f + 1, s });
			if (s > 0 && arr[f][s - 1] > 0 && c.erase({ f, s - 1 })) q.push({ f, s - 1 });
			if (s < m - 1 && arr[f][s + 1] > 0 && c.erase({ f, s + 1 })) q.push({ f, s + 1 });
		}

		if (!c.empty()) {
			cout << year;
			break;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) ice.insert({ i, j });
		}
	}

	bfs();
}