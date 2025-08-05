#include <iostream>
#include <queue>
using namespace std;

const int MAX = 10001;
int graph[MAX];
bool visited[MAX];
int n, a, b;

int bfs(int start) {
	queue<int> q;
	q.push(start);

	visited[start] = true;

	int cnt = -1;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();

		for (int i = 0; i < sz; i++)
		{
			int cur = q.front();
			q.pop();

			if (cur == b) {
				return cnt;
			}

			for (int i = graph[cur]; i < n; i += graph[cur]) {
				int back = cur - i, f = cur + i;
				if (back > 0) {
					if (!visited[back]) {
						visited[back] = true;
						q.push(back);
					}
				}
				if (f <= n) {
					if (!visited[f]) {
						visited[f] = true;
						q.push(f);
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> graph[i];
	}

	cin >> a >> b;

	int t = bfs(a);

	cout << t;
}