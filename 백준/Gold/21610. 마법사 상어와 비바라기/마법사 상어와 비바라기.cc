#include <iostream>
#include <vector>
using namespace std;

int arr[51][51];
bool visit[51][51];
int n, m;

pair<int, int> move(int d, int r, int c, int s) {
    s %= n;

    // ←, ↖, ↑, ↗, →, ↘, ↓, ↙
    if (d == 1) c = (c + n - s - 1) % n + 1;
    else if (d == 2) { 
        c = (c + n - s - 1) % n + 1;
        r = (r + n - s - 1) % n + 1;
    }
    else if (d == 3) r = (r + n - s - 1) % n + 1;
    else if (d == 4) {
        c = (c + s - 1) % n + 1;
        r = (r + n - s - 1) % n + 1;
    }
    else if (d == 5) c = (c + s - 1) % n + 1;
    else if (d == 6) { 
        c = (c + s - 1) % n + 1;
        r = (r + s - 1) % n + 1;
    }
    else if (d == 7) r = (r + s - 1) % n + 1;
    else if (d == 8) { 
        c = (c + n - s - 1) % n + 1;
        r = (r + s - 1) % n + 1;
    }

    return { r, c };
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> arr[i][j];
    }

    vector<pair<int, int>> cloud = { {n, 1}, {n, 2}, {n - 1, 1},{n - 1, 2} };

    while (m--) {
        int d, s;
        cin >> d >> s;

        // 구름 이동, 비 내림
        for (int i = 0; i < cloud.size(); i++) {
            int r = cloud[i].first;
            int c = cloud[i].second;
            cloud[i] = move(d, r, c, s);
            r = cloud[i].first;
            c = cloud[i].second;
            arr[r][c]++;
            visit[r][c] = true;
        }

        // 물 복사 버그
        for (auto& p : cloud) {
            int r = p.first;
            int c = p.second;
            if (r > 1 && c > 1 && arr[r - 1][c - 1]) arr[r][c]++;
            if (r > 1 && c < n && arr[r - 1][c + 1]) arr[r][c]++;
            if (r < n && c > 1 && arr[r + 1][c - 1]) arr[r][c]++;
            if (r < n && c < n && arr[r + 1][c + 1]) arr[r][c]++;
        }

        // 구름 생성
        cloud.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!visit[i][j] && arr[i][j] >= 2) {
                    cloud.push_back({ i, j });
                    arr[i][j] -= 2;
                }
                visit[i][j] = false;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt += arr[i][j];
        }
    }
    cout << cnt;
}