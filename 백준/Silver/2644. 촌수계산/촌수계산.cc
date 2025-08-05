#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> link[101];
bool visit[101];
int a, b;
bool out;

void DFS(int value, int depth) {
    visit[value] = true;
    if (value == link[b][0]) {
        cout << depth;
        out = true;
    }

    for (int i = 0; i < link[value].size(); i++) {
        if (!visit[link[value][i]]) {
            DFS(link[value][i], depth + 1);
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> a >> b >> m;

    while (m--) {
        int u, v; cin >> u >> v;
        link[v].push_back(u);
        link[u].push_back(v);
    }

    DFS(a, 1);

    if (!out) cout << -1;
}