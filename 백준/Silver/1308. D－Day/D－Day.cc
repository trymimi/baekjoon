#include <iostream>
using namespace std;

int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool isYoon(int n) {
    return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int y, m, d;
    cin >> y >> m >> d;
    int endY, endM, endD;
    cin >> endY >> endM >> endD;

    // gg 처리
    if (endY - y > 1000 ||
        (endY - y == 1000 && (endM > m || (endM == m && endD >= d)))) {
        cout << "gg";
        return 0;
    }

    int day = 0;
    // 같은 달일때
    if (m == endM && endD > d) {
        day += endD - d;
    }

    else {
        if (m == 2 && isYoon(y))
            day += 29 - d;
        else
            day += month[m] - d;
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }

        int i = m;
        while (i != endM) {
            if (i == 2 && isYoon(y))
                day += 29;
            else
                day += month[i];
            i++;
            if (i > 12) {
                i = 1;
                y++;
            }
        }
        day += endD;
    }

    while (endY > y) {
        if (endM > 2 && isYoon(y + 1)) day += 366;
        else if (endM <= 2 && isYoon(y)) day += 366;
        else day += 365;
        y++;
    }

    cout << "D-" << day;
}