#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    // 원하는 운동시간, 초기 맥박, 한계 맥박, 운동 맥박, 휴식 맥박;
    int N, m, M, T, R;
    int time = 0;   // 시간;
    int e_time = 0; // 운동 시간;
    cin >> N >> m >> M >> T >> R;

    if (m + T > M) {    // 운동 불가
        cout << -1;
        return 0;
    }

    int X = m; // 맥박
    while (true) {
        if (e_time >= N) break;   // N 충족시 종료
        if (X + T > M) {
            if (X - R < m) X = m;
            else X -= R;
            time++;
        }
        else {
            X += T;
            e_time++;
            time++;
        }
    }
    cout << time;

}