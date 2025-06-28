#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    
    int k = 1, floor = 0;
    while (true) {  // 층 찾기
        k += floor;
        if (n >= k && n <= k + floor) break;
        floor++;
    }

    int f_num = n - k + 1;
    int b_num = floor + 2 - f_num;

    if (floor % 2 == 0) {
        cout << b_num << '/' << f_num;
    }
    else {
        cout << f_num << '/' << b_num;
    }
}