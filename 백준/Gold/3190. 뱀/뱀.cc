#include <iostream>
#include <queue>
using namespace std;

bool apple[101][101];
bool snake[101][101];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    while (k--) {
        int r, c;
        cin >> r >> c;
        apple[r][c] = true;
    }

    int L;
    cin >> L;
    queue<pair<int, char>> ways;
    while (L--) {
        int x;
        char c;
        cin >> x >> c;
        ways.push({ x, c });
    }

    int t = 1;
    int way = 0;
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    snake[1][1] = true;
    while (true) {
        int r = q.back().first;
        int c = q.back().second;
        // 우, 하, 좌, 상
        if (way == 0) c++;
        else if (way == 1) r++;
        else if (way == 2) c--;
        else if (way == 3) r--;

        if (r < 1 || r > n || c < 1 || c > n || snake[r][c]) break;

        if (!apple[r][c]) {
            pair<int, int> t = q.front();
            snake[t.first][t.second] = false;
            q.pop();
        }
        else apple[r][c] = false;

        snake[r][c] = true;
        q.push({ r, c });

        t++;
        if (!ways.empty() && t > ways.front().first) {
            char c = ways.front().second;
            if (c == 'D') way++;
            else way--;
            ways.pop();
            way = (way + 4) % 4;
        }
    }
    cout << t;
}