#include <iostream>
using namespace std;

bool cake[1001] = { false };

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int l, n;
    cin >> l >> n;  // 길이, 입력 수

    int m = 0, m_real = 0, f_index, r_index;
    for (int i = 1; i <= n; i++) {
        int p, k, cnt = 0;
        cin >> p >> k;
        if (k - p - 1 > m) {    // 많길 기대한 방청객
            m = k - p - 1;
            f_index = i;
        }

        for (int j = p; j <= k; j++) {  // 케이크에 쓰기
            if (!cake[j]) {
                cake[j] = true;
                cnt++;
            }
        }

        if (cnt > m_real) {        // 진짜 많은 방청객
            m_real = cnt;
            r_index = i;
        }
    }

    cout << f_index << '\n' << r_index;

    return 0;
}