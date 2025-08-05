#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> link[100001];
int d[100001];

void DFS(int value, int depth) {
    d[value] = depth;

    for (int i = 0; i < link[value].size(); i++) {
        if (!d[link[value][i]]) {
            DFS(link[value][i], depth + 1);
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, r; cin >> n >> m >> r;

    while (m--) {
        int u, v; cin >> u >> v;
        link[u].push_back(v);
        link[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(link[i].begin(), link[i].end());
    }

    DFS(r, 1);

    for (int i = 1; i <= n; i++) {
        cout << d[i] - 1 << '\n';
    }
}