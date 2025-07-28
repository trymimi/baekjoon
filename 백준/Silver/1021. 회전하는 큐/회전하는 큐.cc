#include <iostream>
#include <deque>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    deque<int> front;
    deque<int> back;
    for (int i = 1; i <= n; i++) {
        front.push_back(i);
        back.push_back(i);
    }

    int result = 0;
    while (m--) {
        int a; cin >> a;

        int cnt = 0;
        while (true) {
            if (front.front() == a) {
                front.pop_front();
                back = front;
                break;
            }
            else if (back.front() == a) {
                back.pop_front();
                front = back;
                break;
            }

            front.push_back(front.front());
            front.pop_front();
            back.push_front(back.back());
            back.pop_back();
            cnt++;
        }

        result += cnt;
    }

    cout << result;
}