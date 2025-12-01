#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isvisit[101];
vector<int> link[101];
int num = 0;

void DFS(int value, int depth) {
	isvisit[value] = true;

	for (int i = 0; i < link[value].size(); i++) {
		if (!isvisit[link[value][i]]) {
			num++;
			DFS(link[value][i], depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, first, second;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> first >> second;
		link[first].push_back(second);
		link[second].push_back(first);
	}

	DFS(1, 0);
	cout << num;
}